#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fungsi.h"

struct peserta{
    char nama[30];
    char nohp[20];
    int sudahBayar;      
    int lapak;           
    int beliKopi;   
    int beliMie;
    int jumlahIkan;      
    int beratIkan;       
};
struct peserta data[30];
int noPeserta = 0;


//TAMBAH DATA
void tambahPeserta(){
    char lagi;
    do{
        system("cls");
        printf("=== Input Peserta ===\n");
        printf("Nama : ");
        scanf(" %[^\n]", data[noPeserta].nama);
        printf("No HP: ");
        scanf(" %[^\n]", data[noPeserta].nohp);

        data[noPeserta].sudahBayar = 0;
        data[noPeserta].lapak = 0;
        data[noPeserta].beliKopi = 0;
        data[noPeserta].beliMie = 0;
        data[noPeserta].jumlahIkan = 0;
        data[noPeserta].beratIkan = 0;
        noPeserta++;

        printf("Input lagi? (y/n): ");
        getchar();
        lagi = getchar();
        getchar();
    }while(lagi=='y' || lagi=='Y');
    }

//MENU DALAM LIHAT PESERTA
void menuLihatPeserta() {
    int pilih;
    do {
        system("cls");
        printf("======= LIHAT PESERTA =======\n");
        printf("Total peserta: %d\n\n", noPeserta);
        printf("1. Tampilkan daftar asli\n");
        printf("2. Urutkan berdasarkan nama (A-Z)\n");
        printf("3. Urutkan berdasarkan nomor lapak\n");
        printf("4. Cari peserta\n");
        printf("5. Kembali\n");
        printf("Pilih: ");
        scanf("%d",&pilih);
        getchar(); // buang newline

        struct peserta temp[30]; // array sementara untuk sorting
        memcpy(temp, data, sizeof(data));

        switch(pilih) {
            case 1:
                lihatPeserta();break;
            case 2: // sort nama A-Z
                 sortDataNama();break;
            case 3: // sort lapak
               sortDataLapak();break;
            case 4:
                cariPeserta();break;;
            case 5:
                printf("Kembali ke menu utama...\n");break;
            default:
                printf("Pilihan tidak valid!\n");
                continue; // kembali ke menu pilihan
        }
        
    } while(pilih != 5);
}

//LIHAT PESERTA
void lihatPeserta() {
    system("cls");

    if(noPeserta == 0){
        printf("Belum ada peserta...\n");
    }
    else{
        printf("====================== DATA PESERTA ======================\n");
        printf("Total peserta: %d\n\n", noPeserta);

        printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
        printf("------------------------------------------------------------\n");

        for(int i = 0; i < noPeserta; i++){
            printf("%-3d %-20s %-15s %-10s %-5d\n",
                i+1,
                data[i].nama,
                data[i].nohp,
                data[i].sudahBayar ? "Lunas" : "Belum",
                data[i].lapak
            );
        }

        printf("=============================================================\n");
    
    }
    printf("\nTekan ENTER untuk kembali ke menu...");
    getchar();
}

// FITUR SORTING NAMA (Bubble Sort A-Z)
void sortDataNama() {
    struct peserta temp; // Variabel sementara untuk menukar data

    // Algoritma Bubble Sort
    for (int i = 0; i < noPeserta - 1; i++) {
        for (int j = 0; j < noPeserta - i - 1; j++) {
            // Bandingkan nama sekarang dengan nama depannya
            // strcmp > 0 artinya nama data[j] hurufnya lebih "besar" (misal B vs A)
            if (strcmp(data[j].nama, data[j + 1].nama) > 0) {
                // Tukar posisi seluruh struct
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("\nData berhasil diurutkan berdasarkan Nama (A-Z)!\n");
    // Langsung tampilkan hasilnya supaya user tahu
    lihatPeserta(); 
}

//FITUR SEARCH
void cariPeserta() {
    int pilih;
    do {
        system("cls");
        printf("======= SEARCH PESERTA =======\n");
        printf("1. Cari berdasarkan Nama\n");
        printf("2. Cari berdasarkan Lapak\n");
        printf("3. Kembali\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        getchar(); // buang newline

        if (pilih == 1) {
            char keyword[30];
            printf("Masukkan nama yang dicari: ");
            scanf(" %[^\n]", keyword);
            getchar();

            printf("\n--- Hasil pencarian Nama '%s' ---\n", keyword);
            printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
            printf("-------------------------------------------------------------\n");

            int found = 0;
            for (int i = 0; i < noPeserta; i++) {
                if (strstr(data[i].nama, keyword) != NULL) {
                    printf("%-3d %-20s %-15s %-10s %-5d\n",
                        i + 1,
                        data[i].nama,
                        data[i].nohp,
                        data[i].sudahBayar ? "Lunas" : "Belum",
                        data[i].lapak
                    );
                    found++;
                }
            }
            if (found == 0) {
                printf("Peserta tidak ditemukan.\n");
            }

        } 
        else if (pilih == 2) {
            int lap;
            printf("Masukkan nomor lapak yang dicari: ");
            scanf("%d", &lap);
            getchar();

            printf("\n--- Hasil pencarian Lapak %d ---\n", lap);
            printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
            printf("-------------------------------------------------------------\n");

            int found = 0;
            for (int i = 0; i < noPeserta; i++) {
                if (data[i].lapak == lap) {
                    printf("%-3d %-20s %-15s %-10s %-5d\n",
                        i + 1,
                        data[i].nama,
                        data[i].nohp,
                        data[i].sudahBayar ? "Lunas" : "Belum",
                        data[i].lapak
                    );
                    found++;
                }
            }
            if (found == 0) {
                printf("Peserta di lapak %d tidak ditemukan.\n", lap);
            }

        } 
        else if (pilih == 3) {
            printf("Kembali ke menu utama...\n");
        } 
        else {
            printf("Pilihan tidak valid!\n");
        }

        if (pilih >= 1 && pilih <= 2) {
            printf("\nTekan ENTER untuk kembali ke menu search...");
            while(getchar() != '\n');
            getchar();
        }

    } while(pilih != 3);
}

//FITUR ACAK LAPAK
void acakLapak() {
    // Cek dulu ada peserta atau tidak
    if (noPeserta == 0) {
        printf("Belum ada peserta!\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }

    // 1. SIAPKAN DAFTAR LAPAK
    // Kita tulis manual urutannya: Ganjil dulu (supaya ada jarak), baru Genap.
    // Kiri (1-14)
    int kolamKiri[14] = {1, 3, 5, 7, 9, 11, 13, 2, 4, 6, 8, 10, 12, 14};
    // Kanan (15-28)
    int kolamKanan[14] = {15, 17, 19, 21, 23, 25, 27, 16, 18, 20, 22, 24, 26, 28};

    srand(time(0)); // Reset pengacak waktu

    // 2. ACAK (SHUFFLE) ARRAY KIRI
    for(int i = 0; i < 14; i++) {
        int acak = rand() % 14; 
        // Tukar posisi i dengan posisi acak
        int temp = kolamKiri[i];
        kolamKiri[i] = kolamKiri[acak];
        kolamKiri[acak] = temp;
    }

    // 3. ACAK (SHUFFLE) ARRAY KANAN
    for(int i = 0; i < 14; i++) {
        int acak = rand() % 14;
        // Tukar posisi i dengan posisi acak
        int temp = kolamKanan[i];
        kolamKanan[i] = kolamKanan[acak];
        kolamKanan[acak] = temp;
    }

    // 4. BAGIKAN KE PESERTA (Seling-seling Kiri-Kanan)
    int hitungKiri = 0;  // Penghitung urutan kiri
    int hitungKanan = 0; // Penghitung urutan kanan

    system("cls");
    printf("=== HASIL KOCOK LAPAK ===\n\n");
    printf("%-20s %-10s %-10s\n", "NAMA", "LAPAK", "POSISI");
    printf("------------------------------------------\n");

    for(int i = 0; i < noPeserta; i++) {
        // Jika lapak sudah habis (lebih dari 28 orang)
        if (i >= 28) {
            printf("%-20s (Tidak kebagian tempat)\n", data[i].nama);
            data[i].lapak = 0; 
            continue;
        }

        // Logika Seling-Seling:
        // Kalau i genap (0, 2, 4...) -> Kasih Kiri
        // Kalau i ganjil (1, 3, 5...) -> Kasih Kanan
        
        if (i % 2 == 0) { 
            // Giliran KIRI
            data[i].lapak = kolamKiri[hitungKiri];
            printf("%-20s %-10d %-10s\n", data[i].nama, data[i].lapak, "Kiri");
            hitungKiri++;
        } 
        else {
            // Giliran KANAN
            data[i].lapak = kolamKanan[hitungKanan];
            printf("%-20s %-10d %-10s\n", data[i].nama, data[i].lapak, "Kanan");
            hitungKanan++;
        }
    }

    printf("\nSukses! Lapak sudah disimpan.\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();
}

//FITUR SORT BY LAPAK
void sortDataLapak() {
    struct peserta temp; // Variabel penampung sementara buat tukar tempat

    // Cek apakah ada data?
    if (noPeserta == 0) {
        printf("Belum ada data peserta.\n");
        return;
    }

    // Mulai Sorting (Bubble Sort)
    for (int i = 0; i < noPeserta - 1; i++) {
        for (int j = 0; j < noPeserta - i - 1; j++) {
            
            // Bandingkan: Kalau lapak sekarang lebih besar dari lapak depannya
            // Contoh: Lapak 5 ada di depan Lapak 2 -> TUKAR!
            if (data[j].lapak > data[j + 1].lapak) {
                
                // Proses tukar posisi (Swap)
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("\nData berhasil diurutkan berdasarkan Nomor Lapak (Terkecil -> Terbesar)!\n");
    // Langsung tampilkan hasilnya
    lihatPeserta(); 
}

//MENU KANTIN
void kantin() {
    int menu, nomor, jumlah;
    char lagi;

    do {
       system("cls");
        printf("=== WARUNG KANTIN ===\n\n");

        // 1. Tampilkan peserta
        printf("%-3s %-20s %-5s %-5s\n", "No", "Nama", "Kopi", "Mie");
        printf("-----------------------------------\n");
        for (int i = 0; i < noPeserta; i++) {
            printf("%-3d %-20s %-5d %-5d\n",
                i + 1,
                data[i].nama,
                data[i].beliKopi,
                data[i].beliMie
            );
        }

        printf("\nPilih Nomor Peserta (0 untuk kembali): ");
        scanf("%d", &nomor);
        getchar();

        if (nomor == 0) break;
        if (nomor < 1 || nomor > noPeserta) {
            printf("Nomor tidak valid!\n");
            getchar();
            continue;
        }

        int idx = nomor - 1;

        // 3. Menu kantin
        printf("\n--- Menu Kantin untuk %s ---\n", data[idx].nama);
        printf("1. Kopi (Rp 5.000)\n");
        printf("2. Mie  (Rp10.000)\n");
        printf("3. Batal\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);
        getchar();

        if (menu == 3) continue;
        printf("Jumlah beli: ");
        scanf("%d", &jumlah);
        getchar();

        if (menu == 1) {
            data[idx].beliKopi += jumlah;
            printf("Berhasil! %s membeli %d kopi.\n", data[idx].nama, jumlah);
        } 
        else if (menu == 2) {
            data[idx].beliMie += jumlah;
            printf("Berhasil! %s membeli %d mie.\n", data[idx].nama, jumlah);
        } 
        else {
            printf("Menu tidak valid!\n");
        }

        printf("\nTransaksi lain? (y/n): ");
        lagi = getchar();
        getchar();

    } while (lagi == 'y' || lagi == 'Y');
}

//MENU BAYAR
void pembayaran() {
    int pilih, uangBayar, totalTagihan, kembalian;
    char lanjut;

    do {
        system("cls");
        printf("=== KASIR PEMBAYARAN ===\n");
        printf("Harga Tiket: Rp 70.000/orang\n");
        printf("Harga Kopi : Rp  5.000/gelas\n\n");

        if (noPeserta == 0) {
            printf("Belum ada peserta.\n");
            printf("Tekan ENTER untuk kembali...");
            getchar();
            return;
        }

        // Tampilkan daftar tagihan
        printf("%-3s %-20s %-10s %-15s\n", "No", "Nama", "Total kopi", "Total mie", "Status");
        printf("----------------------------------------------------\n");
        for (int i = 0; i < noPeserta; i++) {
            printf("%-3d %-20s %-15d %-15d %-15s\n", 
                i + 1, 
                data[i].nama, 
                data[i].beliKopi,
                data[i].beliMie,
                data[i].sudahBayar ? "LUNAS" : "BELUM BAYAR"); // Cek status 0 atau 1
        }
        printf("----------------------------------------------------\n");

        printf("\nPilih Nomor Peserta (0 untuk kembali): ");
        scanf("%d", &pilih);
        getchar();

        if (pilih == 0) break; // Keluar menu

        int idx = pilih - 1; // Sesuaikan dengan index array (mulai dari 0)

        // Validasi nomor urut
        if (idx >= 0 && idx < noPeserta) {
            
            // Cek kalau sudah lunas, jangan ditagih lagi
            if (data[idx].sudahBayar == 1) {
                printf("\nPeserta atas nama %s SUDAH LUNAS.\n", data[idx].nama);
            } 
            else {
                // === HITUNG TAGIHAN ===
                int biayaTiket = 70000;
                int biayaKopi  = data[idx].beliKopi * 5000;
                int biayaMie = data[idx].beliMie * 7000;
                totalTagihan = biayaTiket + biayaKopi + biayaMie;
                

                printf("\n--- Rincian Tagihan %s ---\n", data[idx].nama);
                printf("Tiket Mancing : Rp 70.000\n");
                printf("Kopi (%d gelas) : Rp %d\n", data[idx].beliKopi, biayaKopi);
                printf("-------------------------- +\n");
                printf("TOTAL HARUS DIBAYAR: Rp %d\n", totalTagihan);

                // Input Pembayaran
                printf("Masukkan Uang Pembayaran: Rp ");
                scanf("%d", &uangBayar);
                getchar();

                if (uangBayar < totalTagihan) {
                    printf("\nUang tidak cukup! Transaksi dibatalkan.\n");
                } else {
                    kembalian = uangBayar - totalTagihan;
                    printf("Kembalian           : Rp %d\n", kembalian);
                    printf("\nStatus Berubah Menjadi LUNAS.\n");

                    // UPDATE STATUS DI DATABASE
                    data[idx].sudahBayar = 1; 
                }
            }

        } else {
            printf("Nomor peserta tidak valid!\n");
        }

        printf("\nProses pembayaran lain? (y/n): ");
        lanjut = getchar();
        getchar();

    } while (lanjut == 'y' || lanjut == 'Y');
}

//INPUT HASIL MANCING
void hasilIkan() {
    int nomor, ekor, berat;
    char lanjut;

    do {
        system("cls");
        printf("=== INPUT HASIL PANCINGAN ===\n");
        printf("Masukkan data hasil tangkapan peserta.\n\n");

        if (noPeserta == 0) {
            printf("Belum ada peserta.\n");
            printf("Tekan ENTER untuk kembali...");
            getchar();
            return;
        }

        // Tampilkan tabel biar admin gampang lihat data yang sudah masuk
        printf("%-3s %-20s %-10s %-15s\n", "No", "Nama", "Jml Ekor", "Berat Induk(gr)");
        printf("----------------------------------------------------\n");
        for (int i = 0; i < noPeserta; i++) {
            printf("%-3d %-20s %-10d %-15d\n", 
                i + 1, 
                data[i].nama, 
                data[i].jumlahIkan, 
                data[i].beratIkan);
        }
        printf("----------------------------------------------------\n");

        printf("\nPilih Nomor Peserta (0 untuk kembali): ");
        scanf("%d", &nomor);
        getchar();

        if (nomor == 0) break;

        // Validasi nomor
        if (nomor > 0 && nomor <= noPeserta) {
            int idx = nomor - 1;

            printf("\n--- Input Data untuk %s ---\n", data[idx].nama);
            
            printf("Jumlah Ikan (ekor)       : ");
            scanf("%d", &ekor);
            
            printf("Berat Ikan Terberat (gram): "); // Input berat ikan yang paling besar saja
            scanf("%d", &berat);
            getchar();

            // Simpan ke database
            data[idx].jumlahIkan = ekor;
            data[idx].beratIkan  = berat;

            printf("\nData berhasil disimpan!\n");

        } else {
            printf("Nomor peserta tidak valid!\n");
        }

        printf("\nInput data peserta lain? (y/n): ");
        lanjut = getchar();
        getchar();

    } while (lanjut == 'y' || lanjut == 'Y');
}

//PEMENANG
void pemenang() {
    if (noPeserta == 0) {
        printf("Belum ada peserta.\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }

    // 1. HITUNG DUIT HADIAH
    // Rumus: (Tiket 70rb - Ikan 38rb) = 32rb sisa buat hadiah
    long totalUangTerkumpul = noPeserta * 32000; 
    
    // Pembagian Hadiah (Bisa disesuaikan persennya)
    long hadiahBerat = totalUangTerkumpul * 0.25; // 25%
    long hadiahJ1    = totalUangTerkumpul * 0.35; // 35%
    long hadiahJ2    = totalUangTerkumpul * 0.25; // 25%
    long hadiahJ3    = totalUangTerkumpul * 0.15; // 15%

    // 2. CARI JUARA TERBERAT (1 Orang)
    // Kita cari manual pakai loop siapa yang paling berat ikannya
    int idxBerat = -1;
    int maxBerat = -1;

    for(int i = 0; i < noPeserta; i++) {
        if (data[i].beratIkan > maxBerat) {
            maxBerat = data[i].beratIkan;
            idxBerat = i;
        }
    }

    // 3. CARI JUARA TERBANYAK (Top 3)
    // Kita copy dulu datanya ke array sementara biar data asli nggak berantakan
    struct peserta temp[30];
    memcpy(temp, data, sizeof(data));

    // Sorting Descending (Besar ke Kecil) berdasarkan Jumlah Ikan
    for(int i = 0; i < noPeserta - 1; i++) {
        for(int j = 0; j < noPeserta - i - 1; j++) {
            if(temp[j].jumlahIkan < temp[j+1].jumlahIkan) { // Tanda < biar urut dari besar
                struct peserta t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }

    // 4. TAMPILKAN HASIL
    system("cls");
    printf("=== PENGUMUMAN JUARA PEMANCINGAN ===\n");
    printf("Total Peserta: %d orang\n", noPeserta);
    printf("Total Dana Hadiah: Rp %ld\n\n", totalUangTerkumpul);

    printf("--- KATEGORI IKAN TERBERAT (INDUK) ---\n");
    if (maxBerat > 0 && idxBerat != -1) {
        printf("PEMENANG : %s\n", data[idxBerat].nama);
        printf("Berat    : %d gram\n", data[idxBerat].beratIkan);
        printf("Hadiah   : Rp %ld\n", hadiahBerat);
    } else {
        printf("Belum ada data berat ikan.\n");
    }

    printf("\n--- KATEGORI IKAN TERBANYAK (JUMLAH EKOR) ---\n");
    
    // Juara 1
    printf("JUARA 1  : %s (%d ekor)\n", temp[0].nama, temp[0].jumlahIkan);
    printf("Hadiah   : Rp %ld\n", hadiahJ1);

    // Juara 2 (Cek kalau pesertanya cukup)
    if (noPeserta >= 2) {
        printf("JUARA 2  : %s (%d ekor)\n", temp[1].nama, temp[1].jumlahIkan);
        printf("Hadiah   : Rp %ld\n", hadiahJ2);
    }

    // Juara 3 (Cek kalau pesertanya cukup)
    if (noPeserta >= 3) {
        printf("JUARA 3  : %s (%d ekor)\n", temp[2].nama, temp[2].jumlahIkan);
        printf("Hadiah   : Rp %ld\n", hadiahJ3);
    }

    printf("\n============================================\n");
    printf("Selamat kepada para pemenang!\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();
}

//AKHIR SESI
void akhiriSesi() {
    if (noPeserta == 0) {
        printf("Belum ada data untuk disimpan.\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }

    // 1. SIAPKAN WAKTU & NAMA FILE
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    char namaFile[100];
    // Format nama file: Laporan_Tahun-Bulan-Tanggal_Jam-Menit.txt
    sprintf(namaFile, "Laporan_%04d-%02d-%02d_%02d-%02d.txt", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min);

    FILE *f = fopen(namaFile, "w"); // Mode "w" artinya write (buat file baru)

    if (f == NULL) {
        printf("Gagal membuat file laporan!\n");
        return;
    }

    printf("Sedang menyimpan laporan ke '%s'...\n", namaFile);

    // 2. TULIS HEADER & KEUANGAN
    float totalTiket = noPeserta * 70000;
    float modalIkan  = noPeserta * 38000;
    float danaHadiah = noPeserta * 32000;
    float totalKopi  = noPeserta * 5000;
    float totalMie   = noPeserta * 7000;
    float omsetKantin = 0;

    // Hitung omset kantin
    for(int i=0; i<noPeserta; i++){
        omsetKantin += (data[i].beliKopi * 5000 + data[i].beliMie * 7000); 
    }

    fprintf(f, "=== LAPORAN SESI PEMANCINGAN ===\n");
    fprintf(f, "Waktu Cetak : %02d-%02d-%04d Pukul %02d:%02d\n", 
            tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min);
    fprintf(f, "Total Peserta: %d Orang\n\n", noPeserta);

    fprintf(f, "--- RINGKASAN KEUANGAN ---\n");
    fprintf(f, "1. Total Uang Tiket Masuk : Rp %ld\n", totalTiket);
    fprintf(f, "2. Modal Belanja Ikan     : Rp %ld (Disisihkan)\n", modalIkan);
    fprintf(f, "3. Total Dana Hadiah      : Rp %ld (Dibagikan)\n", danaHadiah);
    fprintf(f, "4. Total Pendapatan Kantin: Rp %ld\n", omsetKantin);
    fprintf(f, "--------------------------------------------\n");
    fprintf(f, "TOTAL UANG KAS (Kantin)   : Rp %ld\n", omsetKantin); 
    fprintf(f, "--------------------------------------------\n\n");

    // 3. TULIS DATA PESERTA LENGKAP
    fprintf(f, "--- DATA PESERTA & HASIL ---\n");
    fprintf(f, "%-4s %-20s %-10s %-10s %-10s %-10s %-10s %-10s \n", 
            "No", "Nama", "Lapak", "Status", "Kopi", "Mie", "Ekor", "Berat(gr)");
    fprintf(f, "------------------------------------------------------------------------------\n");

    for (int i = 0; i < noPeserta; i++) {
        fprintf(f, "%-4d %-20s %-10d %-10s %-10d %-10d %-10d %-10d\n",
            i + 1,
            data[i].nama,
            data[i].lapak,
            data[i].sudahBayar ? "Lunas" : "Belum",
            data[i].beliKopi,
            data[i].beliMie,
            data[i].jumlahIkan,
            data[i].beratIkan
        );
    }
    fprintf(f, "------------------------------------------------------------------------------\n");

    fclose(f); // Tutup file biar tersimpan

    // 4. RESET DATA (KOSONGKAN ARRAY)
    // Supaya bisa mulai sesi baru tanpa keluar program
    noPeserta = 0; 

    printf("\nSUKSES! Data telah disimpan ke file .txt\n");
    printf("Sesi telah di-reset. Siap untuk sesi baru.\n");
    printf("Tekan ENTER untuk kembali ke menu utama...");
    getchar();
}