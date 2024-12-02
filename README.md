# Advent of Code 2024 C++ Solutions

## Project Overview

This repository contains my solutions for the Advent of Code 2024 programming challenge, implemented in modern C++. Advent of Code is an annual coding event where participants solve a series of programming puzzles, one for each day leading up to Christmas.

### Project Features
- Modular C++ implementation
- CMake-based build system
- Comprehensive error handling
- Organized project structure
- Detailed solutions for each day's challenges

## 🛠 Prerequisites

### Required Tools
- C++ Compiler with C++17 support (GCC 8+, Clang 7+, MSVC 19.15+)
- CMake (version 3.12 or higher)
- Git (optional, for version control)


## Project Structure

```
aoc2024/
│
├── CMakeLists.txt         # Main build configuration
├── README.md              # Project documentation
│
├── src/                   # Source code directory
│   ├── day01/             # Day 1 specific implementation
│   │   ├── day01.cpp
│   │   └── day01.h
│   │
│   ├── day02/             # Day 2 specific implementation
│   │   ├── day02.cpp
│   │   └── day02.h
│   │
│   └── main.cpp           # Main application entry point
│
├── input/                 # Input files for each day's puzzle
│   ├── day01_puzzle_input.txt
│   └── day02_puzzle_input.txt
│
└── tests/                 # (Future) Unit tests directory
```

## Build Instructions

### 1. Clone the Repository
```bash
git clone https://github.com/lvntky/aoc2024.git
cd aoc2024
```

### 2. Create Build Directory
```bash
mkdir build
cd build
```

### 3. Configure with CMake
```bash
# Basic configuration
cmake ..

# For debug build
cmake -DCMAKE_BUILD_TYPE=Debug ..

# For release build
cmake -DCMAKE_BUILD_TYPE=Release ..
```

### 4. Build the Project
```bash
# On Unix-like systems
make

# On Windows with Visual Studio
cmake --build . --config Release
```

## Running Solutions

### General Usage
```bash
# Run a specific day's solution
./aoc2024 <day_number> <input_file_path>

# Examples
./aoc2024 1 input/day01_puzzle_input.txt
./aoc2024 2 input/day02_puzzle_input.txt
```

## Troubleshooting

### Common Issues
- Ensure input file paths are correct
- Check file read permissions
- Verify CMake and compiler versions

### Debugging Tips
- Use verbose CMake output: `cmake -DCMAKE_VERBOSE_MAKEFILE=ON ..`
- Enable compiler warnings
- Use debugger for complex logic issues

##  Coding Standards

### General Guidelines
- Follow modern C++ practices
- Use C++17/C++20 features
- Prioritize readability and performance
- Include comprehensive error handling
- Write self-documenting code

### Recommended Practices
- Use meaningful variable and function names
- Add comments for complex logic
- Handle potential exceptions
- Optimize for both time and space complexity

## Contributing

### Workflow
1. Fork the repository
2. Create a feature branch (`git checkout -b day-X-solution`)
3. Implement your solution
4. Write tests (if applicable)
5. Create a pull request

### Code Review Checklist
- Correct solution implementation
- Efficient algorithm
- Proper error handling
- Clean, readable code
- Follows project structure


## License
Mit

## Acknowledgments
- Eric Wastl for creating Advent of Code
- The C++ community for continuous support and innovation

---

**Happy Coding! 🎄**