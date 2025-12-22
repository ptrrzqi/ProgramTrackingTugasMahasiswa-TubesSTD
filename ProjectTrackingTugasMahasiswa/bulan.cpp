#include "bulan.h"
#include <iostream>
using namespace std;

//data mata kuliah yang tersedia
const char* DAFTAR_MATKUL[] = {
    "strukturdata",
    "teoripeluang",
    "sistembasisdata",
    "teoribahasaautomata",
    "sistemoperasi"
};

//fungsi menginisialisasi semua bulan
void initSemuaBulan(Bulan bulan[]) {
    const char* namaBulan[] = {
        "Januari", "Februari", "Maret", "April",
        "Mei", "Juni", "Juli", "Agustus",
        "September", "Oktober", "November", "Desember"
    };

    for (int i = 0; i < JUMLAH_BULAN; i++) {
        initBulan(bulan[i], namaBulan[i]);
    }
}

//fungsi mengisi data dummy untuk semua bulan
void isiDataDummy(Bulan bulan[]) {
    //januari
    tambahDataKeBulan(bulan[0], 1, "strukturdata", "Quiz Linked List", "Quiz", "10 Jan");
    tambahDataKeBulan(bulan[0], 1, "sistembasisdata", "Pengenalan DBMS", "Tugas", "12 Jan");

    tambahDataKeBulan(bulan[0], 2, "sistembasisdata", "ER Diagram", "Tugas", "15 Jan");
    tambahDataKeBulan(bulan[0], 2, "sistemoperasi", "Process Management", "Quiz", "18 Jan");

    tambahDataKeBulan(bulan[0], 3, "sistemoperasi", "Tugas Process", "Tugas", "20 Jan");
    tambahDataKeBulan(bulan[0], 3, "teoripeluang", "Probabilitas Dasar", "Tugas", "22 Jan");

    tambahDataKeBulan(bulan[0], 4, "strukturdata", "UTS", "Ujian", "25 Jan");
    tambahDataKeBulan(bulan[0], 4, "teoribahasaautomata", "Finite Automata", "Tugas", "28 Jan");

    //februari
    tambahDataKeBulan(bulan[1], 1, "teoripeluang", "Distribusi Normal", "Tugas", "5 Feb");
    tambahDataKeBulan(bulan[1], 1, "strukturdata", "Stack & Queue", "Tugas", "8 Feb");

    tambahDataKeBulan(bulan[1], 2, "teoribahasaautomata", "CFG Parsing", "Tugas", "18 Feb");
    tambahDataKeBulan(bulan[1], 2, "sistembasisdata", "Normalisasi 1NF", "Tugas", "20 Feb");

    tambahDataKeBulan(bulan[1], 3, "strukturdata", "Binary Tree", "Tugas", "22 Feb");
    tambahDataKeBulan(bulan[1], 3, "sistemoperasi", "Thread Management", "Tugas", "25 Feb");

    //maret
    tambahDataKeBulan(bulan[2], 1, "sistemoperasi", "Process Scheduling", "Quiz", "5 Mar");
    tambahDataKeBulan(bulan[2], 1, "teoripeluang", "Distribusi Binomial", "Tugas", "8 Mar");

    tambahDataKeBulan(bulan[2], 2, "sistembasisdata", "Normalisasi 1NF", "Tugas", "12 Mar");
    tambahDataKeBulan(bulan[2], 2, "strukturdata", "Graph Traversal", "Tugas", "15 Mar");

    tambahDataKeBulan(bulan[2], 3, "sistemoperasi", "CPU Scheduling", "Tugas", "20 Mar");
    tambahDataKeBulan(bulan[2], 3, "teoribahasaautomata", "Pushdown Automata", "Tugas", "22 Mar");

    tambahDataKeBulan(bulan[2], 4, "teoripeluang", "Distribusi Diskrit", "Tugas", "28 Mar");
    tambahDataKeBulan(bulan[2], 4, "sistembasisdata", "SQL DML", "Tugas", "30 Mar");

    //april
    tambahDataKeBulan(bulan[3], 1, "sistembasisdata", "Normalisasi", "Tugas", "8 Apr");
    tambahDataKeBulan(bulan[3], 1, "strukturdata", "Hash Table", "Tugas", "10 Apr");

    tambahDataKeBulan(bulan[3], 2, "teoribahasaautomata", "Pushdown Automata", "Tugas", "15 Apr");
    tambahDataKeBulan(bulan[3], 2, "sistemoperasi", "Memory Management", "Tugas", "18 Apr");

    tambahDataKeBulan(bulan[3], 3, "strukturdata", "Graph Traversal", "Tugas", "22 Apr");
    tambahDataKeBulan(bulan[3], 3, "teoripeluang", "Regresi Linear", "Tugas", "25 Apr");

    //mei
    tambahDataKeBulan(bulan[4], 1, "sistemoperasi", "Memory Management", "Quiz", "3 Mei");
    tambahDataKeBulan(bulan[4], 1, "teoripeluang", "Uji Hipotesis", "Tugas", "5 Mei");

    tambahDataKeBulan(bulan[4], 2, "teoripeluang", "Uji Hipotesis", "Tugas", "10 Mei");
    tambahDataKeBulan(bulan[4], 2, "sistembasisdata", "Indexing", "Tugas", "12 Mei");

    tambahDataKeBulan(bulan[4], 3, "sistembasisdata", "SQL Query", "Tugas", "18 Mei");
    tambahDataKeBulan(bulan[4], 3, "strukturdata", "AVL Tree", "Tugas", "20 Mei");

    tambahDataKeBulan(bulan[4], 4, "strukturdata", "Tree & Graph", "Tugas", "25 Mei");
    tambahDataKeBulan(bulan[4], 4, "sistemoperasi", "File System", "Tugas", "28 Mei");

    //juni
    tambahDataKeBulan(bulan[5], 1, "teoribahasaautomata", "Turing Machine", "Tugas", "5 Jun");
    tambahDataKeBulan(bulan[5], 1, "strukturdata", "Sorting Review", "Tugas", "8 Jun");

    tambahDataKeBulan(bulan[5], 2, "teoripeluang", "Distribusi Probabilitas", "Tugas", "12 Jun");
    tambahDataKeBulan(bulan[5], 2, "sistemoperasi", "Virtual Memory", "Tugas", "15 Jun");

    tambahDataKeBulan(bulan[5], 3, "sistemoperasi", "Deadlock", "Tugas", "20 Jun");
    tambahDataKeBulan(bulan[5], 3, "sistembasisdata", "Transaction", "Tugas", "22 Jun");

    //juli
    tambahDataKeBulan(bulan[6], 1, "strukturdata", "Sorting Algorithm", "Tugas", "5 Jul");
    tambahDataKeBulan(bulan[6], 1, "teoripeluang", "ANOVA", "Tugas", "8 Jul");

    tambahDataKeBulan(bulan[6], 2, "sistembasisdata", "Transaction", "Tugas", "12 Jul");
    tambahDataKeBulan(bulan[6], 2, "sistemoperasi", "I/O Management", "Tugas", "15 Jul");

    tambahDataKeBulan(bulan[6], 3, "teoribahasaautomata", "Pushdown Automata", "Tugas", "22 Jul");
    tambahDataKeBulan(bulan[6], 3, "strukturdata", "Dynamic Programming", "Tugas", "25 Jul");

    tambahDataKeBulan(bulan[6], 4, "teoripeluang", "Regresi Linear", "Tugas", "30 Jul");
    tambahDataKeBulan(bulan[6], 4, "sistembasisdata", "Concurrency", "Tugas", "31 Jul");

    //agustus
    tambahDataKeBulan(bulan[7], 1, "sistemoperasi", "Deadlock", "Tugas", "9 Agu");
    tambahDataKeBulan(bulan[7], 1, "teoribahasaautomata", "Regular Expression", "Tugas", "12 Agu");

    tambahDataKeBulan(bulan[7], 2, "strukturdata", "Dynamic Programming", "Tugas", "16 Agu");
    tambahDataKeBulan(bulan[7], 2, "teoripeluang", "Time Series", "Tugas", "18 Agu");

    tambahDataKeBulan(bulan[7], 3, "sistembasisdata", "Indexing", "Tugas", "24 Agu");
    tambahDataKeBulan(bulan[7], 3, "sistemoperasi", "Security", "Tugas", "26 Agu");

    //september
    tambahDataKeBulan(bulan[8], 1, "teoripeluang", "ANOVA", "Tugas", "4 Sep");
    tambahDataKeBulan(bulan[8], 1, "strukturdata", "Greedy Algorithm", "Tugas", "7 Sep");

    tambahDataKeBulan(bulan[8], 2, "sistembasisdata", "SQL Query", "Tugas", "15 Sep");
    tambahDataKeBulan(bulan[8], 2, "sistemoperasi", "Networking", "Tugas", "18 Sep");

    tambahDataKeBulan(bulan[8], 3, "teoribahasaautomata", "Regular Expression", "Tugas", "22 Sep");
    tambahDataKeBulan(bulan[8], 3, "teoripeluang", "Sampling", "Tugas", "25 Sep");

    tambahDataKeBulan(bulan[8], 4, "sistemoperasi", "File System", "Tugas", "30 Sep");
    tambahDataKeBulan(bulan[8], 4, "strukturdata", "Backtracking", "Tugas", "30 Sep");

    //oktober
    tambahDataKeBulan(bulan[9], 1, "strukturdata", "Hash Table", "Tugas", "7 Okt");
    tambahDataKeBulan(bulan[9], 1, "sistembasisdata", "NoSQL Intro", "Tugas", "10 Okt");

    tambahDataKeBulan(bulan[9], 2, "teoripeluang", "Time Series", "Tugas", "14 Okt");
    tambahDataKeBulan(bulan[9], 2, "teoribahasaautomata", "Context Free", "Tugas", "16 Okt");

    tambahDataKeBulan(bulan[9], 3, "sistemoperasi", "Virtual Memory", "Tugas", "21 Okt");
    tambahDataKeBulan(bulan[9], 3, "strukturdata", "Segment Tree", "Tugas", "23 Okt");

    tambahDataKeBulan(bulan[9], 4, "strukturdata", "Sorting & Searching", "Tugas", "28 Okt");
    tambahDataKeBulan(bulan[9], 4, "sistemoperasi", "Distributed OS", "Tugas", "30 Okt");

    //november
    tambahDataKeBulan(bulan[10], 1, "sistembasisdata", "NoSQL Database", "Tugas", "5 Nov");
    tambahDataKeBulan(bulan[10], 1, "teoripeluang", "Machine Learning", "Tugas", "8 Nov");

    tambahDataKeBulan(bulan[10], 2, "teoribahasaautomata", "Context Free", "Tugas", "12 Nov");
    tambahDataKeBulan(bulan[10], 2, "strukturdata", "Trie", "Tugas", "15 Nov");

    tambahDataKeBulan(bulan[10], 3, "teoripeluang", "Uji Hipotesis", "Tugas", "20 Nov");
    tambahDataKeBulan(bulan[10], 3, "sistemoperasi", "Cloud Computing", "Tugas", "22 Nov");

    tambahDataKeBulan(bulan[10], 4, "sistemoperasi", "Final Project", "Proyek", "28 Nov");
    tambahDataKeBulan(bulan[10], 4, "strukturdata", "Final Review", "Tugas", "30 Nov");

    //desember
    tambahDataKeBulan(bulan[11], 1, "strukturdata", "Final Exam", "Ujian", "5 Des");
    tambahDataKeBulan(bulan[11], 1, "teoripeluang", "Final Review", "Tugas", "7 Des");

    tambahDataKeBulan(bulan[11], 2, "sistemoperasi", "Final Project", "Proyek", "15 Des");
    tambahDataKeBulan(bulan[11], 2, "sistembasisdata", "Final Project", "Proyek", "17 Des");

    tambahDataKeBulan(bulan[11], 3, "teoripeluang", "Final Exam", "Ujian", "20 Des");
    tambahDataKeBulan(bulan[11], 3, "teoribahasaautomata", "Final Project", "Proyek", "22 Des");
}

//fungsi mengisi data contoh untuk bulan tertentu
void isiDataContoh(Bulan& bulan) {
    //data contoh bulan Januari (untuk fitur pencarian)
    tambahDataKeBulan(bulan, 1, "strukturdata", "Quiz Linked List", "Quiz", "10 Jan");
    tambahDataKeBulan(bulan, 1, "strukturdata", "Tugas Stack", "Tugas", "12 Jan");

    tambahDataKeBulan(bulan, 2, "sistembasisdata", "ER Diagram", "Tugas", "15 Jan");
    tambahDataKeBulan(bulan, 2, "sistembasisdata", "Normalisasi", "Tugas", "18 Jan");

    tambahDataKeBulan(bulan, 3, "sistemoperasi", "Tugas Process", "Tugas", "20 Jan");
    tambahDataKeBulan(bulan, 3, "sistemoperasi", "CPU Scheduling", "Tugas", "22 Jan");

    tambahDataKeBulan(bulan, 4, "strukturdata", "UTS", "Ujian", "25 Jan");
    tambahDataKeBulan(bulan, 4, "teoripeluang", "Probabilitas", "Tugas", "28 Jan");
    tambahDataKeBulan(bulan, 4, "teoribahasaautomata", "Finite Automata", "Tugas", "30 Jan");
}
