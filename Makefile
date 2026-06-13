# Derleyici ve bayraklar (flags) tanımlamaları
CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS = -shared

# all hedefi, lib ve main hedeflerini sırasıyla tetikler
all: lib main

# Paylaşılan kütüphane oluşturma hedefi
lib:
	$(CC) $(CFLAGS) -c src/kare.c -o src/kare.o
	$(CC) $(CFLAGS) -c src/kup.c -o src/kup.o
	$(CC) $(CFLAGS) -c src/faktoriyel.c -o src/faktoriyel.o
	$(CC) $(CFLAGS) -c src/asal_mi.c -o src/asal_mi.o
	$(CC) $(LDFLAGS) -o libmath.so src/kare.o src/kup.o src/faktoriyel.o src/asal_mi.o

# Ana programı kütüphane ile bağlayarak derleme hedefi
main:
	$(CC) -Wall -Wextra main.c -L. -lmath -o ana_program

# Programı çalıştırma hedefi (LD_LIBRARY_PATH ile kütüphane yolu gösteriliyor)
run:
	LD_LIBRARY_PATH=. ./ana_program

# Oluşan nesne dosyalarını ve derlenmiş dosyaları temizleme hedefi
clean:
	rm -f src/*.o libmath.so ana_program
