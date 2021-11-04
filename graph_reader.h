#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include <string>

#include "graph.h"

class graph_reader
{
public:
    static graph from_file(const std::string &file_name);
};

#endif // GRAPH_READER_H
