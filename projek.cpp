#include "TaskTree.h"
#include <cstring>

// -------------------------------------
// Inisialisasi Tree
// -------------------------------------
void initTree(Month &M, const char nama[]) {
    strcpy(M.namaBulan, nama);

    M.listWeek = NULL;

    // buat pekan 1–4
    Week *last = NULL;
    for (int i = 1; i <= 4; i++) {
        Week *w = new Week;
        w->mingguKe = i;
        w->listCourse = NULL;
        w->next = NULL;

        if (M.listWeek == NULL)
            M.listWeek = w;
        else
            last->next = w;

        last = w;
    }
}

// -------------------------------------
// Tambah Tugas
// -------------------------------------
void tambahTugas(Month &M, int pekan,
                 const char matkul[],
                 const char namaTugas[],
                 const char jenis[],
                 const char deadline[]) {

    // cari node pekan
    Week *w = M.listWeek;
    while (w != NULL) {
        if (w->mingguKe == pekan) break;
        w = w->next;
    }
    if (w == NULL) return;

    // cari matkul
    Course *c = w->listCourse;
    Course *lastCourse = NULL;
    while (c != NULL) {
        if (strcmp(c->namaMatkul, matkul) == 0) break;
        lastCourse = c;
        c = c->next;
    }

    // jika matkul belum ada → buat
    if (c == NULL) {
        c = new Course;
        strcpy(c->namaMatkul, matkul);
        c->listTask = NULL;
        c->next = NULL;

        if (w->listCourse == NULL)
            w->listCourse = c;
        else
            lastCourse->next = c;
    }

    // buat task baru
    Task *t = new Task;
    strcpy(t->namaTugas, namaTugas);
    strcpy(t->jenisTugas, jenis);
    strcpy(t->deadline, deadline);
    t->next = NULL;

    // insert ke akhir list tugas
    if (c->listTask == NULL)
        c->listTask = t;
    else {
        Task *temp = c->listTask;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = t;
    }
}

// -------------------------------------
// Tampilkan Tugas Bulanan
// -------------------------------------
void tampilBulanan(Month M) {
    cout << "\n=== DAFTAR TUGAS BULAN " << M.namaBulan << " ===\n";

    Week *w = M.listWeek;
    while (w != NULL) {
        cout << "\n-- Pekan " << w->mingguKe << " --\n";

        Course *c = w->listCourse;
        while (c != NULL) {
            cout << "Mata Kuliah: " << c->namaMatkul << "\n";

            Task *t = c->listTask;
            while (t != NULL) {
                cout << " - " << t->namaTugas
                     << " (" << t->jenisTugas
                     << "), Deadline: " << t->deadline << "\n";
                t = t->next;
            }

            c = c->next;
        }

        w = w->next;
    }
}

// -------------------------------------
// Tugas berdasarkan pekan
// -------------------------------------
void tampilPekan(Month M, int pekan) {
    Week *w = M.listWeek;
    while (w != NULL && w->mingguKe != pekan)
        w = w->next;

    if (w == NULL) {
        cout << "Pekan tidak ditemukan!\n";
        return;
    }

    cout << "\n=== TUGAS PEKAN " << pekan << " ===\n";

    Course *c = w->listCourse;
    while (c != NULL) {
        cout << "Mata Kuliah: " << c->namaMatkul << "\n";

        Task *t = c->listTask;
        while (t != NULL) {
            cout << " - " << t->namaTugas
                 << " (" << t->jenisTugas
                 << "), Deadline: " << t->deadline << "\n";
            t = t->next;
        }

        c = c->next;
    }
}

// -------------------------------------
// Semua tugas per mata kuliah (1 bulan)
// -------------------------------------
void tampilMatkul(Month M, const char matkul[]) {
    cout << "\n=== TUGAS MATA KULIAH " << matkul << " ===\n";

    Week *w = M.listWeek;
    while (w != NULL) {

        Course *c = w->listCourse;
        while (c != NULL) {
            if (strcmp(c->namaMatkul, matkul) == 0) {

                Task *t = c->listTask;
                while (t != NULL) {
                    cout << "Pekan " << w->mingguKe << " → "
                         << t->namaTugas
                         << " (" << t->jenisTugas
                         << "), Deadline: " << t->deadline << "\n";
                    t = t->next;
                }
            }
            c = c->next;
        }

        w = w->next;
    }
}
