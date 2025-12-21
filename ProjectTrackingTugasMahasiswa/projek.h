#ifndef PROJEK_H
#define PROJEK_H

#include <iostream>
using namespace std;

// ==================== STRUKTUR DATA BST ====================

// BST untuk Tugas (terurut berdasarkan nama)
struct Tugas
{
    char nama[50];
    char jenis[20];
    char deadline[20];
    Tugas* kiri;
    Tugas* kanan;
};

// BST untuk Mata Kuliah (terurut berdasarkan nama)
struct MataKuliah
{
    char nama[50];
    Tugas* tugas;          // Root BST Tugas
    MataKuliah* kiri;
    MataKuliah* kanan;
};

// BST untuk Pekan (terurut berdasarkan nomor)
struct Pekan
{
    int nomor;            // 1-4
    MataKuliah* matkul;   // Root BST Mata Kuliah
    Pekan* kiri;
    Pekan* kanan;
};

// Struktur Bulan
struct Bulan
{
    char nama[20];
    Pekan* pekan;         // Root BST Pekan
};

// ==================== DEKLARASI FUNGSI ====================

// Fungsi Utilitas
void salinString(char tujuan[], const char asal[]);
int bandingkanString(const char s1[], const char s2[]);
void clearScreen();
void pauseProgram();

// Fungsi BST - Tugas
Tugas* buatTugas(const char nama[], const char jenis[], const char deadline[]);
Tugas* tambahTugasBST(Tugas* root, Tugas* baru);
void tampilkanTugasBST(Tugas* root);
void hapusSemuaTugas(Tugas* root);

// Fungsi BST - Mata Kuliah
MataKuliah* buatMataKuliah(const char nama[]);
MataKuliah* tambahMataKuliahBST(MataKuliah* root, MataKuliah* baru);
MataKuliah* cariMataKuliahBST(MataKuliah* root, const char nama[]);
void tampilkanMataKuliahBST(MataKuliah* root);
void hapusSemuaMataKuliah(MataKuliah* root);

// Fungsi BST - Pekan
Pekan* buatPekan(int nomor);
Pekan* tambahPekanBST(Pekan* root, Pekan* baru);
Pekan* cariPekanBST(Pekan* root, int nomor);
void hapusSemuaPekan(Pekan* root);

// Fungsi Utama
void initBulan(Bulan& bulan, const char nama[]);
void tambahDataKeBulan(Bulan& bulan, int pekan, const char matkul[],
                      const char tugas[], const char jenis[], const char deadline[]);
void tampilkanBulanLengkap(Bulan bulan);
void tampilkanPekanTertentu(Bulan bulan, int pekan);
void cariTugasPerMataKuliah(Bulan bulan, const char matkul[]);
void tampilkanMenuUtama();
void tampilkanDaftarMataKuliah();

// Konstanta Data
const int JUMLAH_BULAN = 12;
const int JUMLAH_MATKUL = 5;

#endif
