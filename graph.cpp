#include "graph.h"
#include "flow_graph.h"

graph::graph(const adjacency_matrix &matrix)
    : _matrix(matrix)
{}

int graph::max_flow(int from, int to) const
{
    // Алгоритм Едмондса-Карпа
    // 1. Создание остаточной сети графа
    flow_graph flow(*this, from - 1, to - 1);

    // 2. Пока в остаточной сети есть аугментальная цепь
    //    от истока к стоку
    while (flow.consist_flow()) {
        // 3. Вычисление минимальной остаточной пропускной 
        //    способности в найденной цепи
        int value = flow.get_min_flow_value();

        // 4. Уменьшение пропускных способностей всех ребер
        //    в найденной цепи
        flow.correct_flow_by_value(value);
    }

    // 5. Расчет максимального потока из истока
    return flow.calc_flow();
}

const graph::adjacency_matrix& graph::get_adjacency_matrix() const
{
    return _matrix;
}

size_t graph::size() const
{
    return _matrix.size();
}
