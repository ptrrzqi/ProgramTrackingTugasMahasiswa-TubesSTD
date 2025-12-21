#ifndef PROJEK_H
#define PROJEK_H
#define QUIZ  1
#define TUGAS 2
#define UJIAN  3

#include <iostream>
using namespace std;

//BST Tugas (terurut berdasarkan nama)
struct Tugas
{
    char nama[50];
    char jenis[20];
    char deadline[20];
    Tugas* kiri;
    Tugas* kanan;
};

//BST Mata Kuliah (terurut berdasarkan nama)
struct MataKuliah
{
    char nama[50];
    Tugas* tugas;          //root BST Tugas
    MataKuliah* kiri;
    MataKuliah* kanan;
};

//BST Pekan (terurut berdasarkan nomor)
struct Pekan
{
    int nomor;            //1-4
    MataKuliah* matkul;   //root BST Mata Kuliah
    Pekan* kiri;
    Pekan* kanan;
};

//struktur Bulan
struct Bulan
{
    char nama[20];
    Pekan* pekan;         //root BST Pekan
};

//fungsi utilitas
void salinString(char tujuan[], const char asal[]);
int bandingkanString(const char s1[], const char s2[]);
void clearScreen();
void pauseProgram();
//fungsi BST - Tugas
Tugas* buatTugas(const char nama[], const char jenis[], const char deadline[]);
Tugas* tambahTugasBST(Tugas* root, Tugas* baru);
void tampilkanTugasBST(Tugas* root);
void hapusSemuaTugas(Tugas* root);
//fungsi BST - Matakuliah
MataKuliah* buatMataKuliah(const char nama[]);
MataKuliah* tambahMataKuliahBST(MataKuliah* root, MataKuliah* baru);
MataKuliah* cariMataKuliahBST(MataKuliah* root, const char nama[]);
void tampilkanMataKuliahBST(MataKuliah* root);
void hapusSemuaMataKuliah(MataKuliah* root);
//fungsi BST - Pekan
Pekan* buatPekan(int nomor);
Pekan* tambahPekanBST(Pekan* root, Pekan* baru);
Pekan* cariPekanBST(Pekan* root, int nomor);
void hapusSemuaPekan(Pekan* root);
//fungsi utama
void initBulan(Bulan& bulan, const char nama[]);
void tambahDataKeBulan(Bulan& bulan, int pekan, const char matkul[],
                      const char tugas[], const char jenis[], const char deadline[]);
void tampilkanBulanLengkap(Bulan bulan);
void tampilkanPekanTertentu(Bulan bulan, int pekan);
void cariTugasPerMataKuliah(Bulan bulan, const char matkul[]);
void tampilkanMenuUtama();
void tampilkanDaftarMataKuliah();
//fungsi memilih mata kuliah
MataKuliah* pilihMataKuliah(MataKuliah* root);
void simpanInOrder(MataKuliah* node, MataKuliah* arr[], int& idx);
//fungsi delete berdasarkan nama
Tugas* cariTugasByNama(Tugas* root, const char namaTugas[]);
Tugas* deleteTugasByNama(Tugas* root, const char namaTugas[], bool& berhasil);
void deleteTugasByNamaMK(MataKuliah* mk);
void deleteTugasFromBulan(Bulan& bulan);
//konstanta data
const int JUMLAH_BULAN = 12;
const int JUMLAH_MATKUL = 5;

#endif
