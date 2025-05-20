#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "updatePin.h"

struct Account {
    char name[50];
    int accNum;
    char pin[4];
    float balance;
};

void updatePIN() {
    struct Account acc, tempAcc;
    int accNo, found = 0;
    char oldPin[10], newPin[10], confirmPin[10];

    FILE *p = fopen("bank_data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!p || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fscanf(p, " %49[^0-9] %d %9s %f", acc.name, &acc.accNum, acc.pin, &acc.balance) != EOF) {
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

    printf("Enter Current PIN: ");
    scanf("%s", oldPin);

    if (strcmp(acc.pin, oldPin) != 0) {
        printf("Incorrect PIN. Aborting PIN update.\n");
        fclose(p);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    printf("Enter New PIN: ");
    scanf("%s", newPin);

    printf("Confirm New PIN: ");
    scanf("%s", confirmPin);

    if (strcmp(newPin, confirmPin) != 0) {
        printf("PIN mismatch! PIN not updated.\n");
        fclose(p);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    strcpy(acc.pin, newPin);

    rewind(p);
    while (fscanf(p, " %49[^0-9] %d %9s %f", tempAcc.name, &tempAcc.accNum, tempAcc.pin, &tempAcc.balance) != EOF) {
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

    printf("PIN updated successfully!\n");
}
