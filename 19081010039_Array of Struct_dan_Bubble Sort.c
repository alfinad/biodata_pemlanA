#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

//Nama			: Alfina Damayanti
//NPM			: 19081010039
//Mata Kuliah	: Pemrograman Lanjut A

typedef struct {
    char nama[50];
    char npm[20];
    char jur[30];
    char fak[30];
    char mk[30];
    float smt;
    int umur;
}Mahasiswa;

void addMahasiswa();
void displayAllMahasiswa();
void editMahasiswa();
void deleteMahasiswa();
void bubblesort();
FILE* openFile();

int main(){

int option;

MENU:
    system("cls");
    printf("=====.:MENU:.=====");
    printf("\n1. Tambah");
    printf("\n2. Tampilkan");
    printf("\n3. Edit");
    printf("\n4. Hapus");
    printf("\n5. Urutkan data");
    printf("\n6. Exit\n");
    printf("\nMasukkan Pilihan : ");
    scanf("%d", &option);
    switch(option){
    case 1:
        addMahasiswa();
        break;
    case 2:
        displayAllMahasiswa();
        break;
    case 3:
        editMahasiswa();
        break;
    case 4:
        deleteMahasiswa();
        break;
    case 5:
    	bubblesort();
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

fptr = fopen("pl.bin", "r+b");
if(fptr == NULL){
    printf("\n File not found .....trying to create one");
    fptr = fopen("pl.bin", "w+b");
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

printf("\nNama\t\t: ");
fflush(stdin);
gets(e.nama);
printf("NPM\t\t: ");
gets(e.npm);
printf("Jurusan\t\t: ");
gets(e.jur);
printf("Fakultas\t: ");
gets(e.fak);
printf("Mata Kuliah\t: ");
gets(e.mk);
printf("Semester\t: ");
scanf("%f", &e.smt);
printf("Umur\t\t: ");
scanf("%d", &e.umur);


fseek(fptr, 0, 2);
if(fwrite(&e, sizeof(e), 1,fptr )==1){
    printf("\nTekan ENTER untuk melanjutkan ..");
}
fclose(fptr);
}
/**** to display all the details of each employee *****/

void displayAllMahasiswa(){
	///clear the screen
system("cls");
Mahasiswa e;
int hasRecord = 0;
///open the file
FILE *fptr = openFile();
if(fptr == NULL){
    exit(-1);
}

while(fread(&e, sizeof(e),1,fptr)==1){
    hasRecord = 1;
   printf("\nNama\t\t: %s\n",e.nama);
   printf("NPM\t\t: %s\n",e.npm);
   printf("Jurusan\t\t: %s\n",e.jur);
   printf("Fakultas\t: %s\n",e.fak);
   printf("Mata Kuliah\t: %s\n",e.mk);
   printf("Semester\t: %f\n",e.smt);
   printf("Umur\t\t: %d\n",e.umur);
}
printf("\nTekan ENTER untuk melanjutkan...");
if(hasRecord == 0){
    printf("\nTidak ada catatan..Tekan ENTER untuk melanjutkan...");
}
///close the file
fclose(fptr);
}///function ends

void editMahasiswa(){
	///clear the screen
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
if(strcmp(searchName, e.nama) == 0){
isFound = 1;
printf("\nMasukkan NPM baru: ");
scanf("%s", &e.npm);
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
void deleteMahasiswa(){
system("cls");
Mahasiswa e;
FILE *fptr, *fptr2;
int isDeleted = 0;
char searchName[50];
fptr = openFile();
fptr2 = fopen("pl.bin", "w+b");
if(fptr2 == NULL || fptr == NULL){
    printf("\n Maaf file tidak dapat dibuka");
    exit(-1);
}
printf("\nMasukkan Nama:\t");
fflush(stdin);
gets(searchName);
while(fread(&e, sizeof(e), 1, fptr) == 1){
    if(strcasecmp(e.nama,searchName ) != 0){
        fwrite(&e, sizeof(e), 1, fptr2);
        printf("\nMenulis .... ke file sementara ... selesai!!!");
    }
    }
    
if(fclose(fptr) == 0)
printf("\nFile asli ditutup...");
if(fclose(fptr2) == 0)
printf("\nFile sementara ditutup ...");
if(remove("pl.bin")==0){

    printf("\nFile asli dihapus ...");
}else{
 printf("\nFile asli tidak dapat dihapus ...");
}

if(rename("pem.bin", "pl.bin")==0){

    printf("\nFile sementara diganti namanya ... Tekan sembarang tombol untuk melanjutkan");
}else{
printf("\nFile sementara tidak dapat diganti namanya ...");
}
}

void bubblesort(){
system("cls");
Mahasiswa e;
FILE *fptr = openFile();
int i;
printf("Sebelum Sorting : \n");
	for(i=0; i>1; i++){
		printf("\nNama\t\t: %s\n",e.nama);
   		printf("NPM\t\t: %s\n",e.npm);
   		printf("Jurusan\t\t: %s\n",e.jur);
   		printf("Fakultas\t: %s\n",e.fak);
   		printf("Mata Kuliah\t: %s\n",e.mk);
   		printf("Semester\t: %f\n",e.smt);
   		printf("Umur\t\t: %d\n",e.umur);
	}
	bubblesort();
	printf("\n\nSetelah Sorting Ascending : \n");
	for(i=0; i>1; i++){
		printf("\nNama\t\t: %s\n",e.nama);
   		printf("NPM\t\t: %s\n",e.npm);
   		printf("Jurusan\t\t: %s\n",e.jur);
   		printf("Fakultas\t: %s\n",e.fak);
   		printf("Mata Kuliah\t: %s\n",e.mk);
   		printf("Semester\t: %f\n",e.smt);
   		printf("Umur\t\t: %d\n",e.umur);
	}
	bubblesort();
	printf("\n\nSetelah Sorting Descending : \n");
	for(i=0; i>1; i++){
		printf("\nNama\t\t: %s\n",e.nama);
   		printf("NPM\t\t: %s\n",e.npm);
   		printf("Jurusan\t\t: %s\n",e.jur);
   		printf("Fakultas\t: %s\n",e.fak);
   		printf("Mata Kuliah\t: %s\n",e.mk);
   		printf("Semester\t: %f\n",e.smt);
   		printf("Umur\t\t: %d\n",e.umur);
	}
	getchar();
}

