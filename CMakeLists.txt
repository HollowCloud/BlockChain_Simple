cmake_minimum_required(VERSION 3.20)
project(BlockChain)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlockChain main.cpp TransactionData.h TransactionData.cpp Block.h Block.cpp Blockchain.h Blockchain.cpp Miner.h Miner.cpp)
