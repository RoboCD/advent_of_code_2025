/**
 * @file lobby.cpp
 * @author Chris Dickson (cdickson.dev@gmail.com)
 * @brief https://adventofcode.com/2025/day/3
 * @date 2025-12-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

int parseInputJoltageBanks(std::ifstream & input){
    std::string bank{};
    int totalJoltage{0};
    while (std::getline(input, bank, '\n')){
        std::cout << "bank: " << bank << "." << std::endl;
        std::size_t bankSize = bank.size();
        // std::cout << bank.size() << std::endl;

        std::vector<int> bankArray(bankSize);
        // std::map<int,int> bankArray;

        for (std::size_t i = 0; i < bankSize; i++){
            // Subtract '0' to convert the ASCII to the actual digit value
            bankArray[i] = bank[i] - '0';
        }
        std::sort(bankArray.begin(), bankArray.end(), [](int a, int b){
            return a > b;
        });

        // std::cout << bankArray.size() << std::endl;
        std::cout << "front " << bankArray.front() << std::endl;
        // std::cout << "front " << bankArray << std::endl;
        std::cout << "back "  << bankArray.back() << std::endl;

        // int firstIndex{0};
        // int secondIndex{-1};
        std::string firstJolt{};
        std::string secondJolt{};
        std::cout << "bank string end " << (bank[bank.size()-1] - '0') << std::endl;
        // If maximum value at the end of the bank:
        // Use the next highest value in the sorted array as the first value

        int lastJolt = static_cast<int>(bank[bank.size()-1]-'0');
        if (bankArray.front() == lastJolt){
            // std::next(bankArray.begin(), 1);
            // firstIndex++;
            std::cout << "at end" << std::endl;
            firstJolt = std::to_string(bankArray[1]);
        }
        else{
            // If maximum value not at the end of the bank:
            // Use that maximum value in the sorted array as the first value
            firstJolt = std::to_string(bankArray.front());
        }
        std::cout << "firstJolt " << firstJolt << std::endl;
        size_t firstIndex = bank.find(firstJolt);
        std::string bankSubset = bank.substr(firstIndex+1,bank.length());
        std::vector<int> bankArraySub(bankSubset.size());

        for (std::size_t i = 0; i < bankSubset.size(); i++){
            // Subtract '0' to convert the ASCII to the actual digit value
            bankArraySub.push_back(bankSubset[i] - '0');
        }
        std::sort(bankArraySub.begin(), bankArraySub.end(), [](int a, int b){
            return a > b;
        });

        secondJolt = std::to_string(bankArraySub.front());

        std::cout << firstJolt << secondJolt << std::endl;

        int bankJoltage = std::stoi(firstJolt + secondJolt);
        totalJoltage+=(bankJoltage);
    }
    return totalJoltage;
};


int main (int argc, char* argv[]){

    if (argc != 2){
        std::cerr << "Error, incorrect number of arguments: " << argc << std::endl;
		return 1;
    }

    // File input
    std::ifstream inputFile{argv[1]};
    if (!inputFile)
    {
        std::cerr << "Unable to read " << argv[1] << std::endl;
        return 1;
    }

    int totalJoltage = parseInputJoltageBanks(inputFile);

    // Loop through list in input file
    // Create a fixed array for the current bank (line) in the list

    // Create a sorted copy of this bank
    // Check if the maximum value is positioned at the end of the bank or not

    // If maximum value not at the end of the bank:
    // Use that maximum value in the sorted array as the first value

    // If maximum value at the end of the bank:
    // Use the next highest value in the sorted array as the first value

    // Take a sub section of the array starting after that first value
    // Sort that array and return the highest number

    std::cout << "total: " << totalJoltage << std::endl;
}
