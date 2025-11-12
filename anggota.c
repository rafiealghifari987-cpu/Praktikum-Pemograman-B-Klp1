#include "perpustakaan.h"

void tambahAnggota() {
    Anggota anggota;
    FILE *file = fopen("members.txt", "a");
    if (!file) {
        printf("Gagal membuka file members.txt\n");
        return;
    }

    printf("\n=== TAMBAH ANGGOTA ===\n");
    printf("ID Anggota: ");
    scanf("%d", &anggota.id);
    printf("Nama: ");
    scanf(" %[^\n]", anggota.nama);
    printf("Alamat: ");
    scanf(" %[^\n]", anggota.alamat);

    fprintf(file, "%d;%s;%s\n", anggota.id, anggota.nama, anggota.alamat);
    fclose(file);

    printf("Anggota berhasil ditambahkan!\n\n");
}