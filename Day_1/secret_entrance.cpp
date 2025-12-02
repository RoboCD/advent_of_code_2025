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
 * @brief Rotate the dial with 1 rotation (Part 1)
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
            int remainder = (dialPosition%100);
            if (remainder == 0){
                dialPosition = 0;
            }
            else{
                dialPosition = (100 - std::abs(remainder))%100;
            }
        }
    }
    else{
        std::cerr << "Incorrect direction " << r.direction;
    }
};

/**
 * @brief
 * @param r
 * @param dialPosition
 * @return int Number of times the dial passed 0
 */
int rotateDial2(Rotation r, int & dialPosition){
    int zeroPasses{r.distance/100};
    int startPosition = dialPosition;

    // Turn dial based on direction
    if (r.direction == "R"){
        dialPosition += (r.distance)%100;
    }
    else if (r.direction == "L"){
        dialPosition -= (r.distance)%100;
    }
    else{
        std::cerr << "Incorrect direction " << r.direction;
    }

    if (dialPosition > 99 ){
        if (startPosition != 0){
            zeroPasses++;
        }
        dialPosition = dialPosition%100;
    }
    else if (dialPosition < 0 ){
        if (startPosition != 0){
            zeroPasses++;
        }
        int remainder = (dialPosition%100);
        dialPosition = (100 + remainder)%100;
    }
    else if(dialPosition == 0){
        zeroPasses++;
    }

    return zeroPasses;
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

        // Part 1 - Only count landing on 0
        // rotateDial(rLine, dialPosition);
        // std::cout << "The dial is rotated " << strLine << " to point at " << dialPosition << "." << std::endl;
        // if (dialPosition == 0){
        //     zeroCount++;
        // }

        // Part 2 - Count all times passing 0
        int zeroPasses = rotateDial2(rLine, dialPosition);
        if (zeroPasses > 0){
            std::cout << "The dial is rotated " << strLine << " to point at " << dialPosition
                      << "; during this rotation, it points at 0 " << zeroPasses << " time(s)." << std::endl;
            zeroCount += zeroPasses;
        }
        else {
            std::cout << "The dial is rotated " << strLine << " to point at " << dialPosition << "." << std::endl;
        }

    }
};


int main(int argc, char* argv[]){
    std::cout << std::endl;
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
