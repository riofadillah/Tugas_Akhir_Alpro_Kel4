#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define LAPAK_TOTAL 28

struct Peserta{
    char nama[30];
    char nohp[20];
    int sudahBayar;      // 0 = belum, 1 = sudah
    int lapak;           // 1–28
    int beliKantin;      // 0 = tidak, 1 = beli kopi
    int jumlahIkan;      // untuk lomba
    int beratIkan;       // gram
};

struct Peserta data[MAX];
int tot=0;
int lapakSudahDiacak=0;

// Prototipe fungsi
void inputPeserta();
void tampilPeserta();     // hanya tampil daftar
void lihatPeserta();      // tampil daftar + pause
void searchPeserta();
void sortNama();
void sortLapak();
void sortBayar();
void acakLapak();
void kantin();
void pembayaran();
void inputHasil();
void listPemenang();
void riwayat();

int main() {
    int awal;
    system("cls");
    printf("=== SISTEM MANAJEMEN PEMANCINGAN ===\n");
    printf("1. Mulai lomba hari ini\n");
    printf("2. Lihat riwayat hari sebelumnya\n");
    printf("Pilihan: ");
    scanf("%d", &awal);
    getchar();

    if (awal == 2) {
        riwayat();
        printf("\nTekan ENTER untuk keluar...");
        getchar();
        return 0;
    } else if (awal != 1) {
        printf("Pilihan tidak valid!\n");
        return 0;
    }

    // ===== MENU UTAMA =====
    int pilihan;
    while(1){
        system("cls");
        printf("\t=== MENU PEMANCINGAN ===\n");
        printf("1. Input Peserta\n2. Lihat Peserta\n3. Search Peserta\n4. Sort Peserta\n");
        printf("5. Acak Lapak\n6. Kantin\n7. Pembayaran\n8. Input Hasil Lomba\n");
        printf("9. List Pemenang\n10. Riwayat\n11. Keluar\n");
        printf("Pilih: ");
        scanf("%d",&pilihan);
        getchar();

        switch(pilihan){
            case 1: inputPeserta(); break;
            case 2: lihatPeserta(); break;
            case 3: searchPeserta(); break;
            case 4: {
                int s;
                printf("Sort berdasarkan: 1. Nama 2. Lapak 3. Status Bayar : ");
                scanf("%d",&s);
                getchar();
                if(s==1) sortNama();
                else if(s==2) sortLapak();
                else if(s==3) sortBayar();
                else printf("Pilihan salah!\n");
                break;
            }
            case 5: acakLapak(); break;
            case 6: kantin(); break;
            case 7: pembayaran(); break;
            case 8: inputHasil(); break;
            case 9: listPemenang(); break;
            case 10: riwayat(); break;
            case 11: printf("Program selesai.\n"); exit(0);
            default: printf("Pilihan tidak valid!\n"); getchar();
        }
    }
    return 0;
}

// ===== FUNGSI =====

void inputPeserta(){
    char lagi;
    do{
        system("cls");
        printf("=== Input Peserta ===\n");
        printf("Nama : ");
        scanf(" %[^\n]", data[tot].nama);
        printf("No HP: ");
        scanf(" %[^\n]", data[tot].nohp);

        data[tot].sudahBayar = 0;
        data[tot].lapak = 0;
        data[tot].beliKantin = 0;
        data[tot].jumlahIkan = 0;
        data[tot].beratIkan = 0;
        tot++;

        printf("Input lagi? (y/n): ");
        getchar();
        lagi = getchar();
        getchar();
    }while(lagi=='y' || lagi=='Y');
}

void tampilPeserta() {
    printf("\n======= DAFTAR PESERTA (%d) =======\n", tot);
    printf("%-3s %-20s %-15s %-10s %-5s\n","No","Nama","No HP","Bayar","Lapak");
    for(int i=0;i<tot;i++){
        printf("%-3d %-20s %-15s %-10s %-5d\n",i+1,data[i].nama,data[i].nohp,
            data[i].sudahBayar?"Lunas":"Belum", data[i].lapak);
    }
    printf("===============================\n");
}

void lihatPeserta() {
    system("cls");
    tampilPeserta();
    printf("Tekan ENTER untuk kembali...");
    while(getchar()!='\n');
    getchar();
}

void searchPeserta(){
    char keyword[50];
    system("cls");
    printf("=== Cari Peserta ===\n");
    printf("Masukkan nama atau no HP: ");
    scanf(" %[^\n]", keyword);

    int found=0;
    for(int i=0;i<tot;i++){
        if(strstr(data[i].nama, keyword)!=NULL || strstr(data[i].nohp, keyword)!=NULL){
            printf("%-3d %-20s %-15s %-10s %-5d\n",i+1,data[i].nama,data[i].nohp,
                data[i].sudahBayar?"Lunas":"Belum",data[i].lapak);
            found=1;
        }
    }
    if(!found) printf("Peserta tidak ditemukan.\n");
    printf("Tekan ENTER...");
    getchar();
    getchar();
}

void sortNama(){
    for(int i=0;i<tot-1;i++){
        for(int j=i+1;j<tot;j++){
            if(strcmp(data[i].nama,data[j].nama)>0){
                struct Peserta temp = data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }
    printf("Data peserta sudah diurutkan berdasarkan nama.\nTekan ENTER...");
    getchar();
    getchar();
}

void sortLapak(){
    for(int i=0;i<tot-1;i++){
        for(int j=i+1;j<tot;j++){
            if(data[i].lapak>data[j].lapak){
                struct Peserta temp = data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }
    printf("Data peserta sudah diurutkan berdasarkan lapak.\nTekan ENTER...");
    getchar();
    getchar();
}

void sortBayar(){
    for(int i=0;i<tot-1;i++){
        for(int j=0;j<tot;j++){
            if(data[i].sudahBayar>data[j].sudahBayar){
                struct Peserta temp = data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }
    printf("Data peserta sudah diurutkan berdasarkan status bayar.\nTekan ENTER...");
    getchar();
    getchar();
}

void acakLapak(){
    system("cls");
    if(lapakSudahDiacak){
        printf("Lapak sudah diacak sebelumnya.\n");
    }else{
        int kiri=1,kanan=15;
        for(int i=0;i<tot;i++){
            if(i%2==0) data[i].lapak=kiri++;
            else data[i].lapak=kanan++;
        }
        lapakSudahDiacak=1;
        printf("Acak lapak selesai!\n");
    }
    tampilPeserta(); // hanya tampil tanpa pause
    printf("Tekan ENTER...");
    getchar();
}

void kantin(){
    system("cls");
    int pilih;
    tampilPeserta(); // tampil peserta tanpa pause
    printf("Pilih nomor peserta yang beli kopi (5000): ");
    scanf("%d",&pilih);
    if(pilih>=1 && pilih<=tot) data[pilih-1].beliKantin=1;
    printf("Kantin berhasil diupdate.\nTekan ENTER...");
    getchar();
    getchar();
}

void pembayaran(){
    system("cls");
    int pilih;
    tampilPeserta(); // tampil peserta tanpa pause
    printf("Pilih nomor peserta untuk pembayaran 70k: ");
    scanf("%d",&pilih);
    if(pilih>=1 && pilih<=tot) data[pilih-1].sudahBayar=1;
    printf("Status pembayaran sudah diperbarui.\nTekan ENTER...");
    getchar();
    getchar();
}

void inputHasil(){
    system("cls");
    for(int i=0;i<tot;i++){
        printf("%s, Jumlah Ikan: ", data[i].nama);
        scanf("%d",&data[i].jumlahIkan);
        printf("Berat Ikan (gram): ");
        scanf("%d",&data[i].beratIkan);
    }
    printf("Input hasil lomba selesai.\nTekan ENTER...");
    getchar();
    getchar();
}

void listPemenang(){
    system("cls");
    int juaraBanyak[3]={-1,-1,-1};
    int juaraBerat=-1;

    for(int i=0;i<tot;i++){
        if(juaraBerat==-1 || data[i].beratIkan>data[juaraBerat].beratIkan) juaraBerat=i;
    }

    for(int k=0;k<3;k++){
        int max=-1,idx=-1;
        for(int i=0;i<tot;i++){
            if(i==juaraBanyak[0] || i==juaraBanyak[1] || i==juaraBanyak[2]) continue;
            if(data[i].jumlahIkan>max){
                max=data[i].jumlahIkan;
                idx=i;
            }
        }
        if(idx!=-1) juaraBanyak[k]=idx;
    }

    printf("======= DAFTAR PEMENANG =======\n");
    for(int i=0;i<3;i++){
        if(juaraBanyak[i]!=-1)
            printf("Juara Banyak Ikan %d: %s (%d ikan)\n",i+1,data[juaraBanyak[i]].nama,data[juaraBanyak[i]].jumlahIkan);
    }
    if(juaraBerat!=-1)
        printf("Juara Berat Ikan: %s (%d gram)\n",data[juaraBerat].nama,data[juaraBerat].beratIkan);

    printf("===============================\nTekan ENTER...");
    getchar();
    getchar();
}

void riwayat(){
    system("cls");
    FILE *f = fopen("riwayat.txt","a+");
    if(f==NULL){
        printf("Gagal membuka file!\n");
        getchar();
        return;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(f,"===== %02d-%02d-%04d %02d:%02d =====\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min);

    // daftar peserta
    fprintf(f,"%-3s %-20s %-15s %-10s %-5s\n","No","Nama","No HP","Bayar","Lapak");
    for(int i=0;i<tot;i++){
        fprintf(f,"%-3d %-20s %-15s %-10s %-5d\n",i+1,data[i].nama,data[i].nohp,
            data[i].sudahBayar?"Lunas":"Belum",data[i].lapak);
    }
    fclose(f);

    // tampilkan riwayat
    f=fopen("riwayat.txt","r");
    if(f){
        char line[200];
        while(fgets(line,sizeof(line),f)){
            printf("%s",line);
        }
        fclose(f);
    }
    printf("Tekan ENTER...");
    getchar();
}
