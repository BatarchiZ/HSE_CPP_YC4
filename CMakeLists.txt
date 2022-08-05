cmake_minimum_required(VERSION 3.21)
project(YC4)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)
add_executable(PloblemA_Tribonacci A/A1.cpp)
add_executable(ProblemB_FastExponent  B/B.cpp)
add_executable(ProblemD_Permutations D/D.cpp)
add_executable(ProblemC_LexicogrpahicalOrder C/C.cpp)
add_executable(ProblemE_Word2Vec E/E.cpp)
add_executable(ProblemG_ComplexN G/G.cpp)
add_executable(ProblemH_RationalN H/H.cpp H/main.cpp H/H.h H H/HFinal.h)
add_executable(ProblemI_MinesSweeper I/minesweeper.h I/main.cpp)