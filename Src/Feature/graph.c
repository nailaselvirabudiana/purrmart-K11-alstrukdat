#include <stdio.h>
# include "graph.h"
# include "../ADT/mesinkarakter/mesinkarakter.h"
# include "../ADT/mesinkata/mesinkata.h"

int graph[MAX][MAX];   // Graph adjacency matrix
int visited[MAX];      // Array for visited nodes
int bestPath[MAX];     // Best path storage
int tempPath[MAX];     // Temporary path storage
int minCost = INF;     // Minimum cost initialized to INF
int currentCost = 0;   // Current traversal cost
int n;                 // Number of nodes


/* Fungsi untuk menampilkan path */
void printPath(int path[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

/* Fungsi untuk membuat pohon DFS dan mengecek semua rute */
void buildTree(int current, int depth) {
    visited[current] = 1;           // Tandai node sebagai dikunjungi
    tempPath[depth - 1] = current;  // Simpan node saat ini dalam path sementara

    // Jika sudah mengunjungi semua node, kembali ke node awal
    if (depth == n) {
        if (graph[current][0] != INF) { // Cek jika ada jalur kembali ke 0
            currentCost += graph[current][0]; // Tambahkan biaya kembali ke awal
            tempPath[depth] = 0;        // Tambahkan node awal ke akhir path

            // Cek apakah ini path dengan biaya minimum
            if (currentCost < minCost) {
                minCost = currentCost;
                for (int i = 0; i <= n; i++) {
                    bestPath[i] = tempPath[i]; // Simpan path terbaik
                }
            }

            // Cetak setiap path yang selesai (optional for tree visualization)
            printf("Path ditemukan: ");
            printPath(tempPath, n + 1);
            currentCost -= graph[current][0]; // Backtrack biaya
        }
        visited[current] = 0; // Batalkan tanda kunjungan
        return;
    }

    // Cek semua node yang bisa menjadi anak dari node saat ini (pembangunan pohon)
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current][i] != INF) {
            currentCost += graph[current][i]; // Tambahkan biaya
            buildTree(i, depth + 1);          // Rekursi ke node anak
            currentCost -= graph[current][i]; // Backtrack biaya
        }
    }

    visited[current] = 0; // Batalkan tanda kunjungan (backtrack)
}

/* Fungsi untuk mengecek input duplikat */
int isDuplicateEdge(int u, int v) {
    return graph[u][v] != INF; // Jika sudah ada jalur, kembalikan true
}

void DFS() {
    int edges, i, u, v, w;

    printf("Masukkan jumlah lokasi pengiriman (node): ");
    STARTWORD();
    if (isKataInteger(currentWord)) {
        n = Word2int(currentWord);
    } else {
        printf("Input tidak valid! Silakan masukkan angka.\n");
        return;
    }
    

    printf("Masukkan jumlah rute (edge): ");
    STARTWORD();
    if (isKataInteger(currentWord)) {
        edges = Word2int(currentWord);
    } else {
        printf("Input tidak valid! Silakan masukkan angka.\n");
        return;
    }


    /* Inisialisasi matriks graph dengan nilai INF */
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                graph[i][j] = 0; // Jarak ke diri sendiri adalah 0
            else
                graph[i][j] = INF;
        }
    }

    /* Masukkan data rute */
    printf("Masukkan jarak antarlokasi (format: asal tujuan jarak):\n");
    for (i = 0; i < edges; i++) {
        while (1) { // Loop sampai input valid
            STARTWORD();
            u = Word2int(currentWord);
            ADVWORD();
            v = Word2int(currentWord);
            ADVWORD();
            w = Word2int(currentWord);

            // Cek duplikat atau edge terbalik
            if (u < 0 || u >= n || v < 0 || v >= n) {
                printf("Node tidak valid! Silakan ulangi.\n");
            } else if (isDuplicateEdge(u, v) || isDuplicateEdge(v, u)) {
                printf("Jalur antara %d dan %d sudah ada! Silakan masukkan rute yang berbeda:\n", u, v);
            } else {
                graph[u][v] = w;
                graph[v][u] = w; // Karena graf tidak berarah
                break;
            }
        }
    }

    /* Inisialisasi array visited */
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Membangun pohon pencarian, silakan tunggu...\n");

    /* Bangun pohon dari node 0 */
    buildTree(0, 1);

    /* Cetak hasil akhir */
    printf("\nRute paling efektif adalah: ");
    for (i = 0; i <= n; i++) {
        printf("%d ", bestPath[i]);
    }
    printf("\nBiaya minimum: %d\n", minCost);

}