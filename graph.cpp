#include "graph.h"
#include "flow_graph.h"

graph::graph(const adjacency_matrix &matrix)
    : _matrix(matrix)
{}

int graph::max_flow(int from, int to) const
{
    // �������� ��������-�����
    // 1. �������� ���������� ���� �����
    flow_graph flow(*this, from - 1, to - 1);

    // 2. ���� � ���������� ���� ���� ������������� ����
    //    �� ������ � �����
    while (flow.consist_flow()) {
        // 3. ���������� ����������� ���������� ���������� 
        //    ����������� � ��������� ����
        int value = flow.get_min_flow_value();

        // 4. ���������� ���������� ������������ ���� �����
        //    � ��������� ����
        flow.correct_flow_by_value(value);
    }

    // 5. ������ ������������� ������ �� ������
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
