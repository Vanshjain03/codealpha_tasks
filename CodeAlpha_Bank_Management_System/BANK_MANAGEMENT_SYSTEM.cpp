/* 
 * Author: Vansh Jain
 * Task 4: High - Banking System 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Account {
    int accNo;
    char name[50];
    float balance;
};
const char* FILENAME = "bank_data.dat";
void createDefaultAccount() {
    FILE *file = fopen(FILENAME, "wb");
    if (file != NULL) {
        struct Account acc = {101, "Vansh Jain", 5000.00};
        fwrite(&acc, sizeof(struct Account), 1, file);
        fclose(file);
    }
}
void updateAccount(struct Account *acc) {
    FILE *file = fopen(FILENAME, "wb");
    if (file != NULL) {
        fwrite(acc, sizeof(struct Account), 1, file);
        fclose(file);
    }
}
void loadAccount(struct Account *acc) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        createDefaultAccount(); // Generate default if file doesn't exist
        file = fopen(FILENAME, "rb");
    }
    fread(acc, sizeof(struct Account), 1, file);
    fclose(file);
}
void deposit() {
    struct Account acc;
    float amount;
    loadAccount(&acc);
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);   
    if (amount > 0) {
        acc.balance += amount;
        updateAccount(&acc);
        printf("Deposit successful. New Balance: %.2f\n", acc.balance);
    } else {
        printf("Invalid amount.\n");
    }
}
void withdraw() {
    struct Account acc;
    float amount;
    loadAccount(&acc);
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);   
    if (amount > 0 && acc.balance >= amount) {
        acc.balance -= amount;
        updateAccount(&acc);
        printf("Withdrawal successful. New Balance: %.2f\n", acc.balance);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}
void balanceEnquiry() {
    struct Account acc;
    loadAccount(&acc);
    printf("\n--- Account Details ---\n");
    printf("Account No: %d\n", acc.accNo);
    printf("Name: %s\n", acc.name);
    printf("Current Balance: %.2f\n", acc.balance);
    printf("-----------------------\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n=== Bank Management System ===\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Balance Enquiry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);       
        switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: balanceEnquiry(); break;
            case 4: 
                printf("Exiting system...\n"); 
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
