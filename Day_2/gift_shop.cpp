/**
 * @file gift_shop.cpp
 * @author Chris Dickson (cdickson.dev@gmail.com)
 * @brief https://adventofcode.com/2025/day/2
 * @date 2025-12-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

std::pair<int,int> splitRangeString(std::string rangeStr){
    size_t hyphenIndex{};
    hyphenIndex = rangeStr.find('-');
    int startRange = std::stoi(rangeStr.substr(0,hyphenIndex));
    int endRange = std::stoi(rangeStr.substr(hyphenIndex+1));
    return std::pair<int,int>(startRange, endRange);
};

std::vector<std::pair<int,int>> parseInputFile(std::ifstream & input){
    std::string strLine;
    std::vector<std::pair<int,int>> rangeList;
    while (std::getline(input, strLine, ',')){
        std::pair<int,int> range = splitRangeString(strLine);
        std::cout << "Start: " << range.first << " End: " << range.second << std::endl;
        rangeList.push_back(range);
    }
    return rangeList;
};

int main(int argc, char* argv[] ){
    // Ensure 2 arguments total
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

    // Parse input
    std::vector<std::pair<int,int>> rangeList = parseInputFile(inputFile);

    // Loop through range list
    // Check if number of digits is even or odd
    // If both odd and same length, skip that range

}