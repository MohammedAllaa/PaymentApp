/*
* File: terminal.c
* Author: Mohamed Alaa
*
*created on Aug 8, 2023, 4;30 PM
*/
#include "terminal.h"

EN_terminalError_t gettransactionDate(ST_terminalData_t* termData) {
    printf("Please enter the transaction date (DD/MM/YYYY): ");
    fgets((char*)termData->transactionDate, 11, stdin);

    size_t dateLength = strlen((char*)termData->transactionDate);
    if (termData->transactionDate[dateLength - 1] == '\n')
    {
        termData->transactionDate[dateLength - 1] = '\0';
        dateLength--;
    }

    if (dateLength != 10 || termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
    {
        return WRONG_DATE;
    }

    return TERMINAL_OK;
}

void getTransactionDateTest(void) {
    EN_terminalError_t ret;
    ST_terminalData_t termData;

    printf("Tester name: Mohamed Alaa\n");
    printf("Function name: getTransactionDate\n");

    /*..........test 1........................*/
    printf("test case 1\n");
    printf("input data: 22/11/2003\n");
    ret = gettransactionDate(&termData);
    printf("expected rsult: TERMINAL_OK \n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == WRONG_DATE) {
        printf("Actual result: WRONG_DATE\n");
    }

    /*..........test 2........................*/
    printf("test case 2\n");
    printf("input data: 22/11\n");
    ret = gettransactionDate(&termData);
    printf("expected rsult: WRONG_DATE \n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == WRONG_DATE) {
        printf("Actual result: WRONG_DATE\n");
    }

    /*..........test 3........................*/
    printf("test case 3\n");
    printf("input data: 22/11/20003\n");
    ret = gettransactionDate(&termData);
    printf("expected rsult: WRONG_DATE \n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == WRONG_DATE) {
        printf("Actual result: WRONG_DATE\n");
    }
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
    int cardYear = (cardData->cardExpirationDate[3] - '0') * 10 + (cardData->cardExpirationDate[4] - '0');
    int cardMonth = (cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0');

    int transYear = (termData->transactionDate[8] - '0') * 10 + (termData->transactionDate[9] - '0');
    int transMonth = (termData->transactionDate[3] - '0') * 10 + (termData->transactionDate[4] - '0');

    if (transYear > cardYear || (transYear == cardYear && transMonth > cardMonth))
    {
        return EXPIRED_CARD;
    }

    return TERMINAL_OK;
}

void isCardExpiredTest(void) {
    EN_terminalError_t ret;
    ST_terminalData_t termData;
    ST_cardData_t cardData;

    printf("Tester name: Mohamed Alaa\n");
    printf("Function name: isCarsExpired\n");

    /*.........test 1...........................*/
    printf("Test case 1\n");
    printf("input date: 12/26 , 22/11/25\n");
    ret = isCardExpired(&cardData, &termData);

    printf("Expected result: TERMINAL_OK\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == EXPIRED_CARD) {
        printf("Actual result: EXPIRED_CARD\n");
    }

    /*.........test 2...........................*/
    printf("Test case 2\n");
    printf("input date: 12/26 , 22/11/03\n");
    ret = isCardExpired(&cardData, &termData);

    printf("Expected result: TERMINAL_OK\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == EXPIRED_CARD) {
        printf("Actual result: EXPIRED_CARD\n");
    }

    /*.........test 3...........................*/
    printf("Test case 3\n");
    printf("input date: 12/26 , 22/11/26\n");
    ret = isCardExpired(&cardData, &termData);

    printf("Expected result: TERMINAL_OK\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == EXPIRED_CARD) {
        printf("Actual result: EXPIRED_CARD\n");
    }
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
    printf("Enter transacion amout\n");
    scanf("%f", &termData->transAmount);
    if (NULL == termData) {
        return INVALID_AMOUNT;
    }
    if (termData->transAmount <= 0) {
        return INVALID_AMOUNT;
    }
    return TERMINAL_OK;
}

void  getTransactionAmountTest(void) {
    EN_terminalError_t ret;
    ST_terminalData_t termData;

    printf("Tester name: Mohamed Alaa\n");
    printf("Function name: getTransactionAmount\n");

    /*..........test 1........................*/
    printf("test case 1\n");
    printf("input data: 20.0\n");
    ret = getTransactionAmount(&termData);
    printf("Expected result: TERMINAL_OK\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == INVALID_AMOUNT) {
        printf("Actual result: INVALID_AMOUNT\n");
    }


    /*..........test 2........................*/
    printf("test case 2\n");
    printf("input data: 0.0");

    ret = getTransactionAmount(&termData);
    printf("Expected result: INVALID_AMOUNT\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == INVALID_AMOUNT) {
        printf("Actual result: INVALID_AMOUNT\n");
    }

    /*..........test 3........................*/
    printf("test case 3\n");
    printf("input data: -2.0");

    ret = getTransactionAmount(&termData);
    printf("Expected result: INVALID_AMOUNT\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == INVALID_AMOUNT) {
        printf("Actual result: INVALID_AMOUNT\n");
    }
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
    getTransactionAmount(termData);
    printf("Enter Max allawed amount\n");
    scanf("%f", &termData->maxTransAmount);
    if (NULL == termData) {
        return EXCEED_MAX_AMOUNT;
    }
    if (termData->transAmount > termData->maxTransAmount) {
        return EXCEED_MAX_AMOUNT;
    }
    return TERMINAL_OK;
}

void isBelowMaxAmountTest(void) {
    EN_terminalError_t ret;
    ST_terminalData_t termData;

    printf("Tester name: Mohamed Alaa\n");
    printf("Function name: isBelowMaxAmount\n");

    /*..........test 1........................*/
    printf("test case 1\n");
    printf("input data: 3 , 5\n");
    ret = isBelowMaxAmount(&termData);
    printf("Expected result: TERMINAL_OK\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == EXCEED_MAX_AMOUNT) {
        printf("Actual result: EXCEED_MAX_AMOUNT");
    }

}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
    printf("Enter maximum allowed amount\n");
    scanf("%f", &maxAmount);
    termData->maxTransAmount = maxAmount;
    if (termData->maxTransAmount <= 0) {
        return INVALID_MAX_AMOUNT;
    }
    return TERMINAL_OK;
}

void setMaxAmountTest(void) {
    EN_terminalError_t ret;
    ST_terminalData_t termData;
    float maxAmount;

    printf("Tester name: Mohamed Alaa\n");
    printf("Function name: setMaxAmount\n");
    /*..........test 1........................*/
    printf("test case 1\n");
    printf("input data: 20.0 \n");
    ret = setMaxAmount(&termData, maxAmount);
    printf("Expected result: TERMINAL_OK\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == INVALID_MAX_AMOUNT) {
        printf("Actual result: INVALID_MAX_AMOUNT\n");
    }
    /*..........test 2........................*/
    printf("test case 2\n");
    printf("input data: 0.0 \n");
    ret = setMaxAmount(&termData, maxAmount);
    printf("Expected result: INVALID_MAX_AMOUNT\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == INVALID_MAX_AMOUNT) {
        printf("Actual result: INVALID_MAX_AMOUNT\n");
    }
    /*..........test 3........................*/
    printf("test case 3\n");
    printf("input data: -30.0 \n");
    ret = setMaxAmount(&termData, maxAmount);
    printf("Expected result: INVALID_MAX_AMOUNT\n");
    if (ret == TERMINAL_OK) {
        printf("Actual result: TERMINAL_OK\n");
    }
    else if (ret == INVALID_MAX_AMOUNT) {
        printf("Actual result: INVALID_MAX_AMOUNT\n");
    }
}




