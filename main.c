#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    login(); // Memastikan pengguna login sebelum menggunakan sistem

    int choice;
    do {
        displayMenu();
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: deleteProduct(); break;
            case 3: updateStock(); break;
            case 4: viewProducts(); break;
            case 5: categorizeProducts(); break;
            case 6: processTransaction(); break;
            case 7: addMember(); break;
            case 8: salesReport(); break;
            case 9: printf("Program selesai. Terima kasih!\n"); break;
            default: printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 9);

    return 0;
}