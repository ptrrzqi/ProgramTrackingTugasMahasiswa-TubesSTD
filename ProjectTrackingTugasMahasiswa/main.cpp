#include "projek.h"
#include "bulan.h"
#include <iostream>
using namespace std;

int main()
{
    // Inisialisasi semua bulan
    Bulan semuaBulan[JUMLAH_BULAN];
    initSemuaBulan(semuaBulan);

    // Isi data dummy untuk semua bulan
    isiDataDummy(semuaBulan);

    // Inisialisasi bulan contoh untuk fitur pencarian
    Bulan bulanContoh;
    initBulan(bulanContoh, "Januari");
    isiDataContoh(bulanContoh);

    int pilihan;
    bool running = true;

    while (running)
    {
        tampilkanMenuUtama();
        cin >> pilihan;

        switch(pilihan)
        {
            case 1:
            {
                // Tampilkan semua bulan
                clearScreen();

                cout << "MENAMPILKAN SEMUA TUGAS 12 BULAN\n\n";

                for (int i = 0; i < JUMLAH_BULAN; i++)
                {
                    tampilkanBulanLengkap(semuaBulan[i]);
                    cout << endl;
                }

                pauseProgram();
                clearScreen();

                break;
            }

            case 2:
            {
                // Tampilkan tugas per pekan
                clearScreen();

                cout << "PILIH BULAN DAN PEKAN\n\n";

                cout << "Daftar Bulan:\n";
                cout << "-------------\n";

                for (int i = 0; i < JUMLAH_BULAN; i++)
                {
                    cout << "  " << i + 1 << ". " << semuaBulan[i].nama << endl;
                }

                cout << "\nMasukkan nomor bulan (1-12): ";

                int bulanPilihan;
                cin >> bulanPilihan;

                if (bulanPilihan < 1 || bulanPilihan > 12)
                {
                    cout << "\nPilihan bulan tidak valid!\n";
                    pauseProgram();
                    clearScreen();
                    break;
                }

                cout << "Masukkan nomor pekan (1-4): ";

                int pekanPilihan;
                cin >> pekanPilihan;

                if (pekanPilihan < 1 || pekanPilihan > 4)
                {
                    cout << "\nPilihan pekan tidak valid!\n";
                    pauseProgram();
                    clearScreen();
                    break;
                }

                clearScreen();
                tampilkanPekanTertentu(semuaBulan[bulanPilihan - 1], pekanPilihan);

                pauseProgram();
                clearScreen();

                break;
            }

            case 3:
            {
                clearScreen();
                cout << "CARI TUGAS PER MATA KULIAH\n\n";

                cout << "Pilih Mata Kuliah:\n";
                cout << "------------------\n";
                cout << "1. strukturdata\n";
                cout << "2. teoripeluang\n";
                cout << "3. sistembasisdata\n";
                cout << "4. teoribahasaautomata\n";
                cout << "5. sistemoperasi\n";
                cout << "------------------\n";
                cout << "Masukkan nomor mata kuliah (1-5): ";

                int matkulPilihan;
                cin >> matkulPilihan;

                if (matkulPilihan < 1 || matkulPilihan > 5)
                {
                    cout << "\nPilihan mata kuliah tidak valid!\n";
                    pauseProgram();
                    clearScreen();
                    break;
                }

                char matkul[50];
                switch(matkulPilihan)
                {
                    case 1: salinString(matkul, "strukturdata"); break;
                    case 2: salinString(matkul, "teoripeluang"); break;
                    case 3: salinString(matkul, "sistembasisdata"); break;
                    case 4: salinString(matkul, "teoribahasaautomata"); break;
                    case 5: salinString(matkul, "sistemoperasi"); break;
                }

                cout << "\nPilih Bulan:\n";
                cout << "------------\n";

                for (int i = 0; i < JUMLAH_BULAN; i++)
                {
                    cout << "  " << i + 1 << ". " << semuaBulan[i].nama << endl;
                }

                cout << "\nMasukkan nomor bulan (1-12): ";
                int bulanPilihan;
                cin >> bulanPilihan;

                if (bulanPilihan < 1 || bulanPilihan > 12)
                {
                    cout << "\nPilihan bulan tidak valid!\n";
                    pauseProgram();
                    clearScreen();
                    break;
                }

                clearScreen();
                cariTugasPerMataKuliah(semuaBulan[bulanPilihan - 1], matkul);

                pauseProgram();
                clearScreen();
                break;
            }

            case 4:
            {
                // Daftar mata kuliah
                clearScreen();
                tampilkanDaftarMataKuliah();

                pauseProgram();
                clearScreen();

                break;
            }

            case 5:
            {
                clearScreen();
                cout << "DELETE TUGAS\n\n";

                cout << "Pilih Bulan:\n";
                for (int i = 0; i < JUMLAH_BULAN; i++)
                    cout << "  " << i + 1 << ". " << semuaBulan[i].nama << endl;

                int bulanPilihan;
                cout << "\nMasukkan nomor bulan (1-12): ";
                cin >> bulanPilihan;

                if (bulanPilihan < 1 || bulanPilihan > 12) {
                    cout << "\nPilihan bulan tidak valid!\n";
                    pauseProgram();
                    clearScreen();
                    break;
                }

                clearScreen();
                deleteTugasFromBulan(semuaBulan[bulanPilihan - 1]);

                pauseProgram();
                clearScreen();
                break;
            }

            case 0:
            {
                // Keluar program
                cout << "\nTerima kasih telah menggunakan program!\n";
                cout << "   Program ditutup...\n\n";

                running = false;

                break;
            }

            default:
            {
                cout << "\nPilihan tidak valid! Silakan pilih 0-4.\n";
                pauseProgram();
                clearScreen();
            }
        }
    }

    // Membersihkan memory
    for (int i = 0; i < JUMLAH_BULAN; i++)
    {
        hapusSemuaPekan(semuaBulan[i].pekan);
    }

    hapusSemuaPekan(bulanContoh.pekan);

    return 0;
}
