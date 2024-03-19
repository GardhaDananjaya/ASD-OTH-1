#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fungsi untuk mengkonversi nilai kartu ke angka
int nilaiKartu(char kartu[]) {
    if (strcmp(kartu, "J") == 0) return 11;
    if (strcmp(kartu, "Q") == 0) return 12;
    if (strcmp(kartu, "K") == 0) return 13;
    return atoi(kartu); // Mengkonversi string ke integer
}

int main() {

    int banyak_angka;   // deklarasi variabel
    printf("Masukkan Banyaknya angka: ");
    scanf("%d", &banyak_angka); // Membaca jumlah kartu

    char kartu[banyak_angka][3]; // Array untuk menyimpan nilai kartu
    for(int i = 0; i < banyak_angka; i++) {
        scanf("%s", kartu[i]); // Membaca nilai kartu
    }

    // Mengurutkan kartu menggunakan Selection Sort
    int langkahPertukaran = 0;      // variabel untuk menampung langkah pertukaran
    for(int i = 0; i < banyak_angka - 1; i++) {
        int minIndex = i;   // variabel yang menyimpan indeks terkecil
        for(int j = i+1; j < banyak_angka; j++) {
            if(nilaiKartu(kartu[j]) < nilaiKartu(kartu[minIndex])) {        // untuk cek jika nilai kartu j < minIndex maka
                minIndex = j;   // minIndex menjadi = j
            }
        }
        if(minIndex != i) { // jika angka terkecil tidak = i
            char temp[3];       // variabel sementara untuk menyimpan kartu
            strcpy(temp, kartu[i]); // copy kartu ke variabel sementara
            strcpy(kartu[i], kartu[minIndex]);  // copy kartu terkecil ke kartu [i]
            strcpy(kartu[minIndex], temp);  // copy kartu dari variabel temp ke kartu terkecil
            langkahPertukaran++;        

            printf("\nPertukaran %d: ", langkahPertukaran);
            for (int L = 0; L < banyak_angka; L++) {
                printf("%s ", kartu[L]);        // mencetak semua hasil kartu yang telah ditukar
            }
        }
    }

    printf("\nJumlah langkah pertukaran: %d\n", langkahPertukaran);
    return 0;
}
