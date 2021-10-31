#include <string>
#include <iostream>
using namespace std;
#include <ctime>

#ifndef BLOCKCHAIN_TRANSACTIONDATA_H
#define BLOCKCHAIN_TRANSACTIONDATA_H


class TransactionData{

public:
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;
    TransactionData(double amount, string senderKey, string receiverKey, time_t timestamp){
        this->amount=amount;
        this->senderKey= senderKey;
        this->receiverKey= receiverKey;
        this->timestamp =  timestamp;
    }
    TransactionData(){};

};



#endif //BLOCKCHAIN_TRANSACTIONDATA_H
