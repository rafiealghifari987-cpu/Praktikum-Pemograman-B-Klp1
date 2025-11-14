CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c buku.c anggota.c peminjaman.c utils.c
OBJ = $(SRC:.c=.o)
OUT = app

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

%.o: %.c perpustakaan.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(OUT)
