#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deleteAcc.h"

struct Account {
    char name[50];
    int accNum;
    char pin[10];
    float balance;
};

void delAccount() {
    struct Account acc;
    int accNo, found = 0;

    FILE *p = fopen("bank_data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!p || !temp) {
        perror("File error");
        return;
    }

    printf("Enter Account Number to Delete: ");
    scanf("%d", &accNo);

    while (fscanf(p, " %49[^0-9] %d %9s %f", acc.name, &acc.accNum, acc.pin, &acc.balance) != EOF) {
        acc.name[strcspn(acc.name, "\n")] = 0; // Strip newline
        if (accNo != acc.accNum) {
            fprintf(temp, "%s %d %s %.2f\n", acc.name, acc.accNum, acc.pin, acc.balance);
        } else {
            found = 1;
        }
    }

    fclose(p);
    fclose(temp);
    remove("bank_data.txt");
    rename("temp.txt", "bank_data.txt");

    if (found) {
        printf("Account Deleted Successfully!\n");
    } else {
        printf("Account not found!\n");
    }
}
