#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// Day headers
#include "day01/day01.h"
#include "day02/day02.h"

namespace fs = std::filesystem;

void run_day(int day, const std::string& input_path) {
    std::cout << "Day " << day << "\n";

    // Validate file exists
    if (!fs::exists(input_path)) {
        throw std::runtime_error("Input file does not exist: " + input_path);
    }

    switch(day) {
        case 1:
            std::cout << "Part 01:" << "\n";
            day01::printDistance(input_path);
            std::cout << "Part 02:" << "\n";
            day01Part02::printSimilarity(input_path);
            break;
        case 2:
            std::cout << "Part 01:" << "\n";
            day02::printValidRows(input_path);
            std::cout << "Part 02:" << "\n";
            day02Part02::printTolerated(input_path);
            break;
        default:
            std::cerr << "Day " << day << " not implemented yet.\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <day_number> <input_file_path>\n";
        std::cerr << "Example: " << argv[0] << " 2 input/day02_puzzle_input.txt\n";
        return 1;
    }

    try {
        int day = std::stoi(argv[1]);
        std::string input_path = argv[2];
        run_day(day, input_path);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}