#include "perpustakaan.h"

// === Tambah Anggota ===
void tambahAnggota() {
    Anggota a;
    FILE *fp = fopen("data/members.txt", "a");
    if (!fp) {
        printf("Gagal membuka file members.txt!\n");
        return;
    }

    printf("\n=== TAMBAH ANGGOTA ===\n");
    printf("ID Anggota: ");
    scanf("%d", &a.id);
    clearBuffer();
    printf("Nama: ");
    fgets(a.nama, MAX_STR, stdin);
    a.nama[strcspn(a.nama, "\n")] = 0;
    printf("Alamat: ");
    fgets(a.alamat, MAX_STR, stdin);
    a.alamat[strcspn(a.alamat, "\n")] = 0;

    fprintf(fp, "%d|%s|%s\n", a.id, a.nama, a.alamat);
    fclose(fp);

    printf("Anggota berhasil ditambahkan!\n");
}

// === Tampilkan Anggota ===
void tampilkanAnggota() {
    FILE *fp = fopen("data/members.txt", "r");
    if (!fp) {
        printf("Belum ada data anggota.\n");
        return;
    }

    Anggota a;
    printf("\n=== DAFTAR ANGGOTA ===\n");
    printf("ID | Nama | Alamat\n");
    printf("--------------------------\n");
    while (fscanf(fp, "%d|%[^|]|%[^\n]\n", &a.id, a.nama, a.alamat) == 3) {
        printf("%d | %s | %s\n", a.id, a.nama, a.alamat);
    }

    fclose(fp);
}
