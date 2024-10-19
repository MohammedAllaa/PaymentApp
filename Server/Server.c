/*
* File: server.c
* Author: Mohamed Alaa
*
*created on Aug 8, 2023, 4;30 PM
*/
#include "server.h"
#include<string.h>


EN_transState_t recieveTransactionData(ST_transaction_t* transData) {

    printf("Enter card Holder name\n");
    scanf("%s", transData->cardHolderData.cardHolderName);

    /***********************************************************************/
    printf("Enter card expiry date\n");
    printf("crad expiry date must be in the format MM/YY \n ");
    scanf("%s", transData->cardHolderData.cardHolderName);

    /************************************************************************/
    printf("Enter card's primary Account Number\n");
    scanf("%s", transData->cardHolderData.primaryAccountNumber);

    /************************************************************************/
    printf("Enter transaction date\n");
    printf("It must be in format DD/MM/YY \n");
    scanf("%s", transData->terminalData.transactionDate);

    /************************************************************************/

    printf("Enter transacion amout\n");
    scanf("%f", &transData->terminalData.transAmount);

    /************************************************************************/
    printf("Enter maximum allowed amount\n");
    scanf("%f", &transData->terminalData.maxTransAmount);
    /********************************************************************/
    for (int i = 0; i <= 10; i++) {
        if (transData->cardHolderData.primaryAccountNumber != accountDB[i].primaryAccountNumber) {
            return FRAUD_CARD;
        }
    }

    for (int i = 0; i <= 10; i++) {
        if (transData->cardHolderData.primaryAccountNumber == accountDB[i].primaryAccountNumber) {
            if (transData->terminalData.transAmount > accountDB[i].balance) {
                return DECLINED_INSUFFECIENT_FUND;
            }
        }
    }

    for (int i = 0; i <= 10; i++) {
        if (transData->cardHolderData.primaryAccountNumber == accountDB[i].primaryAccountNumber) {
            if (accountDB[i].state == BLOCKED) {
                return DECLINED_STILEN_CARD;
            }
        }
    }

    return APPROVED;

}

void recieveTransactionDataTest(void) {
    ST_transaction_t* transData;
    EN_transState_t ret;
    printf("Taster Name: Mohamed Alaa\n");
    printf("Fuction Name: isValidAccount\n");

    /*..............test_1.............*/
    printf("test case 1\n");
    printf("input data: \n");
    ret = recieveTransactionData(transData);
    if (ret == FRAUD_CARD) {
        printf("Actual result:FRAUD_CARD\n ");
    }
    else if (ret == DECLINED_STILEN_CARD) {
        printf("Actual result:DECLINED_STILEN_CARD\n ");

    }
    else if (ret == DECLINED_INSUFFECIENT_FUND) {
        printf("Actual result:DECLINED_INSUFFECIENT_FUND\n ");

    }
    else if (ret == APPROVED) {
        printf("Actual result:APPROVED\n ");

    }
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) {
    if (NULL == cardData) {
        return ACCOUNT_NOT_FOUND;
    }
    for (int i = 0; i <= 10; i++) {
        if (cardData->primaryAccountNumber == accountDB[i].primaryAccountNumber) {
            *accountRefrence = accountDB[i];
            return SERVER_OK;
        }
    }
    return ACCOUNT_NOT_FOUND;
}

void isValidAccountTest(void) {
    EN_serverError_t ret;
    ST_cardData_t cardData;
    ST_accountsDB_t accountRefrence1[10];
    printf("Taster Name: Mohamed Alaa\n");
    printf("Fuction Name: isValidAccount\n");

    /*..............test_1.............*/
    printf("test case 1\n");
    printf("input data: 871009991450012\n");
    scanf("%s", cardData.primaryAccountNumber);
    ret = isValidAccount(&cardData, &accountRefrence1[0]);
    //printf("%s\n",cardData.cardExpirationDate);
    //printf("%s\n",accountRefrence1[0].primaryAccountNumber);
    //printf("%s\n",accountDB[4].primaryAccountNumber);
    printf("Expected result: SERVER_OK\n");
    if (ret == SERVER_OK) {
        printf("Actual result: SERVER_OK\n");
    }

    printf("Actual result: ACCOUNT_NOT_FOUND\n");


    /*..............test_2.............*/
    printf("test case 2\n");
    printf("input data: 87100999145001200\n");
    scanf("%s", cardData.primaryAccountNumber);
    ret = isValidAccount(&cardData, &accountRefrence1[1]);
    printf("Expected result: ACCOUNT_NOT_FOUND\n");
    if (ret == SERVER_OK) {
        printf("Actual result: SERVER_OK\n");
    }

    printf("Actual result: ACCOUNT_NOT_FOUND\n");

}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {
    EN_accountState_t state;

    printf("Enter your PAN: \n");
    scanf("%s", accountRefrence->primaryAccountNumber);
    int i = 0;
    for (i = 0; i < 10;i++) {
        if (accountRefrence->primaryAccountNumber == accountDB[i].primaryAccountNumber) {
            state = accountDB[i].state;
        }
    }
    if (state == BLOCKED)
    {
        return BLOCKED_ACCOUNT;
    }
    else
        return SERVER_OK;

}

void isBlockedAccountTest(void) {
    EN_serverError_t ret;
    ST_accountsDB_t accountRefrence;
    printf("Taster Name: Mohamed Alaa\n");
    printf("Fuction Name: isBlockedAccount\n");

    /*..............test_1.............*/
    printf("test case 1\n");
    printf("input data: 871009991450012\n");
    ret = isBlockedAccount(&accountRefrence);
    printf("Expected result: BLOCKED_ACCOUNT\n");

    if (ret == SERVER_OK) {
        printf("Actual result: SERVER_OK\n");
    }

    if (ret == BLOCKED_ACCOUNT) {
        printf("Actual result: BLOCKED_ACCOUNT\n");
    }


}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {

    if (termData->transAmount > accountRefrence->balance) {
        return LOW_BALANCE;
    }
    return SERVER_OK;
}

void isAmountAvailableTest(void) {
    EN_serverError_t ret;
    ST_terminalData_t* termData;
    ST_accountsDB_t accountRefrence;
    printf("Taster Name: Mohamed Alaa\n");
    printf("Fuction Name: isAmountAvilable\n");

    /*..............test_1.............*/
    printf("test case 1\n");
    printf("input data: 1000\n");
    getTransactionAmount(termData);
    ret = isAmountAvailable(termData, &accountDB[0]);

    printf("Expected result: SERVER_OK\n");

    if (ret == SERVER_OK) {
        printf("Actual result: SERVER_OK\n");
    }

    if (ret == LOW_BALANCE) {
        printf("Actual result: LOW_BALANCE\n");
    }

    /*..............test_2.............*/
    printf("test case 2\n");
    printf("input data: 10000\n");
    getTransactionAmount(termData);
    ret = isAmountAvailable(termData, &accountDB[0]);

    printf("Expected result: LOW_BALANCE\n");

    if (ret == SERVER_OK) {
        printf("Actual result: SERVER_OK\n");
    }

    if (ret == LOW_BALANCE) {
        printf("Actual result: LOW_BALANCE\n");
    }


}

EN_serverError_t saveTransaction(ST_transaction_t* transData) {
    uint23_t counter = 0;
    if (NULL == transData) {
        return SAVING_FAILD;
    }
    for (counter = 0; counter < 255; counter++) {
        if (transaction[counter].transactionSequenceNumber == 0) {
            transaction[counter] = *transData;
            transaction[counter].transactionSequenceNumber = counter + 1;
        }
    }
    return SERVER_OK;
}

void listSaveTransactions(void) {
    uint23_t counter = 0;
    for (counter = 0; counter < 255; counter++) {
        if (transaction[counter].transactionSequenceNumber != 0) {
            printf("#############################\n");
            printf("Transaction Sequence Number: %d\n", transaction[counter].transactionSequenceNumber);
            printf("Transaction Date: %s\n", transaction[counter].terminalData.transactionDate);
            printf("Transaction Amount: %f\n", transaction[counter].terminalData.transAmount);
            printf("Transaction state: %d\n", transaction[counter].transState);
            printf("Terminal Max Amount: %f\n", transaction[counter].terminalData.maxTransAmount);
            printf("Card holder Name: %s\n", transaction[counter].cardHolderData.cardHolderName);
            printf("Card Expiration Date: %s\n", transaction[counter].cardHolderData.cardExpirationDate);
            printf("###############################\n");
        }
    }
}

void saveTransactionTest(void)
{
    ST_transaction_t transData = { {"John Doe", "1234567890123456", "05/25"}, {100.0, 5000.0, "25/06/2022"}, APPROVED, 0 };
    EN_serverError_t result = saveTransaction(&transData);

    if (result == SERVER_OK)
    {
        printf("Transaction saved successfully.\n");
    }
    else
    {
        printf("Error: Saving transaction failed.\n");
    }
}



