/*
* File: server.h
* Author: Mohamed Alaa
*
*created on Aug 8, 2023, 4;30 PM
*/
#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include "../types.h"
#include "../Card/card.h"
#include"../Terminal/terminal.h"

typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STILEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint8_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t {
    SERVER_OK, SAVING_FAILD, TRANSACTION_NOT_FOUND,
    ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t {
    RUNNING, BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t {
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

ST_accountsDB_t accountDB[255] = { {2000.0,RUNNING,"8279360145680245"},{100000.0,BLOCKED,"5807001070561954"},{40000.0,RUNNING,"3670156782062813"},
{1000.0,RUNNING,"1276026791360156"},{800.0,BLOCKED,"871009991450012"},{90000.0,BLOCKED,"9800761299012679"},{1200.0,RUNNING,"1560256190017634"},
{300000.0,BLOCKED,"4619001569141188"},{5000.0,RUNNING,"1670177199001657"},{2000.0,BLOCKED,"1299041883461951"} };

ST_transaction_t transaction[255] = { 0 };

EN_transState_t recieveTransactionData(ST_transaction_t* transData);

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence);

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence);

EN_serverError_t saveTransaction(ST_transaction_t* transData);


void recieveTransactionDataTest(void);

void listSaveTransactions(void);

void isValidAccountTest(void);

void isBlockedAccountTest(void);

void isAmountAvailableTest(void);

void listSaveTransactionsTest(void);





#endif