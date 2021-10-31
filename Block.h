#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include <set>
#include "TransactionData.h"


#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H



class Block{

public:
    int index;
    TransactionData transaction_data;
    size_t block_hash;
    size_t prev_hash;
    TransactionData data1;

    Block(){};

    size_t generateHash(){
// creating string of transaction data
        string toHashS = to_string(transaction_data.amount) + transaction_data.receiverKey + transaction_data.senderKey + to_string(transaction_data.timestamp);
// 2 hashes to combine
        hash<string> tDataHash; // hashes transaction data string
        hash<string> prevHash; // re-hashes previous hash (for combination)
// combine hashes and get size_t for block hash
        return tDataHash(toHashS) ^ (prevHash(to_string(prev_hash)) << 1);
    }
//Constructor:
    Block(int index, TransactionData data, size_t prev_hash)
    {
        this->index = index;
        this->data1 = data;
        this->prev_hash = prev_hash;
        this->block_hash = generateHash();
    }
    size_t getBlockHash()
    {
        return block_hash;
    }

    int getIndex() const {
        return index;
    }

    const TransactionData &getTransactionData() const {
        return transaction_data;
    }

    size_t getPrevHash() const {
        return prev_hash;
    }

    bool isBlockChainValid();


};



#endif //BLOCKCHAIN_BLOCK_H
