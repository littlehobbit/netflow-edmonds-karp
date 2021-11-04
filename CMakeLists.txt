cmake_minimum_required(VERSION 3.5)

project(netflow-edmonds-karp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(netflow-edmonds-karp flow_graph.cpp flow_graph.h graph_reader.cpp graph_reader.h edge.h graph.cpp graph.h main.cpp )
