#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class graph
{
public:
    using adjacency_matrix = std::vector<std::vector<int>>;

    explicit graph(const adjacency_matrix &matrix);

    size_t size() const;

    const adjacency_matrix& get_adjacency_matrix() const;

    int max_flow(int from, int to) const;

private:
    adjacency_matrix _matrix;
};

#endif // GRAPH_H
