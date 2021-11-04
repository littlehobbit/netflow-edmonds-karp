#include <iostream>

#include "graph.h"
#include "graph_reader.h"

using namespace std;

int main()
{
    graph graph = graph_reader::from_file("graph.txt");
    std::cout << graph.max_flow(1, 7) << std::endl;
    return 0;
}
