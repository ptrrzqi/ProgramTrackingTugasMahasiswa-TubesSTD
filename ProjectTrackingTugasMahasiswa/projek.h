#ifndef POHONTUGAS_H
#define POHONTUGAS_H

#include <iostream>
using namespace std;

struct Tugas {
    char namaTugas[50];
    char jenisTugas[20];
    char tenggatWaktu[20];
    Tugas *berikutnya;
};

struct MataKuliah {
    char namaMatkul[50];
    Tugas *daftarTugas;
    MataKuliah *berikutnya;
};

struct Pekan {
    int mingguKe;
    MataKuliah *daftarMatkul;
    Pekan *berikutnya;
};

struct Bulan {
    char namaBulan[20];
    Pekan *daftarPekan;
};

void inisialisasiPohon(Bulan &B);
void muatDataTugas(Bulan &B);
void tampilkanBulanan(Bulan B);
void tampilkanPekanan(Bulan B, int pekan);
void tampilkanPerMatkul(Bulan B, const char matkul[]);
void tampilkanDaftarMatkul();

#endif
