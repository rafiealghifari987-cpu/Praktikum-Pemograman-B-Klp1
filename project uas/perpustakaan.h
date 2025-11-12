#ifndef PERPUSTAKAAN_H

#define PERPUSTAKAAN_H


#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>


#define MAX_STR 100

#define MAX_BOOKS 1000

#define MAX_MEMBERS 500 
        
#define MAX_LOANS 1000


typedef struct{
   int id;
   int judul [MAX_STR];
   int penulis [MAX_STR];
   int kategori [MAX_STR];
   int tersedia;
   int dipinjamCount;   

}Buku;




typedef struct{

   int  id;
   char nama [MAX_STR];
   char alamat [MAX STR];

}Anggota;


typedef struct {
   int  id ;
   int  idBuku;
   int  idAnggota;
   int  tanggalPinjam[20];
   char tanggalKembali[20];
   int  denda;

}Peminjaman;


void tampilkanMenuUtama() ;
void loginPustakawan() ;

void tambahanBuku();
void hapusBuku() ;
void editBuku() ;
void tampilkanDaftarBuku() ;
void cariBuku() ;
void rangkingBuku() ;

void tambahAnggota() ;
void tampilkanAnggota() ;

void pinjamBuku() ;
void kembalikanBuku() ;

int hitungDenda(const char *tlgPinjam, const char *tglKembali) ;
void simpanBuku(Buku buku) ;
void simpanAnggota(Anggota anggota);
void simpanPeminjaman(Peminjaman peminjam) ;

void bacaBukuDariFile(Buku 
daftarBuku[], int *jumlah) ;
void bacaAnggotaDariFile(Anggota daftarAnggota[], int *jumlah) ;
void bacaPeminjamDariFile(Peminjaman daftarPeminjam[], int *jumlah) ;

#endif





















