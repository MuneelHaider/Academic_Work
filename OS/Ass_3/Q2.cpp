#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*

    Muneel Haider
    21i-0640
    Assignment 3
    Question 2

*/

double userAccountBalance = 1000.0;
double recipientAccountBalance = 500.0;
double transactionFee = 0.05;

pthread_mutex_t accountMutex;

void* deductAmount(void* amount) {

    pthread_mutex_lock(&accountMutex);
    
    double transactionAmount = *(double*)amount;
    userAccountBalance -= transactionAmount;
    
    printf("Deducting %.2f from user's account...\n", transactionAmount);
    sleep(2);
    
    printf("Deducted %.2f from user's account. New balance: %.2f\n", transactionAmount, userAccountBalance);
    pthread_mutex_unlock(&accountMutex);
    
    return NULL;
}

void* addAmountToRecipient(void* amount) {
    
    pthread_mutex_lock(&accountMutex);

    double transactionAmount = *(double*)amount;
    recipientAccountBalance += transactionAmount;

    printf("Adding %.2f to recipient's account...\n", transactionAmount);
    sleep(2);

    printf("Added %.2f to recipient's account. New balance: %.2f\n", transactionAmount, recipientAccountBalance);
    pthread_mutex_unlock(&accountMutex);

    return NULL;
}

void* calculateTransactionFee(void* amount) {

    pthread_mutex_lock(&accountMutex);

    double transactionAmount = *(double*)amount;
    double fee = transactionAmount * transactionFee;

    userAccountBalance -= fee; // Deduct fee from user's account

    printf("Calculating transaction fee...\n");
    sleep(1);

    printf("Transaction fee: %.2f, User's account new balance after fee: %.2f\n", fee, userAccountBalance);
    pthread_mutex_unlock(&accountMutex);

    return NULL;
}

void* updateTransactionHistory(void* arg) {

    pthread_mutex_lock(&accountMutex);

    printf("Updating transaction history...\n");
    sleep(3);

    printf("Transaction history updated.\n");
    pthread_mutex_unlock(&accountMutex);

    return NULL;
}

void* sendEmailNotification(void* arg) {

    printf("Sending email notification...\n");
    sleep(2);

    printf("Email notification sent to users.\n");

    return NULL;
}

int main() {
    
    pthread_mutex_init(&accountMutex, NULL);
    pthread_t thread;

    double transactionAmount = 200.0;

    pthread_create(&thread, NULL, deductAmount, &transactionAmount);
    pthread_join(thread, NULL);

    pthread_create(&thread, NULL, addAmountToRecipient, &transactionAmount);
    pthread_join(thread, NULL);

    pthread_create(&thread, NULL, calculateTransactionFee, &transactionAmount);
    pthread_join(thread, NULL);

    pthread_create(&thread, NULL, updateTransactionHistory, NULL);
    pthread_join(thread, NULL);

    pthread_create(&thread, NULL, sendEmailNotification, NULL);
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&accountMutex);

    pthread_exit(0);
}
