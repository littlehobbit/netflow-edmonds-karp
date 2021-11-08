#ifndef FLOW_GRAPH_H
#define FLOW_GRAPH_H

#include <vector>
#include <list>

#include "graph.h"
#include "edge.h"

class flow_graph
{
public:
    flow_graph(const graph& graph, int start, int stop);

    ~flow_graph();

    // Проверка и поиск аугментальной цепи в графе
    bool consist_flow();

    // Получение минимальной пропускной способности в найденном пути
    int get_min_flow_value();

    // Изменение величины потока по всему найденному пути
    void correct_flow_by_value(int value);

    // Вычисление величины потока
    int calc_flow();

private:
    // Список инцидентности графа (вершина - ребра)
    std::vector<std::list<flow_edge *>> _residual_graph;

    // Структура для обратного хода по пути
    std::vector<flow_edge *> _prev;

    int _start;
    int _stop;
};

#endif // FLOW_GRAPH_H
