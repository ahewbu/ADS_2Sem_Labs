#include "Graph.h"
#include "Task.h"

int main() {
    Graph<int> graph;

    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);

    graph.add_edge(1, 2, 1);
    graph.add_edge(2, 3, 2);
    graph.add_edge(3, 4, 2);
    graph.add_edge(4, 2, 1);
    graph.add_edge(4, 3, 3);
    graph.add_edge(3, 5, 4);
    graph.add_edge(1, 3, 4);
    graph.add_edge(5, 4, 5);

    graph.print();

    std::cout << "The degree of the vertex 4: " <<  graph.degree(4) << std::endl;
    std::cout << "The order of the graph: " << graph.order() << std::endl;

    std::cout << "Traversing the graph in depth: ";
    graph.dfs(1, [](const int vertex) {std::cout << vertex << " "; });
    std::cout << std::endl;

    // Solving an additional task with the action function
    std::vector<int> visited;
    graph.dfs(1, [&visited](const int vertex) { visited.push_back(vertex); });
    for (int v : visited)
        std::cout << v << " ";
    std::cout << std::endl;

    double distance = 0.0;
    std::cout << "Dijkstra's algorithm" << std::endl;
    for (const auto& edge : graph.shortest_path(1, 4)) {
        std::cout << "From " << edge.from << " to " << edge.to << " distance = " << edge.distance << std::endl;
        distance += edge.distance;
    }
    std::cout << "Distance from 1 to 4 =  " << distance << std::endl;

    std::cout << "Center: " << find_center(graph) << std::endl;

    std::cout << "An edge 5->4 is present in graph: " << graph.has_edge(5, 4) << std::endl;
    std::cout << "An vertex 1 is present in graph: " << graph.has_vertex(1) << std::endl;
    graph.remove_edge(5, 4);
    graph.remove_vertex(1);
    graph.remove_vertex(4);

    graph.print();

    std::cout << "An edge 5->4 is present in graph: " << graph.has_edge(5, 4) << std::endl;
    std::cout << "An vertex 1 is present in graph: " << graph.has_vertex(1) << std::endl;

    return 0;
}