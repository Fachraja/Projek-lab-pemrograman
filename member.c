#include <stdio.h>
#include "header.h"

void addMember() {
    char name[50];
    int points;

    printf("Nama Member: ");
    scanf("%s", name);
    printf("Poin Awal: ");
    scanf("%d", &points);

    FILE *file = fopen("data/members.txt", "a");
    if (!file) {
        printf("File members.txt tidak ditemukan!\n");
        return;
    }
    fprintf(file, "%s %d\n", name, points);
    fclose(file);
    printf("Member berhasil ditambahkan!\n");
}
