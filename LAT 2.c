#include <stdio.h>

// Inisialisasi papan catur
void koboChess(int i, int j, int size, int *chessBoard) {
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            *(chessBoard + x * size + y) = 0;
        }
    }

    // mendefinisikan semua gerakan yang bisa dilakukan kuda
    int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                       {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};

    // cek setiap gerakan kuda jika benar maka posisi di papan diubah menjadi 1
    for (int k = 0; k < 8; k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            *(chessBoard + new_i * size + new_j) = 1;
        }
    }

    // menampilkan papan catur
    printf("Hasil array %d x %d:\n", size, size);
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d ", *(chessBoard + x * size + y));
        }
        printf("\n");
    }
}

// fungsi utama
int main() {
    int i, j;       // deklarasi variabel i,j sebagai posisi kuda
    printf("Masukkan posisi Kuda (i j): ");     // cetak masukkan posisi kuda dalam i,j
    scanf("%d %d", &i, &j);     // menyimpan inputan kedalam var i, j

    // inisialisasi papan catur yang berupa arrya 2 dimensi berukuran 8x8
    int size = 8;
    int chessBoard[8][8];

    //  pemanggilan fungsi kobochess
    koboChess(i, j, size, (int *)chessBoard);

    return 0;
}

