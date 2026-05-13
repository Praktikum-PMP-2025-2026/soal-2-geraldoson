/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 * Modul               : 05 Foundation of Algorithm
 * Hari dan Tanggal    : Rabu, 13 Mei 2026
 * Nama (NIM)          : Geraldo Son Luther Silalahi (13224018)
 * Nama File           : soal1.c
 * Deskripsi           : Program membaca grid biner yang merepresentasikan peta energi.
 * Program menghitung jumlah pulau dari sel bernilai 1 yang saling terhubung secara
 * vertikal atau horizontal. Program juga menentukan ukuran pulau terbesar menggunakan
 * penelusuran DFS pada grid.
 */

/*
Komentar variabel
brs = jumlah baris grid
klm = jumlah kolom grid
peta[105][105] = grid biner sebagai peta energi
jmlhPulau = jumlah pulau yang ditemukan
ukr = ukuran pulau yang sedang dihitung
ukrMax = ukuran pulau terbesar
r = indeks baris saat DFS
c = indeks kolom saat DFS
dr[4] = perubahan arah baris
dc[4] = perubahan arah kolom
arah = pencacah arah penelusuran
nr = baris berikutnya
nc = kolom berikutnya

referensi: https://www.tutorialspoint.com/dsa_using_c/dsa_using_c_graph.htm
*/

#include <stdio.h>

char peta[105][105];
int brs, klm;

/* referensi: https://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal.htm */
/* referensi: https://www.tutorialspoint.com/cprogramming/c_recursion.htm */
int dfs(int r, int c){
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int arah, nr, nc, ukr = 1;

    for(arah = 0; arah < 4; arah++){
        nr = r + dc[arah];
        nc = c + dc[arah];

        if(nr >= 0 && nr <= brs && nc >= 0 && nc <= klm && peta[nr][nc == '1']){
            ukr = ukr + dfs(nr, nc);
        }
    }
    return ukr;
}

int main(){
    int i, j, ukr, jmlhPulau = 0, ukrMax = 0;

    scanf("%d %d", &brs, &klm);

    for(i = 0; i < brs; i++){
        scanf("%s", peta[i]);
    }

    for(i = 0; i < brs; i++){
        for(j = 0; j < brs; j++){
            if(peta[i][j] == '1'){
                jmlhPulau++;
                ukr = dfs(i, j);

                if(ukr > ukrMax){
                    ukrMax = ukr;
                }
            }
        }
    }

    printf("ISLAND %d\n", jmlhPulau);
    printf("LARGEST %d\n", ukrMax);

    return 0;
}
