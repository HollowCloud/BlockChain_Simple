#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include "Blockchain.h"

bool Blockchain::isBlockChainValid() {

    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it) {
        Block currentBlock = *it;
        if (!currentBlock.isBlockChainValid()) {
            return false;
        }

        // Don't forget to check if this is the first item
        if (it != chain.begin()) {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPrevHash() != previousBlock.getBlockHash()) {
                return false;
            }
        }

    }
}


void Blockchain::printBlockchain() {

    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        cout << "\n\nBlock *****************************************" << endl;
        cout << "\nIndex: " << currentBlock.getIndex();
        cout << "\nAmount: " << currentBlock.data1.amount;
        cout << "\nSenderKey: " << currentBlock.data1.senderKey.c_str();
        cout << "\nReceiverKey: " <<  currentBlock.data1.receiverKey.c_str();
        cout << "\nTimestamp: " <<  currentBlock.data1.timestamp;
        cout << "\nHash: " <<  currentBlock.getBlockHash();
        cout << "\nPrevious Hash: " << currentBlock.getPrevHash();
        cout << "\nIs Block Valid?: " <<  currentBlock.isBlockChainValid();
    }

}