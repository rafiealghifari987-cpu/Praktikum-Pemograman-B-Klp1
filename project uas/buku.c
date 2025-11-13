#include "perpustakaan.h"

// === Tambah Buku ===
void tambahBuku() {
    Buku buku;
    FILE *fp = fopen("data/books.txt", "a");
    if (!fp) {
        printf("Gagal membuka file books.txt!\n");
        return;
    }

    printf("\n=== TAMBAH BUKU ===\n");
    printf("ID Buku: ");
    scanf("%d", &buku.id);
    clearBuffer();
    printf("Judul: ");
    fgets(buku.judul, MAX_STR, stdin);
    buku.judul[strcspn(buku.judul, "\n")] = 0;
    printf("Penulis: ");
    fgets(buku.penulis, MAX_STR, stdin);
    buku.penulis[strcspn(buku.penulis, "\n")] = 0;
    printf("Kategori: ");
    fgets(buku.kategori, MAX_STR, stdin);
    buku.kategori[strcspn(buku.kategori, "\n")] = 0;
    buku.tersedia = 1;
    buku.dipinjamCount = 0;

    fprintf(fp, "%d|%s|%s|%s|%d|%d\n",
            buku.id, buku.judul, buku.penulis, buku.kategori, buku.tersedia, buku.dipinjamCount);
    fclose(fp);

    printf("Buku berhasil ditambahkan!\n");
}

// === Tampilkan Daftar Buku ===
void tampilkanDaftarBuku() {
    FILE *fp = fopen("data/books.txt", "r");
    if (!fp) {
        printf("Belum ada data buku.\n");
        return;
    }

    Buku buku;
    printf("\n=== DAFTAR BUKU ===\n");
    printf("ID | Judul | Penulis | Kategori | Status | Dipinjam\n");
    printf("--------------------------------------------------------\n");
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d\n",
                  &buku.id, buku.judul, buku.penulis, buku.kategori,
                  &buku.tersedia, &buku.dipinjamCount) == 6) {
        printf("%d | %s | %s | %s | %s | %d\n",
               buku.id, buku.judul, buku.penulis, buku.kategori,
               buku.tersedia ? "Tersedia" : "Dipinjam", buku.dipinjamCount);
    }

    fclose(fp);
}

// === Cari Buku ===
void cariBuku() {
    char keyword[MAX_STR];
    printf("\nMasukkan kata kunci (judul atau penulis): ");
    scanf(" %[^\n]", keyword);

    FILE *fp = fopen("data/books.txt", "r");
    if (!fp) {
        printf("Data buku tidak ditemukan.\n");
        return;
    }

    Buku buku;
    int ditemukan = 0;
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d\n",
                  &buku.id, buku.judul, buku.penulis, buku.kategori,
                  &buku.tersedia, &buku.dipinjamCount) == 6) {
        if (strstr(buku.judul, keyword) || strstr(buku.penulis, keyword)) {
            printf("Ditemukan: %d - %s (%s)\n", buku.id, buku.judul, buku.penulis);
            ditemukan = 1;
        }
    }

    if (!ditemukan)
        printf("Buku tidak ditemukan.\n");

    fclose(fp);
}
