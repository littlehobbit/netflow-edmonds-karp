#include <queue>
#include <limits>

#include "flow_graph.h"

flow_graph::flow_graph(const graph& graph, int start, int stop)
    : _residual_graph(graph.size()),
      _prev(graph.size()),
      _start(start),
      _stop(stop)
{
    auto matrix = graph.get_adjacency_matrix();
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph.size(); j++) {
            int capacity = matrix[i][j];
            if (capacity != -1) {
                flow_edge *edge = new flow_edge(i, j, capacity, 0, capacity);
                flow_edge *residual = new flow_edge(j, i, capacity, 0, 0);

                edge->residual_edge = residual;
                residual->residual_edge = edge;

                _residual_graph[i].push_back(edge);
                _residual_graph[j].push_back(residual);
            }
        }
    }

    _prev[_start] = nullptr;
}

flow_graph::~flow_graph()
{
    for (auto &list : _residual_graph) {
        for (flow_edge *edge : list) {
            delete edge;
        }
    }
}

// Проверка и поиск аугментальной цепи в графе
bool flow_graph::consist_flow()
{
    std::queue<int> vertexes;
    vertexes.push(_start);

    std::vector<bool> visited(_residual_graph.size(), false);
    visited[_start] = true;

    while (!vertexes.empty()) {
        int v = vertexes.front();
        vertexes.pop();

        for (flow_edge *edge : _residual_graph[v]) {
            if (!visited[edge->to] && edge->is_valid()) {
                vertexes.push(edge->to);
                _prev[edge->to] = edge;
                visited[edge->to] = true;
                if (edge->to == _stop) return true;
            }
        }
    }

    return false;
}

// Получение минимальной пропускной способности в найденном пути
int flow_graph::get_min_flow_value()
{
    flow_edge *iter = _prev[_stop];
    int min_volume = std::numeric_limits<int>::max();
    while (iter != nullptr) {
        min_volume = std::min(min_volume, iter->residual);
        iter = _prev[iter->from];
    }
    return min_volume;
}

// Изменение величины потока по всему найденному пути
void flow_graph::correct_flow_by_value(int value)
{
    flow_edge *iter = _prev[_stop];
    while (iter != nullptr) {
        iter->flow += value;
        iter->residual -= value;
        iter->residual_edge->residual += value;

        iter = _prev[iter->from];
    }
}

// Вычисление величины потока
int flow_graph::calc_flow()
{
    int flow = 0;
    for (flow_edge *edge : _residual_graph[_start]) {
        flow += edge->flow;
    }
    return flow;
}
