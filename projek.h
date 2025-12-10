#ifndef TASKTREE_H
#define TASKTREE_H

#include <iostream>
using namespace std;

// --------------------- ADT Tugas ------------------------
struct Task {
    char namaTugas[50];
    char jenisTugas[20];
    char deadline[20];
    Task *next;
};

// --------------------- ADT Mata Kuliah ------------------------
struct Course {
    char namaMatkul[50];
    Task *listTask;
    Course *next;
};

// --------------------- ADT Pekan ------------------------
struct Week {
    int mingguKe;
    Course *listCourse;
    Week *next;
};

// --------------------- ADT Bulan (root tree) ------------------------
struct Month {
    char namaBulan[20];
    Week *listWeek;
};

// --------------------- FUNGSI / PROSEDUR ------------------------

void initTree(Month &M, const char nama[]);
void tambahTugas(Month &M, int pekan,
                 const char matkul[],
                 const char namaTugas[],
                 const char jenis[],
                 const char deadline[]);

void tampilBulanan(Month M);
void tampilPekan(Month M, int pekan);
void tampilMatkul(Month M, const char matkul[]);

#endif
