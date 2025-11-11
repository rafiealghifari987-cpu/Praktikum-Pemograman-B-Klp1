#ifndef PERPUSTAKAAN_H

#define PERPUSTAKAAN_H

#include "perpustakaan.h"

#include <stdio.h

#include <stdlib.h>

#include <string.h>

#include <time.h>


#define MAX STR 100

#define MAX BOOKS 1000

#define MAX MEMBERS 500 
        
#define MAX LOANS 1000


typedef struct{
int id;

int judul [MAX_STR];

int penulis [MAX_STR];

int kategori [MAX_STR];

int tersedia;

int dipinjamCount;   
}buku;




typedef struct{
int id:

char nama [MAX_STR);

char alamat (MAX STR);

}anggota;















