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
#include <regex>

using Range = std::pair<unsigned long long, unsigned long long>;
using RangeList = std::vector<Range>;

Range splitRangeString(std::string rangeStr){
    size_t hyphenIndex{};
    hyphenIndex = rangeStr.find('-');
    unsigned long long startRange = std::stoull(rangeStr.substr(0,hyphenIndex));
    unsigned long long endRange = std::stoull(rangeStr.substr(hyphenIndex+1));
    return Range(startRange, endRange);
};

RangeList parseInputFile(std::ifstream & input){
    std::string strLine;
    RangeList rangeList;
    while (std::getline(input, strLine, ',')){
        Range range = splitRangeString(strLine);
        // std::cout << "Start: " << range.first << " End: " << range.second << std::endl;
        rangeList.push_back(range);
    }
    return rangeList;
};

bool isIdInvalid(unsigned long long id){
    std::string stringId = std::to_string(id);

    int idLength = stringId.length();
    // If idLength is odd, return false
    if (idLength%2 != 0){
        return false;
    }

    unsigned long long idHalf1 = std::stoull(stringId.substr(0,idLength/2));
    unsigned long long idHalf2 = std::stoull(stringId.substr((idLength/2)));
    return idHalf1 == idHalf2;
};

bool isRangeValid(Range range){
    int firstLength = std::to_string(range.first).length();
    int secondLength = std::to_string(range.second).length();
    bool firstEven{firstLength%2 == 0};
    bool secondEven{secondLength%2 == 0};

    // If both odd and same length, return false
    if (!(firstEven && secondEven) && (firstLength == secondLength)){
        return false;
    }
    // If either length is even, return true
    return true;
};

std::vector<unsigned long long> getInvalidIds(Range range){
    std::vector<unsigned long long> invalidIdsList{};
    // Check if number of digits is even or odd
    // If both odd and same length, skip that range
    if (!isRangeValid(range)){
        return invalidIdsList;
    }

    for (unsigned long long id = range.first; id <= range.second; id++){
        if(isIdInvalid(id)){
            std::cout << "Invalid Id: " << id << std::endl;
            invalidIdsList.push_back(id);
        }
    }
    return invalidIdsList;
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
    unsigned long long totalInvalidIds{0};
    for (const auto & r: rangeList){
        std::cout << "Start: " << r.first << " End: " << r.second << std::endl;
        auto invalidIds = getInvalidIds(r);
        for (const auto & i: invalidIds){
            totalInvalidIds += i;
        }
    }

    std::cout << "Invalid IDs sum: " << totalInvalidIds << std::endl;
}