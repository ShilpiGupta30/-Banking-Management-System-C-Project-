#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "accDetails.h"

struct Account {
    char name[50];
    int accNum;
    char pin[4];
    float balance;
};

void accDetails() {
    struct Account acc;
    int accNo, found = 0;
    FILE *p = fopen("bank_data.txt", "r");

    if (!p) {
        printf("Account file error.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fscanf(p, " %49[^0-9] %d %9s %f", acc.name, &acc.accNum, acc.pin, &acc.balance) != EOF) {
        acc.name[strcspn(acc.name, "\n")] = 0; // Strip newline
        if (acc.accNum == accNo) {
            printf("Name: %s\n", acc.name);
            printf("Account Number: %d\n", acc.accNum);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(p);

    if (!found)
        printf("Account not found!\n");
}
