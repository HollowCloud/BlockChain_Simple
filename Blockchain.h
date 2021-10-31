#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include <utility>
#include <vector>
#include "Block.h"

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H




class Blockchain{

public:

    vector<Block> chain;

    //Has one constructor:
    Blockchain(){
        Block firstBlock = createFirstBlock();
        chain.push_back(firstBlock);
    }
//Methods:
    Block createFirstBlock()
    {
        time_t current;
        // Setup Initial Transaction Data
        TransactionData dataFirstBlock(0, " FirstBlock ", "FirstBlock", time(&current));

        Block firstBlock (0, dataFirstBlock, 0);
        Block c;
        c.getIndex();
        c.getTransactionData();
        c.getPrevHash();
        return firstBlock;
    }
    void addBlock(TransactionData data)
    {
        int index = (int)chain.size();
        size_t previousHash = getLatestBlock()->getBlockHash();
        Block newBlock(index, std::move(data), previousHash);
        chain.push_back(newBlock);
    }
    Block *Blockchain::getLatestBlock()
    {
        return &chain.back();
    }

    void printBlockchain();

    bool isBlockChainValid();

};




#endif //BLOCKCHAIN_BLOCKCHAIN_H
