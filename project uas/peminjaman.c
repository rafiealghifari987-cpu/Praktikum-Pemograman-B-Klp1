#include "perpustakaan.h"

// === Pinjam Buku ===
void pinjamBuku() {
    int idBuku, idAnggota;
    char tanggal[20];
    printf("\n=== PEMINJAMAN BUKU ===\n");
    printf("ID Buku: ");
    scanf("%d", &idBuku);
    printf("ID Anggota: ");
    scanf("%d", &idAnggota);

    getTanggalSekarang(tanggal);

    FILE *fp = fopen("data/loans.txt", "a");
    if (!fp) {
        printf("Gagal membuka file loans.txt!\n");
        return;
    }

    fprintf(fp, "%d|%d|%d|%s|-\n", rand() % 10000, idBuku, idAnggota, tanggal);
    fclose(fp);
    printf("Buku berhasil dipinjam pada tanggal %s.\n", tanggal);
}

// === Kembalikan Buku ===
void kembalikanBuku() {
    int idPeminjaman;
    char tglKembali[20];
    printf("\nMasukkan ID Peminjaman: ");
    scanf("%d", &idPeminjaman);
    getTanggalSekarang(tglKembali);
    printf("Buku dikembalikan pada %s (denda dicek manual).\n", tglKembali);
}

// === Hitung Denda ===
int hitungDenda(const char *tglPinjam, const char *tglKembali) {
    struct tm tm1 = {0}, tm2 = {0};
    strptime(tglPinjam, "%d-%m-%Y", &tm1);
    strptime(tglKembali, "%d-%m-%Y", &tm2);

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);
    int hari = difftime(t2, t1) / (60 * 60 * 24);
    return (hari > 7) ? (hari - 7) * 1000 : 0;
}
