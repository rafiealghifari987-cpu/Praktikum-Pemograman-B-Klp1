#include "perpustakaan.h"

// === Ambil tanggal sekarang ===
void getTanggalSekarang(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// === Bersihkan buffer input ===
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
