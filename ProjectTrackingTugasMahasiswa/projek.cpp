#include "projek.h"
#include <iostream>
#include <cctype>
using namespace std;

//fungsi menyalin string
void salinString(char tujuan[], const char asal[]) {
    int i = 0;

    while (asal[i] != '\0')
    {
        tujuan[i] = asal[i];
        i = i + 1;
    }

    tujuan[i] = '\0';
}

//fungsi membandingkan string
int bandingkanString(const char s1[], const char s2[]) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i = i + 1;
    }

    return s1[i] - s2[i];
}

//fungsi membersihkan layar
void clearScreen() {
    for (int i = 0; i < 30; i++)
    {
        cout << endl;
    }
}

//fungsi pause program
void pauseProgram() {
    cout << "\nTekan Enter untuk melanjutkan";
    cin.ignore();
    cin.get();
}

//fungsi debugging - tampilkan jenis dan deadline semua tugas
void tampilkanJenisTugasDiBST(Tugas* root) {
    if (root == NULL) return;

    tampilkanJenisTugasDiBST(root->kiri);
    cout << "  - Jenis: " << root->jenis << " | Deadline: " << root->deadline << endl;
    tampilkanJenisTugasDiBST(root->kanan);
}

//fungsi membuat node tugas baru
Tugas* buatTugas(const char nama[], const char jenis[], const char deadline[]) {
    Tugas* baru = new Tugas();

    salinString(baru->nama, nama);
    salinString(baru->jenis, jenis);
    salinString(baru->deadline, deadline);

    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

//fungsi menambahkan tugas ke BST
Tugas* tambahTugasBST(Tugas* root, Tugas* baru) {
    if (root == NULL) {
        return baru;
    }

    int hasil = bandingkanString(baru->nama, root->nama);

    if (hasil < 0) {
        root->kiri = tambahTugasBST(root->kiri, baru);
    }
    else if (hasil > 0) {
        root->kanan = tambahTugasBST(root->kanan, baru);
    }
    return root;
}

//fungsi menampilkan semua tugas dengan format detail
void tampilkanDetailTugas(Tugas* root) {
    if (root == NULL) {
        return;
    }
    tampilkanDetailTugas(root->kiri);
    cout << "  - " << root->nama
         << " | Jenis: \"" << root->jenis << "\""
         << " | Deadline: \"" << root->deadline << "\"\n";
    tampilkanDetailTugas(root->kanan);
}

//fungsi menampilkan semua tugas (in-order traversal)
void tampilkanTugasBST(Tugas* root) {
    if (root == NULL) {
        return;
    }

    tampilkanTugasBST(root->kiri);

    cout << "    - " << root->nama
         << " (" << root->jenis << ")"
         << " - Deadline: " << root->deadline << endl;

    tampilkanTugasBST(root->kanan);
}

//fungsi menghapus semua tugas
void hapusSemuaTugas(Tugas* root) {
    if (root == NULL) {
        return;
    }

    hapusSemuaTugas(root->kiri);
    hapusSemuaTugas(root->kanan);

    delete root;
}

//fungsi membuat node mata kuliah baru
MataKuliah* buatMataKuliah(const char nama[]) {
    MataKuliah* baru = new MataKuliah();

    salinString(baru->nama, nama);
    baru->tugas = NULL;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

//fungsi menambahkan mata kuliah ke BST
MataKuliah* tambahMataKuliahBST(MataKuliah* root, MataKuliah* baru) {
    if (root == NULL) {
        return baru;
    }

    int hasil = bandingkanString(baru->nama, root->nama);

    if (hasil < 0) {
        root->kiri = tambahMataKuliahBST(root->kiri, baru);
    }
    else if (hasil > 0) {
        root->kanan = tambahMataKuliahBST(root->kanan, baru);
    }
    return root;
}

//fungsi mencari mata kuliah dalam BST
MataKuliah* cariMataKuliahBST(MataKuliah* root, const char nama[]) {
    if (root == NULL) {
        return NULL;
    }

    int hasil = bandingkanString(nama, root->nama);

    if (hasil == 0) {
        return root;
    }

    if (hasil < 0) {
        return cariMataKuliahBST(root->kiri, nama);
    }

    return cariMataKuliahBST(root->kanan, nama);
}

//fungsi menampilkan semua mata kuliah dan tugasnya
void tampilkanMataKuliahBST(MataKuliah* root) {
    if (root == NULL) {
        return;
    }

    tampilkanMataKuliahBST(root->kiri);

    cout << "\n  " << root->nama << ":" << endl;
    tampilkanTugasBST(root->tugas);

    tampilkanMataKuliahBST(root->kanan);
}

//fungsi menghapus semua mata kuliah
void hapusSemuaMataKuliah(MataKuliah* root) {
    if (root == NULL) {
        return;
    }

    hapusSemuaMataKuliah(root->kiri);
    hapusSemuaMataKuliah(root->kanan);
    hapusSemuaTugas(root->tugas);

    delete root;
}

//fungsi membuat node pekan baru
Pekan* buatPekan(int nomor) {
    Pekan* baru = new Pekan();

    baru->nomor = nomor;
    baru->matkul = NULL;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

//fungsi menambahkan pekan ke BST
Pekan* tambahPekanBST(Pekan* root, Pekan* baru) {
    if (root == NULL) {
        return baru;
    }
    if (baru->nomor < root->nomor) {
        root->kiri = tambahPekanBST(root->kiri, baru);
    } else if (baru->nomor > root->nomor) {
        root->kanan = tambahPekanBST(root->kanan, baru);
    }

    return root;
}

//fungsi mencari pekan dalam BST
Pekan* cariPekanBST(Pekan* root, int nomor) {
    if (root == NULL) {
        return NULL;
    }
    if (nomor == root->nomor) {
        return root;
    }
    if (nomor < root->nomor) {
        return cariPekanBST(root->kiri, nomor);
    }

    return cariPekanBST(root->kanan, nomor);
}

//fungsi menghapus semua pekan
void hapusSemuaPekan(Pekan* root) {
    if (root == NULL) {
        return;
    }

    hapusSemuaPekan(root->kiri);
    hapusSemuaPekan(root->kanan);
    hapusSemuaMataKuliah(root->matkul);

    delete root;
}

//fungsi rekursif menampilkan semua pekan (helper untuk tampilkanBulanLengkap)
static void tampilkanPekanRecursive(Pekan* root) {
    if (root == NULL) {
        return;
    }

    tampilkanPekanRecursive(root->kiri);

    cout << "\n---------- PEKAN " << root->nomor << " ----------\n";

    if (root->matkul == NULL) {
        cout << "  Tidak ada tugas untuk pekan ini.\n";
    } else {
        tampilkanMataKuliahBST(root->matkul);
    }
    tampilkanPekanRecursive(root->kanan);
}

//fungsi rekursif mencari di semua pekan (helper untuk cariTugasPerMataKuliah)
static void cariDiSemuaPekan(Pekan* root, const char matkul[], bool& ditemukan, bool& adaTugas) {
    if (root == NULL) {
        return;
    }

    cariDiSemuaPekan(root->kiri, matkul, ditemukan, adaTugas);

    MataKuliah* m = cariMataKuliahBST(root->matkul, matkul);

    if (m != NULL) {
        ditemukan = true;

        if (m->tugas != NULL) {
            adaTugas = true;
            cout << "\nPekan " << root->nomor << ":\n";
            tampilkanTugasBST(m->tugas);
        }
    }
    cariDiSemuaPekan(root->kanan, matkul, ditemukan, adaTugas);
}

//fungsi menginisialisasi bulan
void initBulan(Bulan& bulan, const char nama[]) {
    salinString(bulan.nama, nama);
    bulan.pekan = NULL;
}

//fungsi menambahkan data ke bulan
void tambahDataKeBulan(Bulan& bulan, int pekan, const char matkul[],
                      const char tugas[], const char jenis[], const char deadline[]) {
    //cari atau buat pekan
    Pekan* p = cariPekanBST(bulan.pekan, pekan);

    if (p == NULL) {
        p = buatPekan(pekan);
        bulan.pekan = tambahPekanBST(bulan.pekan, p);
    }

    //cari atau buat mata kuliah
    MataKuliah* m = cariMataKuliahBST(p->matkul, matkul);

    if (m == NULL) {
        m = buatMataKuliah(matkul);
        p->matkul = tambahMataKuliahBST(p->matkul, m);
    }

    //tambah tugas
    Tugas* t = buatTugas(tugas, jenis, deadline);
    m->tugas = tambahTugasBST(m->tugas, t);
}

//fungsi menampilkan bulan lengkap dengan semua tugas
void tampilkanBulanLengkap(Bulan bulan) {
    cout << "\n================================================\n";
    cout << "            TUGAS BULAN " << bulan.nama << "\n";
    cout << "================================================\n";

    tampilkanPekanRecursive(bulan.pekan);

    cout << "\n================================================\n";
}

//fungsi menampilkan tugas pekan tertentu
void tampilkanPekanTertentu(Bulan bulan, int pekan) {
    Pekan* p = cariPekanBST(bulan.pekan, pekan);

    if (p == NULL)
    {
        cout << "\nPekan " << pekan << " tidak ditemukan dalam bulan " << bulan.nama << "!\n";
        return;
    }

    cout << "\n================================================\n";
    cout << "        TUGAS PEKAN " << pekan << " - " << bulan.nama << "\n";
    cout << "================================================\n";

    if (p->matkul == NULL)
    {
        cout << "\n  Tidak ada tugas untuk pekan ini.\n";
    }
    else
    {
        tampilkanMataKuliahBST(p->matkul);
    }

    cout << "\n================================================\n";
}

//fungsi mencari tugas berdasarkan mata kuliah
void cariTugasPerMataKuliah(Bulan bulan, const char matkul[]) {
    cout << "\n================================================\n";
    cout << "      TUGAS MATA KULIAH: " << matkul << "\n";
    cout << "================================================\n";

    bool ditemukan = false;
    bool adaTugas = false;

    cariDiSemuaPekan(bulan.pekan, matkul, ditemukan, adaTugas);

    if (!ditemukan)
    {
        cout << "\nMata kuliah \"" << matkul << "\" tidak ditemukan!\n";
    }
    else if (!adaTugas)
    {
        cout << "\nMata kuliah ditemukan, tetapi belum ada tugas.\n";
    }

    cout << "\n================================================\n";
}

//fungsi menampilkan menu utama
void tampilkanMenuUtama() {
    cout << "================================================\n";
    cout << "        SISTEM TRACKING TUGAS KULIAH\n";
    cout << "================================================\n";
    cout << "1. Tampilkan Semua Bulan\n";
    cout << "2. Tampilkan Tugas per Pekan\n";
    cout << "3. Cari Tugas per Mata Kuliah\n";
    cout << "4. Daftar Mata Kuliah Tersedia\n";
    cout << "5. Hapus Tugas\n";
    cout << "0. Keluar Program\n";
    cout << "================================================\n";
    cout << "Pilihan Anda: ";
}

//fungsi menampilkan daftar mata kuliah
void tampilkanDaftarMataKuliah() {
    cout << "\n================================================\n";
    cout << "        DAFTAR MATA KULIAH TERSEDIA\n";
    cout << "================================================\n";
    cout << "1. strukturdata\n";
    cout << "2. teoripeluang\n";
    cout << "3. sistembasisdata\n";
    cout << "4. teoribahasaautomata\n";
    cout << "5. sistemoperasi\n";
    cout << "================================================\n";
}

//fungsi helper menyimpan mata kuliah ke array
void simpanInOrder(MataKuliah* node, MataKuliah* arr[], int& idx) {
    if (node == NULL) return;
    simpanInOrder(node->kiri, arr, idx);
    arr[idx++] = node;
    simpanInOrder(node->kanan, arr, idx);
}

MataKuliah* pilihMataKuliah(MataKuliah* root) {
    if (root == NULL) {
        cout << "Tidak ada mata kuliah!\n";
        return NULL;
    }

    // array menyimpan mata kuliah
    MataKuliah* daftar[50];
    int jumlah = 0;

    //simpan semua mata kuliah ke array
    simpanInOrder(root, daftar, jumlah);

    //tampilkan pilihan
    cout << "\nDaftar Mata Kuliah:\n";
    for (int i = 0; i < jumlah; i++)
    {
        cout << i + 1 << ". " << daftar[i]->nama << endl;
    }

    //minta input user
    int pilih;
    cout << "\nPilih mata kuliah (angka): ";
    cin >> pilih;

    if (pilih < 1 || pilih > jumlah)
    {
        cout << "Pilihan tidak valid!\n";
        return NULL;
    }

    return daftar[pilih - 1];
}

//fungsi mencari tugas berdasarkan nama
Tugas* cariTugasByNama(Tugas* root, const char namaTugas[]) {
    if (root == NULL) {
            return NULL;
    }

    int cmp = bandingkanString(namaTugas, root->nama);

    if (cmp == 0) {
            return root;
    }

    else if (cmp < 0) {
            return cariTugasByNama(root->kiri, namaTugas);
    } else {
        return cariTugasByNama(root->kanan, namaTugas);
    }
}

//fungsi menghapus tugas berdasarkan nama di BST
Tugas* deleteTugasByNama(Tugas* root, const char namaTugas[], bool& berhasil) {
    if (root == NULL) {
            return NULL;
    }

    int cmp = bandingkanString(namaTugas, root->nama);

    if (cmp == 0) {
        berhasil = true;

        //case 1: 0 child
        if (root->kiri == NULL && root->kanan == NULL) {
            delete root;
            return NULL;
        }
        //case 2: 1 child (kanan)
        else if (root->kiri == NULL) {
            Tugas* temp = root->kanan;
            delete root;
            return temp;
        }
        //case 3: 1 child (kiri)
        else if (root->kanan == NULL) {
            Tugas* temp = root->kiri;
            delete root;
            return temp;
        }
        //case 4: 2 children
        else {
            //cari successor in-order (smallest in right subtree)
            Tugas* successor = root->kanan;
            while (successor->kiri != NULL) {
                successor = successor->kiri;
            }

            //copy data
            salinString(root->nama, successor->nama);
            salinString(root->jenis, successor->jenis);
            salinString(root->deadline, successor->deadline);

            //delete successor
            root->kanan = deleteTugasByNama(root->kanan, successor->nama, berhasil);
            return root;
        }
    }
    else if (cmp < 0) {
        root->kiri = deleteTugasByNama(root->kiri, namaTugas, berhasil);
    } else {
        root->kanan = deleteTugasByNama(root->kanan, namaTugas, berhasil);
    }

    return root;
}

//fungsi utama menghapus tugas berdasarkan nama
void deleteTugasByNamaMK(MataKuliah* mk) {
    if (mk == NULL) {
        cout << "Error: Mata kuliah tidak ditemukan!\n";
        return;
    }

    cout << "\n==================================================\n";
    cout << "DELETE TUGAS - " << mk->nama << "\n";
    cout << "==================================================\n";

    if (mk->tugas == NULL) {
        cout << "\nTidak ada tugas dalam mata kuliah ini.\n";
        cout << "==================================================\n";
        return;
    }

    cout << "\nDAFTAR TUGAS:\n";
    cout << "--------------------------------------------------\n";
    tampilkanTugasBST(mk->tugas);
    cout << "--------------------------------------------------\n";

    char namaTugas[50];
    cout << "\nMasukkan nama tugas yang ingin dihapus: ";
    cin.ignore();
    cin.getline(namaTugas, 50);

    Tugas* tugasDitemukan = cariTugasByNama(mk->tugas, namaTugas);

    if (tugasDitemukan == NULL) {
        cout << "\nERROR: Tugas \"" << namaTugas << "\" tidak ditemukan!\n";
        cout << "Pastikan nama tugas sama persis.\n";
        return;
    }

    cout << "\n==================================================\n";
    cout << "TUGAS YANG AKAN DIHAPUS:\n";
    cout << "--------------------------------------------------\n";
    cout << "Nama     : " << tugasDitemukan->nama << "\n";
    cout << "Jenis    : " << tugasDitemukan->jenis << "\n";
    cout << "Deadline : " << tugasDitemukan->deadline << "\n";
    cout << "--------------------------------------------------\n";

    char konfirmasi;
    cout << "\nApakah yakin ingin menghapus? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi != 'y' && konfirmasi != 'Y') {
        cout << "\nPenghapusan dibatalkan.\n";
        return;
    }

    bool berhasil = false;
    mk->tugas = deleteTugasByNama(mk->tugas, namaTugas, berhasil);

    if (berhasil) {
        cout << "\n==================================================\n";
        cout << "SUKSES: Tugas berhasil dihapus!\n";
        cout << "==================================================\n\n";

        cout << "SISA TUGAS DI MATA KULIAH " << mk->nama << ":\n";
        cout << "--------------------------------------------------\n";
        if (mk->tugas == NULL) {
            cout << "  (Tidak ada tugas)\n";
        } else {
            tampilkanTugasBST(mk->tugas);
        }
        cout << "--------------------------------------------------\n";
    } else {
        cout << "\nGagal menghapus tugas!\n";
    }
}

//fungsi menghapus tugas dari bulan
void deleteTugasFromBulan(Bulan& bulan) {
    if (bulan.pekan == NULL) {
        cout << "Tidak ada data pekan di bulan ini!\n";
        return;
    }

    int nomorPekan;
    cout << "\nPilih Pekan (1-4): ";
    cin >> nomorPekan;

    if (nomorPekan < 1 || nomorPekan > 4) {
        cout << "Pekan tidak valid!\n";
        return;
    }

    Pekan* p = cariPekanBST(bulan.pekan, nomorPekan);
    if (p == NULL) {
        cout << "Pekan " << nomorPekan << " tidak ditemukan!\n";
        return;
    }

    if (p->matkul == NULL) {
        cout << "Tidak ada mata kuliah di pekan ini!\n";
        return;
    }

    cout << "\nMata kuliah di Pekan " << nomorPekan << ":\n";
    cout << "--------------------------------------------------\n";
    tampilkanMataKuliahBST(p->matkul);
    cout << "--------------------------------------------------\n";

    MataKuliah* mk = pilihMataKuliah(p->matkul);
    if (mk == NULL) {
        return;
    }

    deleteTugasByNamaMK(mk);
}
