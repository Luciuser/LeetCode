cmake_minimum_required (VERSION 2.8)
project(leetCode)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11 -Wall)

if(NOT CMAKE_BUILD_TYPE)
	message(STATUS "No build type selected, default to Release")
	set(CMAKE_BUILD_TYPE "Release")
endif()

 set(SOURCES
 	src/audition0406.h
 	src/audition1711.h
 	src/leetcode2.h
 	src/leetcode5.h
 	src/leetcode30.h
 	src/leetcode94.h
 	src/leetcode174.h
 	src/leetcode215.h
 	src/leetcode324.h
 	src/leetcode326.h
 	src/leetcode427.h
 	src/leetcode434.h
 	src/leetcode436.h
 	src/leetcode450.h
 	src/leetcode462.h
 	src/leetcode464.h
 	src/leetcode467.h
 	src/leetcode468.h
 	src/leetcode473.h
 	src/leetcode497.h
 	src/leetcode498.h
 	src/leetcode508.h
 	src/leetcode513.h
 	src/leetcode516.h
 	src/leetcode522.h
 	src/leetcode532.h
 	src/leetcode535.h
 	src/leetcode592.h
 	src/leetcode647.h
 	src/leetcode668.h
 	src/leetcode675.h
 	src/leetcode676.h
 	src/leetcode699.h
 	src/leetcode715.h
 	src/leetcode719.h
 	src/leetcode730.h
 	src/leetcode731.h
 	src/leetcode732.h
 	src/leetcode735.h
 	src/leetcode745.h
 	src/leetcode747.h
 	src/leetcode749.h
 	src/leetcode757.h
 	src/leetcode762.h
 	src/leetcode814.h
 	src/leetcode829.h
 	src/leetcode875.h
 	src/leetcode890.h
 	src/leetcode919.h
 	src/leetcode926.h
 	src/leetcode942.h
 	src/leetcode951.h
 	src/leetcode953.h
 	src/leetcode961.h
 	src/leetcode965.h
 	src/leetcode1021.h
 	src/leetcode1022.h
 	src/leetcode1037.h
 	src/leetcode1051.h
 	src/leetcode1052.h
 	src/leetcode1089.h
 	src/leetcode1108.h
 	src/leetcode1162.h
 	src/leetcode1172.h
 	src/leetcode1175.h
 	src/leetcode1184.h
 	src/leetcode1185.h
 	src/leetcode1200.h
	src/leetcode1206.h
 	src/leetcode1252.h
 	src/leetcode1260.h
 	src/leetcode1399.h
 	src/leetcode1728.h
 	src/leetcode1781.h
 	src/leetcode1786.h
 	src/leetcode1909.h
 	src/leetcode2104.h
 	src/leetcode2119.h
 	src/swordOfferII041.h
 	src/swordOfferII114.h
 	src/swordOfferII115.h
 	src/leetcodetest.h
 	src/leetcodetest.cpp
 	src/main.cpp)

link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(leetCode ${SOURCES})
#target_include_directories(leetCode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
