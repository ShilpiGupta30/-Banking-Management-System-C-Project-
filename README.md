# 🏦 Banking Management System (C Project)

A console-based banking management system written in C. This project supports account creation, secure deposits and withdrawals using PINs, loan management, and PIN updates. All account data is stored in a plain text file.

---

## 📚 Features

- Create a new account (with 8-digit account number & 4-digit PIN)
- Deposit money (with account and PIN verification)
- Withdraw money (with balance and PIN checks)
- View account details
- Delete an account
- Apply for a loan (up to 5× balance)
- Update account PIN securely
- Hidden PIN input for security

---

## 🗂️ File Structure

BankingSystem/
├── main.c # Main menu and function dispatch
├── build.bat # Batch script to compile the program
│
├── account.h # Common account structure
│
├── createAcc.c / createAcc.h # Account creation logic
├── deposit.c / deposit.h # Deposit functionality
├── withdraw.c / withdraw.h # Withdrawal functionality
├── accDetails.c / accDetails.h # Display account information
├── deleteAcc.c / deleteAcc.h # Delete account functionality
├── loan.c / loan.h # Loan management logic
├── updatePin.c / updatePin.h # Update PIN logic
