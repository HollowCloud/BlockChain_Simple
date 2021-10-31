#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include "Block.h"


bool Block::isBlockChainValid()
{
    return generateHash() == getBlockHash();
}