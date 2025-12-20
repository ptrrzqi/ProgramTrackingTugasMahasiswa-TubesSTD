#include "projek.h"
#include <iostream>
using namespace std;

// ==================== FUNGSI UTILITAS ====================

// Fungsi untuk menyalin string
void salinString(char tujuan[], const char asal[])
{
    int i = 0;

    while (asal[i] != '\0')
    {
        tujuan[i] = asal[i];
        i = i + 1;
    }

    tujuan[i] = '\0';
}

// Fungsi untuk membandingkan dua string
int bandingkanString(const char s1[], const char s2[])
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i = i + 1;
    }

    return s1[i] - s2[i];
}

// Fungsi untuk membersihkan layar
void clearScreen()
{
    for (int i = 0; i < 30; i++)
    {
        cout << endl;
    }
}

// Fungsi untuk pause program
void pauseProgram()
{
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// ==================== FUNGSI BST - TUGAS ====================

// Fungsi untuk membuat node tugas baru
Tugas* buatTugas(const char nama[], const char jenis[], const char deadline[])
{
    Tugas* baru = new Tugas();

    salinString(baru->nama, nama);
    salinString(baru->jenis, jenis);
    salinString(baru->deadline, deadline);

    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

// Fungsi untuk menambahkan tugas ke BST
Tugas* tambahTugasBST(Tugas* root, Tugas* baru)
{
    if (root == NULL)
    {
        return baru;
    }

    int hasil = bandingkanString(baru->nama, root->nama);

    if (hasil < 0)
    {
        root->kiri = tambahTugasBST(root->kiri, baru);
    }
    else if (hasil > 0)
    {
        root->kanan = tambahTugasBST(root->kanan, baru);
    }

    return root;
}

// Fungsi untuk menampilkan semua tugas (in-order traversal)
void tampilkanTugasBST(Tugas* root)
{
    if (root == NULL)
    {
        return;
    }

    tampilkanTugasBST(root->kiri);

    cout << "    - " << root->nama
         << " (" << root->jenis << ")"
         << " - Deadline: " << root->deadline << endl;

    tampilkanTugasBST(root->kanan);
}

// Fungsi untuk menghapus semua tugas
void hapusSemuaTugas(Tugas* root)
{
    if (root == NULL)
    {
        return;
    }

    hapusSemuaTugas(root->kiri);
    hapusSemuaTugas(root->kanan);

    delete root;
}

// ==================== FUNGSI BST - MATA KULIAH ====================

// Fungsi untuk membuat node mata kuliah baru
MataKuliah* buatMataKuliah(const char nama[])
{
    MataKuliah* baru = new MataKuliah();

    salinString(baru->nama, nama);
    baru->tugas = NULL;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

// Fungsi untuk menambahkan mata kuliah ke BST
MataKuliah* tambahMataKuliahBST(MataKuliah* root, MataKuliah* baru)
{
    if (root == NULL)
    {
        return baru;
    }

    int hasil = bandingkanString(baru->nama, root->nama);

    if (hasil < 0)
    {
        root->kiri = tambahMataKuliahBST(root->kiri, baru);
    }
    else if (hasil > 0)
    {
        root->kanan = tambahMataKuliahBST(root->kanan, baru);
    }

    return root;
}

// Fungsi untuk mencari mata kuliah dalam BST
MataKuliah* cariMataKuliahBST(MataKuliah* root, const char nama[])
{
    if (root == NULL)
    {
        return NULL;
    }

    int hasil = bandingkanString(nama, root->nama);

    if (hasil == 0)
    {
        return root;
    }

    if (hasil < 0)
    {
        return cariMataKuliahBST(root->kiri, nama);
    }

    return cariMataKuliahBST(root->kanan, nama);
}

// Fungsi untuk menampilkan semua mata kuliah dan tugasnya
void tampilkanMataKuliahBST(MataKuliah* root)
{
    if (root == NULL)
    {
        return;
    }

    tampilkanMataKuliahBST(root->kiri);

    cout << "\n  " << root->nama << ":" << endl;
    tampilkanTugasBST(root->tugas);

    tampilkanMataKuliahBST(root->kanan);
}

// Fungsi untuk menghapus semua mata kuliah
void hapusSemuaMataKuliah(MataKuliah* root)
{
    if (root == NULL)
    {
        return;
    }

    hapusSemuaMataKuliah(root->kiri);
    hapusSemuaMataKuliah(root->kanan);
    hapusSemuaTugas(root->tugas);

    delete root;
}

// ==================== FUNGSI BST - PEKAN ====================

// Fungsi untuk membuat node pekan baru
Pekan* buatPekan(int nomor)
{
    Pekan* baru = new Pekan();

    baru->nomor = nomor;
    baru->matkul = NULL;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

// Fungsi untuk menambahkan pekan ke BST
Pekan* tambahPekanBST(Pekan* root, Pekan* baru)
{
    if (root == NULL)
    {
        return baru;
    }

    if (baru->nomor < root->nomor)
    {
        root->kiri = tambahPekanBST(root->kiri, baru);
    }
    else if (baru->nomor > root->nomor)
    {
        root->kanan = tambahPekanBST(root->kanan, baru);
    }

    return root;
}

// Fungsi untuk mencari pekan dalam BST
Pekan* cariPekanBST(Pekan* root, int nomor)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (nomor == root->nomor)
    {
        return root;
    }

    if (nomor < root->nomor)
    {
        return cariPekanBST(root->kiri, nomor);
    }

    return cariPekanBST(root->kanan, nomor);
}

// Fungsi untuk menghapus semua pekan
void hapusSemuaPekan(Pekan* root)
{
    if (root == NULL)
    {
        return;
    }

    hapusSemuaPekan(root->kiri);
    hapusSemuaPekan(root->kanan);
    hapusSemuaMataKuliah(root->matkul);

    delete root;
}

// ==================== FUNGSI BANTUAN UNTUK REKURSIF ====================

// Fungsi rekursif untuk menampilkan semua pekan (helper untuk tampilkanBulanLengkap)
static void tampilkanPekanRecursive(Pekan* root)
{
    if (root == NULL) {
        return;
    }

    tampilkanPekanRecursive(root->kiri);

    cout << "\n---------- PEKAN " << root->nomor << " ----------\n";

    if (root->matkul == NULL)
    {
        cout << "  Tidak ada tugas untuk pekan ini.\n";
    }
    else
    {
        tampilkanMataKuliahBST(root->matkul);
    }

    tampilkanPekanRecursive(root->kanan);
}

// Fungsi rekursif untuk mencari di semua pekan (helper untuk cariTugasPerMataKuliah)
static void cariDiSemuaPekan(Pekan* root, const char matkul[], bool& ditemukan, bool& adaTugas)
{
    if (root == NULL)
    {
        return;
    }

    cariDiSemuaPekan(root->kiri, matkul, ditemukan, adaTugas);

    MataKuliah* m = cariMataKuliahBST(root->matkul, matkul);

    if (m != NULL)
    {
        ditemukan = true;

        if (m->tugas != NULL)
        {
            adaTugas = true;
            cout << "\nPekan " << root->nomor << ":\n";
            tampilkanTugasBST(m->tugas);
        }
    }

    cariDiSemuaPekan(root->kanan, matkul, ditemukan, adaTugas);
}

// ==================== FUNGSI UTAMA ====================

// Fungsi untuk menginisialisasi bulan
void initBulan(Bulan& bulan, const char nama[])
{
    salinString(bulan.nama, nama);
    bulan.pekan = NULL;
}

// Fungsi untuk menambahkan data ke bulan
void tambahDataKeBulan(Bulan& bulan, int pekan, const char matkul[],
                      const char tugas[], const char jenis[], const char deadline[])
{
    // Cari atau buat pekan
    Pekan* p = cariPekanBST(bulan.pekan, pekan);

    if (p == NULL)
    {
        p = buatPekan(pekan);
        bulan.pekan = tambahPekanBST(bulan.pekan, p);
    }

    // Cari atau buat mata kuliah
    MataKuliah* m = cariMataKuliahBST(p->matkul, matkul);

    if (m == NULL)
    {
        m = buatMataKuliah(matkul);
        p->matkul = tambahMataKuliahBST(p->matkul, m);
    }

    // Tambah tugas
    Tugas* t = buatTugas(tugas, jenis, deadline);
    m->tugas = tambahTugasBST(m->tugas, t);
}

// Fungsi untuk menampilkan bulan lengkap dengan semua tugas
void tampilkanBulanLengkap(Bulan bulan)
{
    cout << "\n================================================\n";
    cout << "            TUGAS BULAN " << bulan.nama << "\n";
    cout << "================================================\n";

    tampilkanPekanRecursive(bulan.pekan);

    cout << "\n================================================\n";
}

// Fungsi untuk menampilkan tugas pekan tertentu
void tampilkanPekanTertentu(Bulan bulan, int pekan)
{
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

// Fungsi untuk mencari tugas berdasarkan mata kuliah
void cariTugasPerMataKuliah(Bulan bulan, const char matkul[])
{
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

// Fungsi untuk menampilkan menu utama
void tampilkanMenuUtama()
{
    cout << "\n================================================\n";
    cout << "        SISTEM MANAJEMEN TUGAS KULIAH\n";
    cout << "================================================\n";
    cout << "1. Tampilkan Semua Bulan\n";
    cout << "2. Tampilkan Tugas per Pekan\n";
    cout << "3. Cari Tugas per Mata Kuliah\n";
    cout << "4. Daftar Mata Kuliah Tersedia\n";
    cout << "0. Keluar Program\n";
    cout << "================================================\n";
    cout << "Pilihan Anda: ";
}

// Fungsi untuk menampilkan daftar mata kuliah
void tampilkanDaftarMataKuliah()
{
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
