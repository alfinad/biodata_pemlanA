#include <stdio.h>
#include <string.h>

// membuat struct
struct Mahasiswa{
  char nama[30]; //variable nama dapat diisi dengan karakter maksimal 30 karakter
  double npm; //bilangan real
  char jurusan[30]; //variable jurusan dapat diisi dengan karakter maksimal 30 karakter
  char fakultas[30]; //variable fakultas dapat diisi dengan karakter maksimal 30 karakter
};

// membuat struct dengan typedef
typedef struct Mahasiswa biodata;
int main(void)
{
  biodata mhs; //biodata adalah alias dari struct Mahasiswa
  
  //strcpy digunakan untuk mengcopy sebuah string ke dalam string lain
  strcpy(mhs.nama, "Alfina Damayanti");
  mhs.npm=19081010039; //isi variable mhs.npm dengan angka karena menggunakan type data double
  strcpy(mhs.jurusan, "Informatika");
  strcpy(mhs.fakultas, "Ilmu Komputer");
  
 //menampilkan variable
  printf("Nama 	 : %s\n",mhs.nama);
  printf("NPM 	 : %.lf\n",mhs.npm);
  printf("Jurusan  : %s\n",mhs.jurusan);
  printf("Fakultas : %s\n",mhs.fakultas);
 
  return 0;
}
