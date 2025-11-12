#include "perpustakaan.h"

void tambahBuku() {
    Buku buku;
    FILE *file = fopen("books.txt", "a");
    if (!file) {
        printf("Gagal membuka file books.txt\n");
        return;
    }

    printf("\n=== TAMBAH BUKU ===\n");
    printf("ID Buku: ");
    scanf("%d", &buku.id);
    printf("Judul: ");
    scanf(" %[^\n]", buku.judul);
    printf("Penulis: ");
    scanf(" %[^\n]", buku.penulis);
    printf("Kategori: ");
    scanf(" %[^\n]", buku.kategori);
    buku.tersedia = 1;
    buku.dipinjamCount = 0;

    fprintf(file, "%d;%s;%s;%s;%d;%d\n", buku.id, buku.judul, buku.penulis, buku.kategori, buku.tersedia, buku.dipinjamCount);
    fclose(file);

    printf("Buku berhasil ditambahkan!\n\n");
}