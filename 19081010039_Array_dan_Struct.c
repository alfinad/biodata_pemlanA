#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

typedef struct {
    char fullName[50],jur[20],fak[30],agm[30],mk[50];
    int age,num;
}Mahasiswa;

void addMahasiswa();
void displayAllMahasiswa();
void searchMahasiswaByName();
void editMahasiswaByName();
void deleteMahasiswaByName();
FILE* openFile();

int main(){

int option;

MENU:
    system("cls");
    printf("=====.:MENU:.=====");
    printf("\n1. Tambah");
    printf("\n2. Tampilkan");
    printf("\n3. Edit");
    printf("\n4. Cari");
    printf("\n5. Hapus");
    printf("\n6. Exit\n");
    printf("\nMasukkan Pilihan : ");
    scanf("%d", &option);
    switch(option){
    case 1:
        addMahasiswa();
        break;
    case 2:
        displayAllMahasiswaList();
        break;
    case 3:
        editMahasiswaByName();
        break;
    case 4:
        searchMahasiswaByName();
        break;
    case 5:
        deleteMahasiswaByName();
        break;
    case 6:
        exit(-1);
        break;
    default:
        printf("\nAda Kesalahan");
        break;
    }
    getch();
    goto MENU;
getch();
return 0;
}

FILE* openFile(){
FILE *fptr;

fptr = fopen("emp.bin", "r+b");
if(fptr == NULL){
    printf("\n File not found .....trying to create one");
    fptr = fopen("emp.bin", "w+b");
        if(fptr == NULL){
         printf("\n File not found .....trying to create one failed too...");
         return NULL;
        }else{
        return fptr;
        }
}else{

return fptr;
}
 
}
void addMahasiswa(){
system("cls");
Mahasiswa e;
FILE *fptr = openFile();
if(fptr == NULL){
    exit(-1);
}

printf("\nMasukkan Nama: ");
fflush(stdin);
gets(e.fullName);
printf("Masukkan Umur: ");
scanf("%d", &e.age);
printf("Masukkan NPM: ");
scanf("%d", &e.num);
printf("Masukkan Jurusan: ");
fflush(stdin);
gets(e.jur);
printf("Masukkan Fakultas: ");
fflush(stdin);
gets(e.fak);
printf("Masukkan Agama: ");
fflush(stdin);
gets(e.agm);
printf("Masukkan Mata Kuliah: ");
fflush(stdin);
gets(e.mk);


fseek(fptr, 0, 2);
if(fwrite(&e, sizeof(e), 1,fptr )==1){
    printf("\nMenulis ke disk ... Selesai..Tekan sembarang tombol untuk melanjutkan ..");
}
fclose(fptr);
}

void displayAllMahasiswaList(){
system("cls");
Mahasiswa e;
int hasRecord = 0;
FILE *fptr = openFile();
if(fptr == NULL){
    exit(-1);
}
printf("\nNama\t\tUmur\tNPM\t\tJurusan\t\tFakultas\t\tAgama\t\tMata Kuliah");
printf("\n*********************************************************************************************************************\n");
while(fread(&e, sizeof(e),1,fptr)==1){
    hasRecord = 1;
   printf("%s\t\t%d\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n", e.fullName, e.age, e.num, e.jur, e.fak, e.agm, e.mk);
   printf("_____________________________________________________________________________________________________________________\n");
}
if(hasRecord == 0){
    printf("\nTidak ada catatan..Tekan tombol apa saja untuk melanjutkan.");
}

fclose(fptr);
}
void editMahasiswaByName(){
system("cls");
Mahasiswa e;
char searchName[50];
int recordNo =0, isFound = 0;
FILE *fptr = openFile();
if(fptr == NULL ){
    printf("\nMaaf, modifikasi gagal ...");
    exit(-1);
}
printf("\nMasukkan Nama:\t");
fflush(stdin);
gets(searchName);
while(fread(&e, sizeof(e), 1, fptr) == 1){
if(strcmp(searchName, e.fullName) == 0){
isFound = 1;
printf("\nMasukkan NPM baru: ");
scanf("%d", &e.num);
fseek(fptr, sizeof(e)*recordNo, 0);
if(fwrite(&e, sizeof(e), 1, fptr)==1){
    fseek(fptr, sizeof(e)*(recordNo+1), 0);
}
}
recordNo++;
}
if(isFound == 1){
    printf("\nData berhasil diubah..Tekan sembarang tombol untuk melanjutkan");
}else{
printf("\nTidak ada yang cocok .. Tekan sembarang tombol untuk melanjutkan");
}
fclose(fptr);
 
}
void deleteMahasiswaByName(){
system("cls");
Mahasiswa e;
FILE *fptr, *fptr2;
int isDeleted = 0;
char searchName[50];
fptr = openFile();
fptr2 = fopen("tmp.bin", "w+b");
if(fptr2 == NULL || fptr == NULL){
    printf("\n Maaf file tidak dapat dibuka");
    exit(-1);
}
printf("\nMasukkan Nama:\t");
fflush(stdin);
gets(searchName);
while(fread(&e, sizeof(e), 1, fptr) == 1){
    if(strcasecmp(e.fullName,searchName ) != 0){
        fwrite(&e, sizeof(e), 1, fptr2);
        printf("\nMenulis .... ke file sementara ... selesai!!!");
    }
    }
    
if(fclose(fptr) == 0)
printf("\nFile asli ditutup...");
if(fclose(fptr2) == 0)
printf("\nFile sementara ditutup ...");
if(remove("emp.bin")==0){

    printf("\nFile asli dihapus ...");
}else{
 printf("\nFile asli tidak dapat dihapus ...");
}

if(rename("tmp.bin", "emp.bin")==0){

    printf("\nFile sementara diganti namanya ... Tekan sembarang tombol untuk melanjutkan");
}else{
printf("\nFile sementara tidak dapat diganti namanya ...");
}
}
void searchMahasiswaByName(){

system("cls");
Mahasiswa e;
char searchName[50];
int  isFound = 0;
FILE *fptr = openFile();
if(fptr == NULL ){
    printf("\nSorry, the data file could not be opened...");
    exit(-1);
}
printf("\nMasukkan nama :\t");
fflush(stdin);
gets(searchName);
printf("\nNama\t\tUmur\tNPM\t\tJurusan\t\tFakultas\t\tAgama\t\tMata Kuliah");
printf("\n***********************************************\n");
while(fread(&e, sizeof(e),1,fptr)==1){
    if(strcasecmp(e.fullName,searchName ) == 0){
    isFound = 1;
   printf("%s\t\t%d\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n", e.fullName, e.age, e.num, e.jur, e.fak, e.agm, e.mk);
   printf("_____________________________________________________________________________________________________________________");
    }
}
if(isFound == 0){
    printf("\nMaaf ... catatan tidak ditemukan... coba periksa ejaan Anda.. \nTekan sembarang tombol untuk melanjutkan");
}
fclose(fptr);
}
