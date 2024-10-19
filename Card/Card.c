/*
* File: card.c
* Author: Mohamed Alaa
*
*created on Aug 8, 2023, 4;30 PM
*/
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
    printf("Enter card Holder name\n");
    scanf("%s", cardData->cardHolderName);
    if (NULL == cardData) {
        return WRONG_NAME;
    }
    int counter = 0;
    for (int i = 0; cardData->cardHolderName[i] != '\0'; i++) {
        counter++;
    }
    if (counter == 0 || counter < 20 || counter>24) {
        return WRONG_NAME;
    }
    return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
    printf("Enter card expiry date\n");
    printf("crad expiry date must be in the format MM/YY \n ");
    scanf("%s", cardData->cardExpirationDate);
    if (NULL == cardData || cardData->cardExpirationDate[2] != '/') {
        return WRONG_EXP_DATE;
    }
    int counter = 0;
    for (int i = 0; cardData->cardExpirationDate[i] != '\0'; i++) {
        counter++;
    }
    if (counter == 0 || counter < 5 || counter>5) {
        return WRONG_EXP_DATE;
    }
    return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData) {

    printf("Enter card's primary Account Number\n");
    scanf("%s", cardData->primaryAccountNumber);
    if (NULL == cardData) {
        return WRONG_NAME;
    }
    int counter = 0;
    for (int i = 0; cardData->primaryAccountNumber[i] != '\0'; i++) {
        counter++;
    }
    if (counter == 0 || counter < 16 || counter>19) {
        return WRONG_PAN;
    }
    return CARD_OK;

}

void getCardHolderNameTest(void) {
    EN_cardError_t ret;
    ST_cardData_t cardData;
    printf("Taster Name: Mohamed Alaa\n");
    printf("Fuction Name: getHolderName\n");

    /*..............test_1.............*/

    printf("test case 1\n");
    printf("input data: MohamedAlaaMohamedSar\n");
    ret = getCardHolderName(&cardData);
    printf("expected result: CARD_OK \n");
    if (ret == CARD_OK) {
        printf("actual result: CARD_OK\n");
    }
    else if (ret == WRONG_NAME) {
        printf("actual result: WORNG_NAME\n");
    }
    /*...............test 2...........*/
    printf("test case 2\n");
    printf("input data: MohamedAlaa\n");
    ret = getCardHolderName(&cardData);
    printf("expected result: WORNG_NAME \n");
    if (ret == CARD_OK) {
        printf("actual result: CARD_OK\n");
    }
    else if (ret == WRONG_NAME) {
        printf("actual result: WORNG_NAME\n");
    }
    /*...............test 3...........*/
    printf("test case 3\n");
    printf("input data: MohamedAlaaMohamedSarhannnnnn\n");
    ret = getCardHolderName(&cardData);
    printf("expected result: WORNG_NAME \n");
    if (ret == CARD_OK) {
        printf("actual result: CARD_OK\n");
    }
    else if (ret == WRONG_NAME) {
        printf("actual result: WORNG_NAME\n");
    }
}

void getCardExpiryDateTest(void) {
    EN_cardError_t ret;
    ST_cardData_t cardData;
    printf("Taster name: Mohamed Alaa\n");
    printf("Function name: getExpiryDate\n");

    /*..........test 1....................*/
    printf("test case1 \n");
    printf("input date: 11/23 \n");
    ret = getCardExpiryDate(&cardData);
    printf("expected result: CARD_OK\n");
    if (ret == CARD_OK) {
        printf("Actual result: CARD_OK\n");
    }
    else if (ret == WRONG_EXP_DATE) {
        printf("Actual result: WRONG_EXP_DATE\n");
    }

    /*..........test 2....................*/
    printf("test case2 \n");
    printf("input date: 11/234 \n");
    ret = getCardExpiryDate(&cardData);
    printf("expected result: WRONG_EXP_DATE\n");
    if (ret == CARD_OK) {
        printf("Actual result: CARD_OK\n");
    }
    else if (ret == WRONG_EXP_DATE) {
        printf("Actual result: WRONG_EXP_DATE\n");
    }

    /*..........test 3....................*/
    printf("test case3 \n");
    printf("input date: 1/2 \n");
    ret = getCardExpiryDate(&cardData);
    printf("expected result: WRONG_EXP_DATE\n");
    if (ret == CARD_OK) {
        printf("Actual result: CARD_OK\n");
    }
    else if (ret == WRONG_EXP_DATE) {
        printf("Actual result: WRONG_EXP_DATE\n");
    }

    /*..........test 4....................*/
    printf("test case 4 \n");
    printf("input date: 22-11 \n");
    ret = getCardExpiryDate(&cardData);
    printf("expected result: WRONG_EXP_DATE\n");
    if (ret == CARD_OK) {
        printf("Actual result: CARD_OK\n");
    }
    else if (ret == WRONG_EXP_DATE) {
        printf("Actual result: WRONG_EXP_DATE\n");
    }
}

void getCardPANTest(void) {
    EN_cardError_t ret;
    ST_cardData_t cardData;
    printf("Taster name: Mohamed Alaa\n");
    printf("Function name: getCardPAN\n");

    /*..........test 1....................*/
    printf("test case1 \n");
    printf("input date: 12345678912345678 \n");
    ret = getCardPAN(&cardData);
    printf("Expected result: CARD_OK\n");
    if (ret == CARD_OK) {
        printf("Actual result : CARD_OK\n");
    }
    else if (ret == WRONG_PAN) {
        printf("Actual result: WRONG_PAN\n");
    }

    /*..........test 2....................*/
    printf("test case1 \n");
    printf("input date: 123456789 \n");
    ret = getCardPAN(&cardData);
    printf("Expected result: WRONG_PAN\n");
    if (ret == CARD_OK) {
        printf("Actual result : CARD_OK\n");
    }
    else if (ret == WRONG_PAN) {
        printf("Actual result: WRONG_PAN\n");
    }
    /*..........test 2....................*/
    printf("test case1 \n");
    printf("input date: 123456789123456789123 \n");
    ret = getCardPAN(&cardData);
    printf("Expected result: WRONG_PAN\n");
    if (ret == CARD_OK) {
        printf("Actual result : CARD_OK\n");
    }
    else if (ret == WRONG_PAN) {
        printf("Actual result: WRONG_PAN\n");
    }
}

