#ifndef TASKTREE_H
#define TASKTREE_H

#include <iostream>
using namespace std;

struct Task {
    char namaTugas[50];
    char jenisTugas[20];
    char deadline[20];
    Task *next;
};

struct Course {
    char namaMatkul[50];
    Task *listTask;
    Course *next;
};

struct Week {
    int mingguKe;
    Course *listCourse;
    Week *next;
};

struct Month {
    char namaBulan[20];
    Week *listWeek;
};

void initTree(Month &M, const char nama[]);
void tambahTugas(Month &M, int pekan, const char matkul[], const char namaTugas[], const char jenis[], const char deadline[]);
void tampilBulanan(Month M);
void tampilPekan(Month M, int pekan);
void tampilMatkul(Month M, const char matkul[]);

#endif
