#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "loan.h"

struct Account {
    char name[50];
    int accNum;
    float balance;
};

void manageLoan() {
    struct Account acc;
    int accNo, found = 0, tenure;
    float maxLoan, reqLoan, monthlyRate, annualRate = 10.0, emi;
    char line[200];

    FILE *p = fopen("bank_data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!p || !temp) {
        perror("Error opening file");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fgets(line, sizeof(line), p)) {
        if (sscanf(line, "%s %d %f", acc.name, &acc.accNum, &acc.balance) == 3) {
            if (acc.accNum == accNo) {
                found = 1;
                maxLoan = acc.balance * 5;
                printf("You can apply for a loan up to: %.2f\n", maxLoan);
                printf("Enter desired loan amount: ");
                scanf("%f", &reqLoan);

                if (reqLoan <= maxLoan) {
                    printf("Enter Loan Duration (in months): ");
                    scanf("%d", &tenure);

                    monthlyRate = annualRate / (12 * 100);
                    emi = (reqLoan * monthlyRate * pow(1 + monthlyRate, tenure)) /
                          (pow(1 + monthlyRate, tenure) - 1);

                    printf("Loan Approved! Amount: %.2f\n", reqLoan);
                    printf("Monthly EMI for %d months at %.2f%% interest: Rs. %.2f\n", tenure, annualRate, emi);

                    acc.balance += reqLoan;
                } else {
                    printf("Loan Denied! Amount exceeds maximum allowed.\n");
                }
            }
            fprintf(temp, "%s %d %.2f\n", acc.name, acc.accNum, acc.balance);
        }
    }

    fclose(p);
    fclose(temp);
    remove("bank_data.txt");
    rename("temp.txt", "bank_data.txt");

    if (!found) {
        printf("Account not found!\n");
    }
}