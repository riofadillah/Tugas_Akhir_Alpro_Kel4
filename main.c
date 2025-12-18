#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fungsi.h"

//MENU MAIN
int main(){

    while(1){
    system("cls");
    int pilihan1;
    system("cls");
    printf("=== SISTEM MANAJEMEN PEMANCINGAN ===\n");
    printf("1. Mulai sesi\n");
    printf("2. Akhiri program\n");
    printf("Pilihan[1-2}: ");
    scanf("%d", &pilihan1);
    getchar();
    
    switch(pilihan1){
        case 1:
            menuMulai();break;
        case 2:
            return 0;
        default:
            printf("Pilihan tidak valid!\n\n");
            printf("Tekan enter untuk kembali..."); getchar();
        }
    }
     return 0;
}

//MENU MULAI
void menuMulai(){ 
    int pilihan2;

    do {
        system("cls");
        printf("=== Menu Pemancingan ===\n");
        printf("1. Tambah peserta\n");
        printf("2. Acak lapak\n");
        printf("3. Lihat peserta\n");
        printf("4. Kantin\n");
        printf("5. Pembayaran\n");
        printf("6. Input hasil peserta\n");
        printf("7. List pemenang\n");
        printf("8. Akhiri sesi\n");
        printf("Pilihan [1-8]: ");
        scanf("%d", &pilihan2);
        getchar(); // bersihkan ENTER

        switch(pilihan2) {
            case 1:
                tambahPeserta();break;
            case 2:
                acakLapak();break;
            case 3:
                menuLihatPeserta();break;
            case 4:
                kantin();break;
            case 5:
                pembayaran();break;
            case 6:
                hasilIkan();break;
            case 7:
                pemenang();break;

            case 8:
                akhiriSesi();break;

            default:
                printf("Pilihan tidak valid!\n");
                printf("Tekan ENTER untuk kembali...");
                getchar();
        }

    } while (pilihan2 != 8);
}
