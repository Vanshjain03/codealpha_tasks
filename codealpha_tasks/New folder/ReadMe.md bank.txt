# CodeAlpha_Banking_System

## Overview
A Bank Account Management System mini-project developed in C for the CodeAlpha C Programming Internship. This program implements `structs` and binary file handling (`.dat` files) to ensure user data is stored persistently across multiple sessions.

## Features
* **Deposit:** Add funds to the account securely.
* **Withdraw:** Remove funds with built-in insufficient balance checks.
* **Balance Enquiry:** View current account details and available balance.
* **Data Persistence:** Uses `fwrite` and `fread` to save and load account states permanently.

## How to Run
1. Compile the program: `gcc banking_system.c -o banking_system`
2. Execute the compiled file: `./banking_system`
3. Use the numbered, menu-driven interface to perform banking operations. *(Note: A default account file `bank_data.dat` will be generated on the first run).*

## Author
**Vansh Jain**