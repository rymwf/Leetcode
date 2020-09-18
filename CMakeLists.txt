cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_C_EXTENSIONS off)


project(LeetCode)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(3.lengthOfLongestSubstring 3.lengthOfLongestSubstring.cpp)
add_executable(37.sudokuSolver 37.sudokuSolver.cpp)
add_executable(40.combinedsum2 40.combinedsum2.cpp)
add_executable(47.PermutationsII 47.PermutationsII.cpp)
add_executable(79.wordsearch 79.wordsearch.cpp)
add_executable(94.inorderTraversal 94.inorderTraversal.cpp)
add_executable(226.InvertBinaryTree 226.InvertBinaryTree.cpp)
add_executable(637.averageOfLevels 637.averageOfLevels.cpp)
add_executable(684.RedundantConnectionI 684.RedundantConnectionI.cpp)
add_executable(685.RedundantConnectionII 685.RedundantConnectionII.cpp)