#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"

struct peserta{
    char nama[30];
    char nohp[20];
    int sudahBayar;      // 0 = belum, 1 = sudah
    int lapak;           // 1–28
    int beliKantin;      // 0 = tidak, 1 = beli kopi
    int jumlahIkan;     
    int beratIkan;       // gram
};
struct peserta data[30];
int noPeserta = 0;

//MENU AWAL
void menuMulai(){
    int pilihan2;

    do {
        system("cls");
        printf("=== Menu Pemancingan ===\n");
        printf("1. Tambah peserta\n");
        printf("2. Lihat peserta\n");
        printf("3. Kantin\n");
        printf("4. Pembayaran\n");
        printf("5. Input hasil peserta\n");
        printf("6. List pemenang\n");
        printf("7. Akhiri sesi\n");
        printf("Pilihan [1-7]: ");
        scanf("%d", &pilihan2);
        getchar(); // bersihkan ENTER

        switch(pilihan2) {
            case 1:
                tambahPeserta();
                break;

            case 2:
                lihatPeserta();
                break;

            case 3:
                // kantin();
                break;

            case 4:
                // pembayaran();
                break;

            case 5:
                // hasilIkan();
                break;

            case 6:
                // pemenang();
                break;

            case 7:
                printf("\nSesi diakhiri...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                printf("Tekan ENTER untuk kembali...");
                getchar();
        }

        // supaya setelah fungsi selesai, tidak langsung lompat,
        // user baca dulu outputnya
        if (pilihan2 != 7) {
            printf("\nTekan ENTER untuk kembali ke menu...");
            getchar();
        }

    } while (pilihan2 != 7);
}

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
        data[noPeserta].beliKantin = 0;
        data[noPeserta].jumlahIkan = 0;
        data[noPeserta].beratIkan = 0;
        noPeserta++;

        printf("Input lagi? (y/n): ");
        getchar();
        lagi = getchar();
        getchar();
    }while(lagi=='y' || lagi=='Y');
    }

//LIHAT PESERTA
void lihatPeserta(){
    system("cls");
    if(noPeserta == 0){
        printf("Belum ada peserta...");
    }
    else{
        printf("\n===================== Daftar peserta =====================\n", noPeserta);
        printf("%-3s %-20s %-15s %-10s %-5s\n","No","Nama","No HP","Bayar","Lapak");
    for(int i=0;i<noPeserta;i++){
        printf("%-3d %-20s %-15s %-10s %-5d\n",i+1,data[i].nama,data[i].nohp,
            data[i].sudahBayar?"Lunas":"Belum", data[i].lapak);
    }
        printf("==========================================================\n");
    }
}