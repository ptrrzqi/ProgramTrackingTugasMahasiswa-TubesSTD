#include <iostream>
#include "projek.h"
using namespace std;

int main() {
    cout << "========================================\n";
    cout << "    Program MANAJEMEN TUGAS KULIAH\n";
    cout << "========================================\n";

    Bulan jadwal;
    inisialisasiPohon(jadwal);

    muatDataTugas(jadwal);

    int pilihan;

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Lihat Semua Tugas Bulanan\n";
        cout << "2. Lihat Tugas per-Pekan\n";
        cout << "3. Lihat Tugas per-Mata Kuliah\n";
        cout << "4. Lihat Daftar Mata Kuliah\n";
        cout << "0. Keluar Program\n";
        cout << "Pilihan Anda: ";

        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                tampilkanBulanan(jadwal);
                break;
            }

            case 2: {
                int p;
                cout << "\nMasukkan nomor pekan (1-4): ";
                cin >> p;

                if (p < 1 || p > 4) {
                    cout << "Pilih antara pekan 1-4!\n";
                } else {
                    tampilkanPekanan(jadwal, p);
                }
                break;
            }

            case 3: {
                char mk[50];
                cout << "\nNama mata kuliah (huruf kecil tanpa spasi): ";
                cin >> mk;
                tampilkanPerMatkul(jadwal, mk);
                break;
            }

            case 4: {
                tampilkanDaftarMatkul();
                break;
            }

            case 0: {
                cout << "\nKeluar dari program...\n";
                break;
            }

            default: {
                cout << "Pilihan tidak valid!, pilih nomor 0-4.\n";
                break;
            }
        }

    } while (pilihan != 0);

    cout << "\n========================================\n";
    cout << "   Terima kasih telah menggunakan\n";
    cout << "   Program Manajemen Tugas Kuliah\n";
    cout << "========================================\n";

    return 0;
}
