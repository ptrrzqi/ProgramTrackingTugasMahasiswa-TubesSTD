#include <iostream>
#include "projek.h"
#include "bulan.h"

using namespace std;

int main() {
    cout << "========================================\n";
    cout << "    Program MANAJEMEN TUGAS KULIAH\n";
    cout << "========================================\n";

    Bulan jadwal;
    inisialisasiPohon(jadwal);
    Bulan daftarBulan[JUMLAH_BULAN];
    inisialisasiSemuaBulan(daftarBulan);
    muatDummyData(daftarBulan);
    muatDataTugas(jadwal);

    int pilihan = -1;

    while (pilihan != 0) {
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
                for (int i = 0; i < 12; i++) {
                    cout << endl;
                    tampilkanBulananRapi(daftarBulan[i]);
                    cout << endl;
                }
                break;
            }

            case 2: {
                cout << "\n=== Pilih Bulan ===\n";
                for (int i = 0; i < 12; i++) {
                    cout << i+1 << ". " << daftarBulan[i].namaBulan << "\n";
                }

                int bulanPilihan;
                cout << "Masukkan nomor bulan (1-12): ";
                cin >> bulanPilihan;

                if (bulanPilihan < 1 || bulanPilihan > 12) {
                    cout << "Pilih antara bulan 1-12!\n";
                    break;
                }

                int pekanPilihan;
                cout << "Masukkan nomor pekan (1-4): ";
                cin >> pekanPilihan;

                if (pekanPilihan < 1 || pekanPilihan > 4) {
                    cout << "Pilih antara pekan 1-4!\n";
                } else {
                    tampilkanPekanan(daftarBulan[bulanPilihan - 1], pekanPilihan);
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

    };

    cout << "\n========================================\n";
    cout << "   Terima kasih telah menggunakan\n";
    cout << "   Program Manajemen Tugas Kuliah\n";
    cout << "========================================\n";

    return 0;
}
