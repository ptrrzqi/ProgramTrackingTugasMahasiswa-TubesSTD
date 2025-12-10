#include <iostream>
#include "TaskTree.h"
using namespace std;

int main() {

    Month jadwal;
    initTree(jadwal, "Januari");

    int pilih;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Tugas Bulanan\n";
        cout << "3. Lihat Tugas Pekanan\n";
        cout << "4. Lihat Tugas Per Mata Kuliah\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            int pekan;
            char matkul[50], nama[50], jenis[20], deadline[20];

            cout << "Masukkan pekan (1-4): ";
            cin >> pekan;
            cin.ignore();

            cout << "Mata Kuliah: ";
            cin.getline(matkul, 50);

            cout << "Nama Tugas: ";
            cin.getline(nama, 50);

            cout << "Jenis Tugas: ";
            cin.getline(jenis, 20);

            cout << "Deadline: ";
            cin.getline(deadline, 20);

            tambahTugas(jadwal, pekan, matkul, nama, jenis, deadline);

        } else if (pilih == 2) {
            tampilBulanan(jadwal);

        } else if (pilih == 3) {
            int p;
            cout << "Masukkan pekan: ";
            cin >> p;
            tampilPekan(jadwal, p);

        } else if (pilih == 4) {
            char mk[50];
            cout << "Nama Matkul: ";
            cin.ignore();
            cin.getline(mk, 50);
            tampilMatkul(jadwal, mk);
        }

    } while (pilih != 0);

    return 0;
}
