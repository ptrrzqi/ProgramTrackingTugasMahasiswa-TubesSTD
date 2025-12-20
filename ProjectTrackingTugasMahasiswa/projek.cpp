#include "projek.h"
#include <iostream>
using namespace std;

//tes_push_github

void salinString(char tujuan[], const char asal[]) {
    int i = 0;
    while (asal[i] != '\0') {
        tujuan[i] = asal[i];
        i = i + 1;
    }
    tujuan[i] = '\0';
}

void inisialisasiPohon(Bulan &B) {
    salinString(B.namaBulan, "Januari");
    B.daftarPekan = NULL;

    for (int i = 4; i >= 1; i = i - 1) {
        Pekan *p = new Pekan;
        p->mingguKe = i;
        p->daftarMatkul = NULL;
        p->berikutnya = B.daftarPekan;
        B.daftarPekan = p;
    }
}

void muatDataTugas(Bulan &B) {
    cout << "Memuat data tugas ke dalam sistem...\n";

    Pekan *p1 = B.daftarPekan;
    while (p1 != NULL) {
        if (p1->mingguKe == 1) {
            break;
        }
        p1 = p1->berikutnya;
    }

    if (p1 != NULL) {
        MataKuliah *m1 = new MataKuliah;
        salinString(m1->namaMatkul, "strukturdata");

        Tugas *t1 = new Tugas;
        salinString(t1->namaTugas, "Quiz Linked List");
        salinString(t1->jenisTugas, "Quiz");
        salinString(t1->tenggatWaktu, "10 Jan");
        t1->berikutnya = NULL;

        m1->daftarTugas = t1;
        m1->berikutnya = p1->daftarMatkul;
        p1->daftarMatkul = m1;
    }

    Pekan *p2 = B.daftarPekan;
    while (p2 != NULL) {
        if (p2->mingguKe == 2) {
            break;
        }
        p2 = p2->berikutnya;
    }

    if (p2 != NULL) {
        MataKuliah *m2 = new MataKuliah;
        salinString(m2->namaMatkul, "sistembasisdata");

        Tugas *t2 = new Tugas;
        salinString(t2->namaTugas, "ER Diagram");
        salinString(t2->jenisTugas, "Tugas");
        salinString(t2->tenggatWaktu, "15 Jan");
        t2->berikutnya = NULL;

        m2->daftarTugas = t2;
        m2->berikutnya = p2->daftarMatkul;
        p2->daftarMatkul = m2;
    }

    Pekan *p3 = B.daftarPekan;
    while (p3 != NULL) {
        if (p3->mingguKe == 3) {
            break;
        }
        p3 = p3->berikutnya;
    }

    if (p3 != NULL) {
        MataKuliah *m3 = new MataKuliah;
        salinString(m3->namaMatkul, "sistemoperasi");

        Tugas *t3 = new Tugas;
        salinString(t3->namaTugas, "Tugas Process");
        salinString(t3->jenisTugas, "Tugas");
        salinString(t3->tenggatWaktu, "20 Jan");
        t3->berikutnya = NULL;

        m3->daftarTugas = t3;
        m3->berikutnya = p3->daftarMatkul;
        p3->daftarMatkul = m3;
    }

    Pekan *p4 = B.daftarPekan;
    while (p4 != NULL) {
        if (p4->mingguKe == 4) {
            break;
        }
        p4 = p4->berikutnya;
    }

    if (p4 != NULL) {
        MataKuliah *m4 = new MataKuliah;
        salinString(m4->namaMatkul, "strukturdata");

        Tugas *t4 = new Tugas;
        salinString(t4->namaTugas, "UTS");
        salinString(t4->jenisTugas, "Ujian");
        salinString(t4->tenggatWaktu, "25 Jan");
        t4->berikutnya = NULL;

        m4->daftarTugas = t4;
        m4->berikutnya = p4->daftarMatkul;
        p4->daftarMatkul = m4;
    }

    cout << "Berhasil memuat data tugas!\n\n";
}

void tampilkanBulanan(Bulan B) {
    cout << "\n=== DAFTAR TUGAS BULAN " << B.namaBulan << " ===\n";

    Pekan *p = B.daftarPekan;
    bool adaTugas = false;

    while (p != NULL) {
        bool adaTugasPekan = false;

        MataKuliah *m = p->daftarMatkul;
        while (m != NULL) {
            if (m->daftarTugas != NULL) {
                adaTugasPekan = true;
                adaTugas = true;
                break;
            }
            m = m->berikutnya;
        }

        if (adaTugasPekan) {
            cout << "\n--- Pekan " << p->mingguKe << " ---\n";

            MataKuliah *m = p->daftarMatkul;
            while (m != NULL) {
                if (m->daftarTugas != NULL) {
                    cout << "\nMata Kuliah: " << m->namaMatkul << "\n";

                    Tugas *t = m->daftarTugas;
                    while (t != NULL) {
                        cout << "  - " << t->namaTugas;
                        cout << " (" << t->jenisTugas << ")";
                        cout << ", Tenggat: " << t->tenggatWaktu << "\n";
                        t = t->berikutnya;
                    }
                }
                m = m->berikutnya;
            }
        }

        p = p->berikutnya;
    }

    if (adaTugas == false) {
        cout << "\nBelum ada tugas untuk bulan ini.\n";
    }
}

void tampilkanPekanan(Bulan B, int pekan) {
    Pekan *p = B.daftarPekan;
    while (p != NULL && p->mingguKe != pekan) {
        p = p->berikutnya;
    }

    if (p == NULL || pekan < 1 || pekan > 4) {
        cout << "Pekan tidak ditemukan! (Hanya pekan 1-4)\n";
        return;
    }

    cout << "\n=== TUGAS PEKAN " << pekan << " ===\n";

    bool adaTugas = false;
    MataKuliah *m = p->daftarMatkul;

    if (m == NULL) {
        cout << "\nTidak ada tugas untuk pekan ini.\n";
        return;
    }

    while (m != NULL) {
        if (m->daftarTugas != NULL) {
            adaTugas = true;
            cout << "\nMata Kuliah: " << m->namaMatkul << "\n";

            Tugas *t = m->daftarTugas;
            while (t != NULL) {
                cout << "  - " << t->namaTugas;
                cout << " (" << t->jenisTugas << ")";
                cout << ", Tenggat: " << t->tenggatWaktu << "\n";
                t = t->berikutnya;
            }
        }
        m = m->berikutnya;
    }

    if (adaTugas == false) {
        cout << "\nTidak ada tugas untuk pekan ini.\n";
    }
}

void tampilkanPerMatkul(Bulan B, const char matkul[]) {
    cout << "\n=== TUGAS MATA KULIAH " << matkul << " ===\n";

    bool ditemukan = false;
    bool adaTugas = false;

    Pekan *p = B.daftarPekan;
    while (p != NULL) {
        MataKuliah *m = p->daftarMatkul;
        while (m != NULL) {
            bool sama = true;
            int i = 0;
            while (matkul[i] != '\0' && m->namaMatkul[i] != '\0') {
                if (matkul[i] != m->namaMatkul[i]) {
                    sama = false;
                    break;
                }
                i = i + 1;
            }

            if (sama && matkul[i] == '\0' && m->namaMatkul[i] == '\0') {
                ditemukan = true;

                Tugas *t = m->daftarTugas;
                while (t != NULL) {
                    adaTugas = true;
                    cout << "Pekan " << p->mingguKe << " -> ";
                    cout << t->namaTugas;
                    cout << " (" << t->jenisTugas << ")";
                    cout << ", Tenggat: " << t->tenggatWaktu << "\n";
                    t = t->berikutnya;
                }
            }
            m = m->berikutnya;
        }
        p = p->berikutnya;
    }

    if (ditemukan == false) {
        cout << "Mata kuliah \"" << matkul << "\" tidak ditemukan!\n";
        tampilkanDaftarMatkul();
    } else if (adaTugas == false) {
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
