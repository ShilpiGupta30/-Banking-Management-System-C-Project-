#include <stdio.h>
#include <stdlib.h>
#include "createAcc.h"
#include "deposit.h"
#include "withdraw.h"
#include "accDetails.h"
#include "deleteAcc.h"
#include "loan.h"
#include "updatePin.h"


int main() {
    int ch;

    while (1) {
        printf("\n=== Banking Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. Delete Account\n");
        printf("6. Loan Management\n");
        printf("7. Update PIN\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createAcc(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: accDetails(); break;
            case 5: delAccount(); break;
            case 6: manageLoan(); break;
            case 7: updatePIN(); break;
            case 8: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
