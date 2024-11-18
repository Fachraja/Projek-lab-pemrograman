#include <stdio.h>
#include "header.h"

int main() {
    int choice;

    login(); // Login terlebih dahulu

    do {
        printf("\n=== Sistem Kasir ===\n");
        printf("1. Tambah Produk\n");
        printf("2. Hapus Produk\n");
        printf("3. Ubah Stok Produk\n");
        printf("4. Lihat Daftar Produk\n");
        printf("5. Kategorikan Produk\n");
        printf("6. Tambah Member\n");
        printf("7. Proses Transaksi\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                categorizeProducts();
                break;
            case 6:
                addMember();
                break;
            case 7:
                processTransaction();
                break;
            case 8:
                generateSalesReport();
                break;
            case 9:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 9);

    return 0;
}
