/*
* File: app.c
* Author: Mohamed Alaa
*
*created on Aug 8, 2023, 4;30 PM
*/

#include "Application.h"

void appStart(void)
{
    ST_cardData_t cardData;
    ST_terminalData_t terminalData;
    ST_accountsDB_t* accountRef;
    ST_transaction_t transactionData;

    if (getCardHolderName(&cardData) != CARD_OK)
    {
        printf("Error: Invalid card holder name.\n");
        return;
    }

    if (getCardExpiryDate(&cardData) != CARD_OK)
    {
        printf("Error: Invalid card expiry date.\n");
        return;
    }

    if (getCardPAN(&cardData) != CARD_OK)
    {
        printf("Error: Invalid card PAN.\n");
        return;
    }

    if (getTransactionDate(&terminalData) != TERMINAL_OK)
    {
        printf("Error: Invalid transaction date.\n");
        return;
    }

    if (isCardExpired(&cardData, &terminalData) != TERMINAL_OK)
    {
        printf("Error: Card is expired.\n");
        return;
    }

    if (getTransactionAmount(&terminalData) != TERMINAL_OK)
    {
        printf("Error: Invalid transaction amount.\n");
        return;
    }

    if (isValidAccount(&cardData, &accountRef) != SERVER_OK)
    {
        printf("Error: Account not found.\n");
        return;
    }

