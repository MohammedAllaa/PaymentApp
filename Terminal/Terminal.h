/*
* File: terminal.h
* Author: Mohamed Alaa
*
*created on Aug 8, 2023, 4;30 PM
*/
#ifndef TERMINAL_H
#define TERMINAL_H
#include <stdio.h>
#include "../types.h"
#include "../Card/card.h"

typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t {
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD,
    INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

EN_terminalError_t gettransactionDate(ST_terminalData_t* termData);

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData);

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount);

void getTransactionDateTest(void);

void isCardExpiredTest(void);

void  getTransactionAmountTest(void);

void isBelowMaxAmountTest(void);

void setMaxAmountTest(void);
#endif
