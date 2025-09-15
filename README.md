# Competitive Programming Solutions Repository

This repository contains a comprehensive collection of competitive programming solutions across multiple platforms including Codeforces, CodeChef, AtCoder, CSES, and LeetCo---

**Note**: This repository represents an ongoing journey in competitive programming, with solutions spanning multiple years of contests and practice across various platforms. The collection continues to grow with participation in new contests and exploration of advanced algorithmic concepts. It serves as both a showcase of problem-solving journey and a reference for algorithms and data structures commonly used in competitive programming.

## Table of Contents

- [Overview](#overview)
- [Repository Structure](#repository-structure)
- [Platforms Covered](#platforms-covered)
  - [AtCoder](#atcoder)
  - [Codeforces](#codeforces)
  - [CodeChef](#codechef)
  - [CSES Problem Set](#cses-problem-set)
  - [LeetCode](#leetcode)
  - [NITR Contest](#nitr-contest)
- [Educational Content](#educational-content)
  - [CP Algorithms](#cp-algorithms)
  - [Codeforces Educational](#codeforces-educational)
  - [AtCoder DP Contest](#atcoder-dp-contest)
  - [Tree Basics](#tree-basics)
- [Setup and Usage](#setup-and-usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)

## Overview

This repository contains solutions to competitive programming problems from various online judges and contests. The solutions are primarily written in C++ and follow competitive programming best practices with optimized I/O and efficient algorithms.

Each solution includes:

- Source code with proper comments and explanations
- Optimized implementations for contest environments
- Standard competitive programming template usage

## Repository Structure

The repository is organized into platform-specific directories, each containing solutions categorized by contest or problem type:

```
CP/
├── AtCoder/                    # AtCoder contest solutions
├── AtCoder-DP/                 # AtCoder DP contest problems
├── CF-EDU-BS/                  # Codeforces Educational Binary Search
├── CF-EDU-TwoP/                # Codeforces Educational Two Pointers
├── Codechef/                   # CodeChef contest solutions
├── Codeforces/                 # Codeforces contest solutions
├── CP Algos/                   # Algorithm implementations
├── CSES/                       # CSES Problem Set solutions
├── LeetCode/                   # Selected LeetCode problems
├── NITR Contest/               # NITR specific contest problems
├── Picture-References-CP/      # Visual references and diagrams
└── Tree-Basics-CF/             # Tree algorithm fundamentals
```

## Platforms Covered

### AtCoder

Contains solutions from AtCoder Beginner Contests (ABC) and regular contests. Problems are organized by contest number and difficulty level.

- **File Format**: `{contest}{problem}.cpp` (e.g., `abc384A.cpp`)

### Codeforces

Comprehensive collection of Codeforces solutions spanning various contest types and difficulty levels.

- **File Format**: `{contest_id}{problem}.cpp` (e.g., `2136A.cpp`)

### CodeChef

Solutions from CodeChef contests including Long Challenge, Cook-Off, and Lunchtime contests.

- **File Format**: `{contest_id}{problem}.cpp` or `CC{contest}{problem}.cpp`

### CSES Problem Set

Systematic solutions to the CSES Problem Set, organized by topic areas:

#### Dynamic Programming

- Array Description, Book Shop, Coin Problems
- Edit Distance, Grid Paths, LCS, LIS
- Rectangle Cutting, Removal Game
- **Total**: 22+ DP problems solved

#### Graph Algorithms

- Building Roads/Teams, Counting Rooms
- Shortest Routes, Flight problems
- Cycle detection, Topological sorting
- **Total**: 30+ graph problems solved

#### Range Queries

- Static and Dynamic range queries
- Segment tree implementations
- **Total**: 8 range query problems

#### Tree Algorithms

- Tree diameter, distances, matching
- Company queries, path counting
- **Total**: 10+ tree algorithm problems

### LeetCode

Selected challenging and educational problems from LeetCode that complement competitive programming skills.

### NITR Contest

Solutions from institution-specific programming contests at NIT Rourkela.

## Educational Content

### CP Algorithms

A curated collection of fundamental algorithms and data structures:

- **Graph Algorithms**: Dijkstra, Bellman-Ford, Floyd-Warshall, MST
- **Advanced Topics**: Kosaraju SCC, Topological Sort, Euler paths
- **Data Structures**: Segment Tree implementations
- **Tree Algorithms**: Tree diameter calculation

### Codeforces Educational

Structured learning paths for specific algorithmic techniques:

#### Binary Search (CF-EDU-BS)

- Progressive difficulty levels (Step 1-5)
- Covers basic to advanced binary search applications
- **Total**: 25+ binary search problems

#### Two Pointers (CF-EDU-TwoP)

- Systematic approach to two-pointer technique
- Multiple difficulty steps with comprehensive coverage
- **Total**: 20+ two-pointer problems

### AtCoder DP Contest

Classic dynamic programming problems from AtCoder's educational DP contest:

- Frog problems (1D DP)
- Knapsack variants
- Vacation problem (multi-state DP)

### Tree Basics

Fundamental tree algorithms and concepts from Codeforces problems, providing a solid foundation for tree-related competitive programming problems.

## Setup and Usage

### Prerequisites

- C++ compiler (GCC/Clang recommended)
- Text editor or IDE for competitive programming

### Template Structure

Each solution follows a standard competitive programming template:

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

void solve() {
    // Solution implementation
}
```

### Compilation and Testing

```bash
g++ -o program_name source_file.cpp
./program_name
```

For local development, create your own `solution.cpp` and `test.cpp` files for testing purposes.

## File Structure

- **Source Files**: `.cpp` files containing problem solutions
- **Executable Files**: `.exe` files (compiled binaries for Windows) - ignored in git
- **Input/Output**: `input.txt` and `output.txt` for local testing - ignored in git
- **Testing Templates**: Local `solution.cpp` and `test.cpp` files for development - ignored in git
- **Organization**: Problems organized by platform and contest/topic

## Contributing

This repository serves as a personal collection of competitive programming solutions. While primarily for personal reference and learning, the implementations can serve as educational resources for others learning competitive programming concepts.

### Best Practices Followed

- Clean, readable code with meaningful variable names
- Efficient algorithms optimized for competitive programming
- Comprehensive coverage of fundamental algorithmic concepts
- Systematic organization for easy reference and learning

---

**Note**: This repository represents an ongoing journey in competitive programming, with solutions spanning multiple years of contests and practice across various platforms. The collection continues to grow with participation in new contests and exploration of advanced algorithmic concepts.’ve compiled all my competitive programming solutions in this repository named CP, including those submitted during contests on Codeforces, CodeChef, AtCoder, InterviewBit, and the CSES Problem Set. While most of my LeetCode problems are solved directly on the platform, selected noteworthy solutions are also included here. This collection showcases my problem-solving journey across multiple platforms. Additionally, you’ll find a dedicated CP Algos folder containing implementations of popular algorithms and data structures that I frequently use, serving as both a quick reference and a valuable learning resource.
