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

using Range = std::pair<unsigned long long, unsigned long long>;
using RangeList = std::vector<Range>;

Range splitRangeString(std::string rangeStr){
    size_t hyphenIndex{};
    hyphenIndex = rangeStr.find('-');
    long startRange = std::stoull(rangeStr.substr(0,hyphenIndex));
    long endRange = std::stoull(rangeStr.substr(hyphenIndex+1));
    return Range(startRange, endRange);
};

RangeList parseInputFile(std::ifstream & input){
    std::string strLine;
    RangeList rangeList;
    while (std::getline(input, strLine, ',')){
        Range range = splitRangeString(strLine);
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
    RangeList rangeList = parseInputFile(inputFile);

    // Loop through range list
    // Check if number of digits is even or odd
    // If both odd and same length, skip that range

}