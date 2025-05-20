
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createAcc.h"

struct Account {
    char name[50];
    int accNum;
    char pin[4];
    float balance;
};

void createAcc() {
    struct Account acc;
    FILE *p = fopen("bank_data.txt", "a");

    getchar();
    printf("Enter Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';

    while (1) {
        printf("Enter 8-digit Account Number: ");
        scanf("%d", &acc.accNum);
        if (acc.accNum >= 10000000 && acc.accNum <= 99999999)
            break;
        else
            printf("Account number must be exactly 8 digits.\n");
    }
    
    while (1) {
        printf("Set 4-digit PIN: ");
        scanf("%s", acc.pin);
        if (strlen(acc.pin) == 4)
            break;
        else
            printf("Invalid! PIN must be exactly 4 digits.\n");
    }

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fprintf(p, "%s %d %s %.2f\n", acc.name, acc.accNum, acc.pin, acc.balance);
    fclose(p);

    printf("Account Created Successfully!\n");
}   