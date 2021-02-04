cmake_minimum_required(VERSION 3.17)
project(DP)

set(CMAKE_CXX_STANDARD 14)

add_executable(fab fab.cpp)
add_executable(coin_change coin_change.cpp)
add_executable(lengthOfLIS lengthOfLIS.cpp)
add_executable(EditDistance EditDistance.cpp)
add_executable(superEggDrop superEggDrop.cpp)
add_executable(longestPalindromeSubseq longestPalindromeSubseq.cpp)
add_executable(stoneGame stoneGame.cpp)

