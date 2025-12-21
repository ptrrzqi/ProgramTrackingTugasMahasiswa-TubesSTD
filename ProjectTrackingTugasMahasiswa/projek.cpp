#include "projek.h"
#include <iostream>
using namespace std;

void salinString(char tujuan[], const char asal[]) {
    int i = 0;
    while (asal[i] != '\0') {
        tujuan[i] = asal[i];
        i++;
    }
    tujuan[i] = '\0';
}

/* ================= BST PEKAN ================= */

Pekan* buatPekan(int minggu) {
    Pekan *p = new Pekan;
    p->mingguKe = minggu;
    p->daftarMatkul = NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Pekan* insertPekan(Pekan *root, int minggu) {
    if (root == NULL) {
        return buatPekan(minggu);
    }

    if (minggu < root->mingguKe) {
        root->left = insertPekan(root->left, minggu);
    } else if (minggu > root->mingguKe) {
        root->right = insertPekan(root->right, minggu);
    }

    return root;
}

Pekan* cariPekan(Pekan *root, int minggu) {
    if (root == NULL || root->mingguKe == minggu) {
        return root;
    }

    if (minggu < root->mingguKe) {
        return cariPekan(root->left, minggu);
    }

    return cariPekan(root->right, minggu);
}

/* ================= INISIALISASI ================= */

void inisialisasiPohon(Bulan &B) {
    salinString(B.namaBulan, "Januari");
    B.root = NULL;

    for (int i = 1; i <= 4; i++) {
        B.root = insertPekan(B.root, i);
    }
}

/* ================= MUAT DATA ================= */


/* ================= CEK MATKUL ================= */

bool matkulTerdaftar(const char matkul[]) {
    const char daftar[][30] = {
        "strukturdata",
        "teoripeluang",
        "sistembasisdata",
        "teoribahasaautomata",
        "sistemoperasi"
    };

    for (int i = 0; i < 5; i++) {
        int j = 0;
        bool sama = true;

        while (daftar[i][j] != '\0' && matkul[j] != '\0') {
            if (daftar[i][j] != matkul[j]) {
                sama = false;
                break;
            }
            j++;
        }

        if (sama && daftar[i][j] == '\0' && matkul[j] == '\0') {
            return true;
        }
    }
    return false;
}


/* ================= TRAVERSAL ================= */


void tampilkanBulananBST(Pekan *root) {
    if (root == NULL) return;

    tampilkanBulananBST(root->left);

    cout << "---(Pekan " << root->mingguKe << ")---" << endl;

    bool adaTugas = false;
    MataKuliah *m = root->daftarMatkul;

    while (m != NULL) {
        Tugas *t = m->daftarTugas;
        while (t != NULL) {
            adaTugas = true;
            cout << "Mata Kuliah: " << m->namaMatkul << endl;
            cout << "  - (" << t->jenisTugas << ") "
                 << t->namaTugas
                 << ", Tenggat: " << t->tenggatWaktu << endl << endl;
            t = t->berikutnya;
        }
        m = m->berikutnya;
    }

    if (!adaTugas) {
        cout << "Tidak ada tugas!" << endl << endl;
    }

    tampilkanBulananBST(root->right);
}

void tampilkanPekanRapiBST(Pekan *root) {
    if (root == NULL) return;

    tampilkanPekanRapiBST(root->left);

    cout << "---(Pekan " << root->mingguKe << ")---\n";

    bool adaTugas = false;
    MataKuliah *m = root->daftarMatkul;

    while (m != NULL) {
        Tugas *t = m->daftarTugas;
        while (t != NULL) {
            adaTugas = true;
            cout << "Mata Kuliah: " << m->namaMatkul << "\n";
            cout << "  - " << " (" << t->jenisTugas << ") " << t->namaTugas << ", Tenggat: " << t->tenggatWaktu << endl << endl;
            t = t->berikutnya;
        }
        m = m->berikutnya;
    }

    if (!adaTugas) {
        cout << "Tidak ada tugas!" << endl << endl;
    }

    tampilkanPekanRapiBST(root->right);
}

void tampilkanBulananRapi(Bulan B) {
    cout << "================================" << endl;
    cout << "Daftar Tugas Bulan " << B.namaBulan << "\n";
    cout << "================================" << endl;

    tampilkanBulananBST(B.root);
}


void tampilkanPekanan(Bulan B, int pekan) {
    Pekan *p = cariPekan(B.root, pekan);
    if (p == NULL) {
        cout << "Pekan tidak ditemukan!\n";
        return;
    }

    cout << "\n=== TUGAS PEKAN " << pekan << " ===\n";

    MataKuliah *m = p->daftarMatkul;
    if (m == NULL) {
        cout << "Tidak ada tugas.\n";
        return;
    }

    while (m != NULL) {
        cout << "Mata Kuliah: " << m->namaMatkul << "\n";
        Tugas *t = m->daftarTugas;
        while (t != NULL) {
            cout << "  - " << " (" << t->jenisTugas << ") " << t->namaTugas << ", Tenggat: " << t->tenggatWaktu << endl << endl;
            t = t->berikutnya;
        }
        m = m->berikutnya;
    }
}

void tampilkanPerMatkulBST(Pekan *root, const char matkul[], bool &ditemukan, bool &adaTugas) {
    if (root == NULL) return;

    tampilkanPerMatkulBST(root->left, matkul, ditemukan, adaTugas);

    MataKuliah *m = root->daftarMatkul;
    while (m != NULL) {
        bool sama = true;
        int i = 0;

        while (matkul[i] != '\0' && m->namaMatkul[i] != '\0') {
            if (matkul[i] != m->namaMatkul[i]) {
                sama = false;
                break;
            }
            i++;
        }

        if (sama && matkul[i] == '\0' && m->namaMatkul[i] == '\0') {
            ditemukan = true;
            Tugas *t = m->daftarTugas;
            while (t != NULL) {
                adaTugas = true;
                cout << "Pekan " << root->mingguKe << " -> ";
                cout << " (" << t->jenisTugas << ") " << t->namaTugas << ", Tenggat: " << t->tenggatWaktu << endl << endl;
                t = t->berikutnya;
            }
        }
        m = m->berikutnya;
    }

    tampilkanPerMatkulBST(root->right, matkul, ditemukan, adaTugas);
}

void tampilkanPerMatkul(Bulan B, const char matkul[]) {
    cout << "\n=== TUGAS MATA KULIAH " << matkul << " ===\n";

    bool ditemukan = false;
    bool adaTugas = false;

    tampilkanPerMatkulBST(B.root, matkul, ditemukan, adaTugas);

    if (!ditemukan) {
        if (matkulTerdaftar(matkul)) {
            cout << "Mata kuliah \"" << matkul
                 << "\" terdaftar, belum terdapat tugas baru!\n";
        } else {
            cout << "Mata kuliah \"" << matkul
                 << "\" tidak ditemukan!\n";
            tampilkanDaftarMatkul();
        }
    } else if (!adaTugas) {
        cout << "Belum ada tugas untuk mata kuliah ini.\n";
    }

}

void tampilkanDaftarMatkul() {
    cout << "\nDAFTAR MATA KULIAH YANG TERSEDIA:\n";
    cout << "====================================\n";
    cout << "1. strukturdata\n";
    cout << "2. teoripeluang\n";
    cout << "3. sistembasisdata\n";
    cout << "4. teoribahasaautomata\n";
    cout << "5. sistemoperasi\n";
    cout << "====================================\n";
}

