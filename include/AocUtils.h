#ifndef AOC_UTILS_HPP
#define AOC_UTILS_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>

class AocUtils {
public:
    // Read entire file and return as vector of strings (lines)
    static std::vector<std::string> readFileLines(const std::string& filename) {
        std::vector<std::string> lines;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Could not open file: " << filename << std::endl;
            return lines;
        }

        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    // Split string by delimiter
    static std::vector<std::string> split(const std::string& s, char delimiter = ' ') {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }

    // Convert string to integer with error handling
    static int stringToInt(const std::string& s, int defaultValue = 0) {
        try {
            return std::stoi(s);
        } catch (...) {
            return defaultValue;
        }
    }

    // Convert string to long long with error handling
    static long long stringToLongLong(const std::string& s, long long defaultValue = 0) {
        try {
            return std::stoll(s);
        } catch (...) {
            return defaultValue;
        }
    }

    // Regular expression match
    static std::vector<std::string> regexMatch(const std::string& input, const std::string& pattern) {
        std::regex re(pattern);
        std::smatch matches;
        std::vector<std::string> results;

        if (std::regex_search(input, matches, re)) {
            for (size_t i = 1; i < matches.size(); ++i) {
                results.push_back(matches[i].str());
            }
        }
        return results;
    }

    // Sum of all elements in a container
    template <typename T>
    static T sum(const T& container) {
        return std::accumulate(container.begin(), container.end(), T(0));
    }

    // Product of all elements in a container
    template <typename T>
    static T product(const T& container) {
        return std::accumulate(container.begin(), container.end(), T(1), std::multiplies<typename T::value_type>());
    }

    // Find minimum element in a container
    template <typename T>
    static typename T::value_type min(const T& container) {
        return *std::min_element(container.begin(), container.end());
    }

    // Find maximum element in a container
    template <typename T>
    static typename T::value_type max(const T& container) {
        return *std::max_element(container.begin(), container.end());
    }

    // Manhattan distance for 2D grid
    static int manhattanDistance(int x1, int y1, int x2, int y2) {
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    }

    // Euclidean distance for 2D grid
    static double euclideanDistance(int x1, int y1, int x2, int y2) {
        return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    }

    // Greatest Common Divisor using Euclidean algorithm
    static long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Least Common Multiple
    static long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // Binary to decimal conversion
    static long long binaryToDecimal(const std::string& binary) {
        return std::stoll(binary, nullptr, 2);
    }

    // Decimal to binary conversion
    static std::string decimalToBinary(long long decimal) {
        return std::bitset<64>(decimal).to_string();
    }

    // Count occurrences of an element in a container
    template <typename T, typename U>
    static int count(const T& container, const U& element) {
        return std::count(container.begin(), container.end(), element);
    }

    // Check if a value exists in a container
    template <typename T, typename U>
    static bool contains(const T& container, const U& element) {
        return std::find(container.begin(), container.end(), element) != container.end();
    }

    // Trim whitespace from start and end of string
    static std::string trim(const std::string& s) {
        auto start = s.begin();
        while (start != s.end() && std::isspace(*start)) {
            start++;
        }

        auto end = s.end();
        do {
            end--;
        } while (std::distance(start, end) > 0 && std::isspace(*end));

        return std::string(start, end + 1);
    }

    // Join vector of strings with a delimiter
    static std::string join(const std::vector<std::string>& vec, const std::string& delimiter = " ") {
        std::string result;
        for (size_t i = 0; i < vec.size(); ++i) {
            result += vec[i];
            if (i < vec.size() - 1) {
                result += delimiter;
            }
        }
        return result;
    }
};

#endif // AOC_UTILS_HPP