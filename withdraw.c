#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "withdraw.h"


struct Account {
    char name[50];
    int accNum;
    char pin[4];
    float balance;
};

void withdrawMoney() {
    struct Account acc;
    int accNo, found = 0;
    float amount;
    char inputPin[10];
    FILE *p = fopen("bank_data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!p || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fscanf(p, " %49s %d %9s %f", acc.name, &acc.accNum, acc.pin, &acc.balance) != EOF) {
        if (acc.accNum == accNo) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
        fclose(p);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    printf("Enter PIN: ");
    scanf("%s", inputPin);

    if (strcmp(acc.pin, inputPin) != 0) {
        printf("Incorrect PIN! Transaction aborted.\n");
        fclose(p);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (acc.balance < amount) {
        printf("Insufficient balance.\n");
        fclose(p);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    acc.balance -= amount;

    rewind(p);
    struct Account tempAcc;
    while (fscanf(p, " %49s %d %9s %f", tempAcc.name, &tempAcc.accNum, tempAcc.pin, &tempAcc.balance) != EOF) {
        if (tempAcc.accNum == acc.accNum) {
            fprintf(temp, "%s %d %s %.2f\n", acc.name, acc.accNum, acc.pin, acc.balance);
        } else {
            fprintf(temp, "%s %d %s %.2f\n", tempAcc.name, tempAcc.accNum, tempAcc.pin, tempAcc.balance);
        }
    }

    fclose(p);
    fclose(temp);
    remove("bank_data.txt");
    rename("temp.txt", "bank_data.txt");

    printf("Withdrawal successful!\n");
}
