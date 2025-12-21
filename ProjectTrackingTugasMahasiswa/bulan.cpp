#include "bulan.h"
#include <iostream>
using namespace std;

void inisialisasiSemuaBulan(Bulan daftarBulan[]) {
    const char namaBulan[JUMLAH_BULAN][20] = {
        "Januari", "Februari", "Maret", "April",
        "Mei", "Juni", "Juli", "Agustus",
        "September", "Oktober", "November", "Desember"
    };

    for (int i = 0; i < JUMLAH_BULAN; i++) {
        salinString(daftarBulan[i].namaBulan, namaBulan[i]);
        daftarBulan[i].root = NULL;

        for (int p = 1; p <= 4; p++) {
            daftarBulan[i].root = insertPekan(daftarBulan[i].root, p);
        }
    }
}

void muatDummyData(Bulan daftarBulan[]) {
    Pekan *p;
    MataKuliah *m;
    Tugas *t;

    // ===== JANUARI =====
    // Pekan 1
    p = cariPekan(daftarBulan[0].root, 1);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "strukturdata");

        t = new Tugas;
        salinString(t->namaTugas, "Quiz Linked List");
        salinString(t->jenisTugas, "Quiz");
        salinString(t->tenggatWaktu, "10 Jan");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // Pekan 2
    p = cariPekan(daftarBulan[0].root, 2);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistembasisdata");

        t = new Tugas;
        salinString(t->namaTugas, "ER Diagram");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "15 Jan");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // Pekan 3
    p = cariPekan(daftarBulan[0].root, 3);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistemoperasi");

        t = new Tugas;
        salinString(t->namaTugas, "Tugas Process");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "20 Jan");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // Pekan 4
    p = cariPekan(daftarBulan[0].root, 4);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "strukturdata");

        t = new Tugas;
        salinString(t->namaTugas, "UTS");
        salinString(t->jenisTugas, "Ujian");
        salinString(t->tenggatWaktu, "25 Jan");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;

    // ===== FEBRUARI =====
    p = cariPekan(daftarBulan[1].root, 2);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "teoribahasaautomata");

        t = new Tugas;
        salinString(t->namaTugas, "CFG Parsing");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "18 Feb");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== MARET =====
    p = cariPekan(daftarBulan[2].root, 3);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistemoperasi");

        t = new Tugas;
        salinString(t->namaTugas, "CPU Scheduling");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "20 Mar");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== APRIL =====
    p = cariPekan(daftarBulan[3].root, 1);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistembasisdata");

        t = new Tugas;
        salinString(t->namaTugas, "Normalisasi");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "8 Apr");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== MEI =====
    p = cariPekan(daftarBulan[4].root, 4);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "strukturdata");

        t = new Tugas;
        salinString(t->namaTugas, "Tree & Graph");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "25 Mei");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== JUNI =====
    p = cariPekan(daftarBulan[5].root, 2);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "teoripeluang");

        t = new Tugas;
        salinString(t->namaTugas, "Distribusi Probabilitas");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "12 Jun");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== JULI =====
    p = cariPekan(daftarBulan[6].root, 3);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "teoribahasaautomata");

        t = new Tugas;
        salinString(t->namaTugas, "Pushdown Automata");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "22 Jul");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== AGUSTUS =====
    p = cariPekan(daftarBulan[7].root, 1);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistemoperasi");

        t = new Tugas;
        salinString(t->namaTugas, "Deadlock");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "9 Agu");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== SEPTEMBER =====
    p = cariPekan(daftarBulan[8].root, 2);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistembasisdata");

        t = new Tugas;
        salinString(t->namaTugas, "SQL Query");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "15 Sep");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== OKTOBER =====
    p = cariPekan(daftarBulan[9].root, 4);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "strukturdata");

        t = new Tugas;
        salinString(t->namaTugas, "Sorting & Searching");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "28 Okt");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== NOVEMBER =====
    p = cariPekan(daftarBulan[10].root, 3);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "teoripeluang");

        t = new Tugas;
        salinString(t->namaTugas, "Uji Hipotesis");
        salinString(t->jenisTugas, "Tugas");
        salinString(t->tenggatWaktu, "20 Nov");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }

    // ===== DESEMBER =====
    p = cariPekan(daftarBulan[11].root, 2);
    if (p) {
        m = new MataKuliah;
        salinString(m->namaMatkul, "sistemoperasi");

        t = new Tugas;
        salinString(t->namaTugas, "Final Project");
        salinString(t->jenisTugas, "Proyek");
        salinString(t->tenggatWaktu, "15 Des");
        t->berikutnya = NULL;

        m->daftarTugas = t;
        m->berikutnya = p->daftarMatkul;
        p->daftarMatkul = m;
    }
}
}
