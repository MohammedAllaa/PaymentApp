# PaymentApp
This project is a simple Payment Application implemented in C that simulates a terminal-based system for processing credit card transactions. It includes functionalities for validating cardholder information, checking account balance, processing transactions, and maintaining transaction logs. The project follows a modular approach, separating logic into different modules such as Card, Terminal, Server, and Application.

# Features
Card Module: Handles cardholder details including cardholder name, card expiration date, and primary account number (PAN).

Terminal Module: Manages transaction data such as transaction date and amount.

Server Module: Simulates a bank server with account and transaction databases.

Application Module: Coordinates the entire process, invoking the necessary modules in sequence to process a transaction from start to finish.

# Project Structure
card.c/card.h: Contains card validation logic.

terminal.c/terminal.h: Manages transaction-related data and validations.

server.c/server.h: Handles account and transaction processing.

app.c/app.h: The main application that integrates all modules.

# How It Works
1- The user inputs cardholder details and the application validates them.

2- The user inputs the transaction date and amount.

3- The application checks whether the card is expired and if the account has sufficient funds.

4-The server processes the transaction, and if approved, logs it in the transaction history.

# For You
I will leave the project file in the project code.
