#include <stdio.h>
#include <string.h>
#include "header.h"

void addProduct() {
    char name[50], category[50];
    int stock;
    float price;

    printf("Nama Produk: ");
    scanf("%s", name);
    printf("Kategori: ");
    scanf("%s", category);
    printf("Harga: ");
    scanf("%f", &price);
    printf("Stok: ");
    scanf("%d", &stock);

    FILE *file = fopen("data/products.txt", "a");
    if (!file) {
        printf("File products.txt tidak ditemukan!\n");
        return;
    }
    fprintf(file, "%s %s %.2f %d\n", name, category, price, stock);
    fclose(file);
    printf("Produk berhasil ditambahkan!\n");
}

void deleteProduct() {
    char name[50], tempName[50];
    int found = 0;
    FILE *file = fopen("data/products.txt", "r");
    FILE *tempFile = fopen("data/temp.txt", "w");

    if (!file || !tempFile) {
        printf("File tidak ditemukan!\n");
        return;
    }

    printf("Nama produk yang ingin dihapus: ");
    scanf("%s", name);

    while (fscanf(file, "%s", tempName) != EOF) {
        if (strcmp(name, tempName) != 0) {
            fprintf(tempFile, "%s\n", tempName);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("data/products.txt");
    rename("data/temp.txt", "data/products.txt");

    if (found) {
        printf("Produk berhasil dihapus!\n");
    } else {
        printf("Produk tidak ditemukan!\n");
    }
}

void viewProducts() {
    char buffer[255];
    FILE *file = fopen("data/products.txt", "r");

    if (!file) {
        printf("File products.txt tidak ditemukan!\n");
        return;
    }

    printf("\n=== Daftar Produk ===\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}
