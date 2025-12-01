/**
 * @file secret_entrance.cpp
 * @author Chris Dickson (cdickson.dev@gmail.com)
 * @brief https://adventofcode.com/2025/day/1
 * @date 2025-12-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 */
struct rotation{
    //
    std::string direction;

    //
    int distance;
};

// Parse input file and return array of pairs
const std::vector<rotation> parseInput(){

};

// rotate dial function, performs a single rotation



int main(int argc, char* argv[]){

    if (argc <= 1){
        std::cout << "Error, incorrect number of arguments: " << argc << std::endl;

		return 1;
    }

    int zeroCount{0};

    // File input


    // Call parse input file function

    int dialPosition{50};
    std::cout << "The dial starts by pointing at " << dialPosition << "." << std::endl;

    // Loop through list from input file

    // Use rotate dial function on each item in the list


    return 0;
}
