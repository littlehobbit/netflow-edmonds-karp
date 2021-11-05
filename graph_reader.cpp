#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "graph_reader.h"
#include "edge.h"

graph graph_reader::from_file(const std::string &file_name)
{
    std::ifstream src(file_name);
    if (!src.is_open()) {
        throw std::runtime_error("no such file");
    }

    std::list<graph_edge> edges;

    std::string line;
    while (std::getline(src, line)) {
        std::istringstream line_stream(line);
        graph_edge edge;
        line_stream >> edge.from >> edge.to >> edge.capacity;
        edges.push_back(edge);
    }

    int vertex_count = 0;
    for (const auto &edge : edges) {
        if (edge.from > vertex_count)
            vertex_count = edge.from;

        if (edge.to > vertex_count)
            vertex_count = edge.to;
    }

    graph::adjacency_matrix matrix(vertex_count, std::vector<int> (vertex_count, -1));
    for (const auto &edge : edges) {
        matrix[edge.from - 1][edge.to - 1] = edge.capacity;
    }

    return graph(matrix);
}
