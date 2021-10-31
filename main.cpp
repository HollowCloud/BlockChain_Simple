#include "TransactionData.h"
#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include "Blockchain.h"
#include "Miner.h"
#include <thread>


void function(){

    Miner n;
    n.mine();

}


void func_for_first(){

        Blockchain b;
//    Miner m;
//    m.mine();

    // Data for first block
    time_t data1Time;
    TransactionData data1(2.2, "Cloud", "Gill", time(&data1Time));
    b.addBlock(data1);

    time_t data2Time;
    TransactionData data2(1.1, "Kail", "Frederic", time(&data2Time));
    b.addBlock(data2);

    // Prints the Information About the Block
    b.printBlockchain();


    // Checking the hashes
    cout << "\nIs chain still valid? \n", b.isBlockChainValid();

}

void func_for_last(){

        Blockchain b;
//    Miner m;
//    m.mine();

    // Data for first block
    time_t data1Time;
    TransactionData data1(3.2, "Daniels", "Witch", time(&data1Time));
    b.addBlock(data1);

    time_t data2Time;
    TransactionData data2(0.121, "Onei", "Gendolf", time(&data2Time));
    b.addBlock(data2);

    // Prints the Information About the Block
    b.printBlockchain();


    // Checking the hashes
    cout << "\nIs chain still valid? \n", b.isBlockChainValid();

}


int main() {
    cout << " HEY " << endl;
    thread new_thread1(func_for_first);
    thread new_thread2(func_for_last);
    cout << "WAITING...." << endl;
    new_thread1.join();
    cout << endl;
    cout << endl;
    new_thread2.join();

//    Blockchain b;
//    Miner m;
//    m.mine();

//    // Data for first block
//    time_t data1Time;
//    TransactionData data1(2.2, "Cloud", "Gill", time(&data1Time));
//    b.addBlock(data1);
//
//    time_t data2Time;
//    TransactionData data2(1.1, "Kail", "Frederic", time(&data2Time));
//    b.addBlock(data2);
//
//    // Prints the Information About the Block
//    b.printBlockchain();
//
//    m.mine(b, data2);
//
//    // Checking the hashes
//    cout << "\nIs chain still valid? \n", b.isBlockChainValid();

//    // This is For a Hacker
//    Block *hacked = b.getLatestBlock();
//    hacked->data1.amount = 21000;
//    hacked->data1.receiverKey = "Many";
//
//    // Prints Information
//    b.printBlockchain();
//
//    // We will see that it is not valid as blockchain stores the information from previous block
//    cout << "\nIs chain still valid? \n" << b.isBlockChainValid();

    return 0;

}
