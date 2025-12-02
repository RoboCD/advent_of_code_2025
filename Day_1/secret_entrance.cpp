/**
 * @file secret_entrance.cpp
 * @author Chris Dickson (cdickson.dev@gmail.com)
 * @brief https://adventofcode.com/2025/day/1
 * @date 2025-12-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 */
struct Rotation{
    //
    std::string direction;

    //
    int distance;
};

/**
 * @brief
 * @param line
 * @return Rotation
 */
Rotation convertStringToRotation(std::string line){
    Rotation r{};
    r.direction = line.at(0);
    r.distance = std::stoi(line.substr(1));

    return r;
};

/**
 * @brief
 * @param r
 * @param dialPosition
 */
void rotateDial(Rotation r, int & dialPosition){
    if (r.direction == "R"){
        dialPosition += r.distance;
        if (dialPosition > 99 ){
            dialPosition = dialPosition%100;
        }
    }
    else if (r.direction == "L"){
        dialPosition -= r.distance;
        if (dialPosition < 0 ){
            dialPosition = 100 - std::abs(dialPosition%100);
            // int hundreds{dialPosition%100};
            // dialPosition += (hundreds*100);
        }
    }
    else{
        std::cerr << "Incorrect direction " << r.direction;
    }

};

/**
 * @brief Parse input file and rotate the dial
 * @param input
 * @param dialPosition
 * @param zeroCount
 */
void parseInputAndRotate(std::ifstream & input, int & dialPosition, int & zeroCount){
    std::string strLine;
    std::vector<Rotation> rotationList{};
    while (std::getline(input, strLine)){
        Rotation rLine = convertStringToRotation(strLine);
        // rotate dial function, performs a single Rotation
        rotateDial(rLine, dialPosition);
        std::cout << "The dial is rotated " << strLine << " to point at " << dialPosition << "." << std::endl;
        if (dialPosition == 0){
            zeroCount++;
        }
    }
};


int main(int argc, char* argv[]){
    std::cout << "test";

    if (argc != 2){
        std::cerr << "Error, incorrect number of arguments: " << argc << std::endl;
		return 1;
    }

    int zeroCount{0};

    // File input
    std::ifstream inputFile{argv[1]};
    if (!inputFile)
    {
        std::cerr << "Unable to read " << argv[1] << std::endl;
        return 1;
    }

    // Call parse input file and roate function
    int dialPosition{50};
    std::cout << "The dial starts by pointing at " << dialPosition << "." << std::endl;
    parseInputAndRotate(inputFile, dialPosition, zeroCount);

    std::cout << "Number of times pointing at zero: " << zeroCount;
    return 0;
}
