/**
 * @file lobby.cpp
 * @author Chris Dickson (cdickson.dev@gmail.com)
 * @brief https://adventofcode.com/2025/day/3
 * @date 2025-12-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int parseInputJoltageBanks(std::ifstream & input){
    std::string bank;
    int totalJoltage{0};
    while (std::getline(input, bank)){
        int bankSize = bank.length();
        // std::array<int,bankSize> bankArray{};
        std::vector<int> bankArray(bankSize);
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
}