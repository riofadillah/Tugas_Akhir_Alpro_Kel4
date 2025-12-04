#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"


int main(){
 int awal;
    while(1){
    system("cls");
    int pilihan1;
    system("cls");
    printf("=== SISTEM MANAJEMEN PEMANCINGAN ===\n");
    printf("1. Mulai pemancingan hari ini\n");
    printf("2. Lihat riwayat hari sebelumnya\n");
    printf("3. Akhiri program\n");
    printf("Pilihan[1-3]: ");
    scanf("%d", &pilihan1);
    getchar();
    
    switch(pilihan1){
        case 1:menuMulai();break;
        case 2:printf("hi");break;
        case 3:return 0;
        default:
            printf("Pilihan tidak valid!\n\n");
            printf("Tekan enter untuk kembali..."); getchar();
        }
        return 0;
    }
}