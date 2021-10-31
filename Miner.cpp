#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include <set>
#include <random>
#include "Miner.h"



void Miner::mine() {

    Blockchain b;

    srand(time(NULL));

    int n = (rand()%10) + 100;
    int n1 = (rand()%10) + 100;
    int answer;
    cout << "---------------Please Answer 1 Simple Math Question-----------------" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "What is the output of: " << n << " + " << n1 << " = ?" << endl;
    cin >> answer;
    int plus = n+n1;

    if(answer == plus){
        cout << "Information Successfully Inserted: " << endl;
        cout << endl;
        cout << endl;
        // Data for first block
        time_t data1Time;
        TransactionData data1(2.2, "Cloud", "Gill", time(&data1Time));
        b.addBlock(data1);

        time_t data2Time;
        TransactionData data2(1.1, "Kail", "Frederic", time(&data2Time));
        b.addBlock(data2);

        // Prints the Information About the Block
        b.printBlockchain();

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

    } else {
        cout << "Unfortunately not correct..." << endl;
        cout << "Try Again Next Time... " << endl;
    }







    // Checking the hashes
    cout << "\nIs chain still valid? \n", b.isBlockChainValid();





}
