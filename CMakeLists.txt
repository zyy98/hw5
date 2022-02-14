cmake_minimum_required(VERSION 3.15)
project(lec_4_files)

set(CMAKE_CXX_STANDARD 20)

#set(pthread_flag -pthread)

add_executable(distributed1 DistributedCounterTest1.cpp)

add_executable(distributed2 DistributedCounterTest2.cpp)
target_compile_options(distributed2 PRIVATE -pthread)

add_executable(distributed3 DistributedCounterTest3.cpp)
target_compile_options(distributed3 PRIVATE -pthread)

add_executable(hello HelloThreads.cpp)
target_compile_options(hello PRIVATE -pthread)

add_executable(Q3 Question3.cpp)
target_compile_options(hello PRIVATE -pthread)

add_executable(Q4 Question4.cpp)
#add_executable(Question3 Question3.cpp)