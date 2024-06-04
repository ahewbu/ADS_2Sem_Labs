#ifndef LAB_3_INCLUDE_TASK_H
#define LAB_3_INCLUDE_TASK_H

#include "Graph.h"

template<typename Vertex, typename Distance = double>
Vertex find_center(const Graph<Vertex, Distance>& graph) {
    Vertex center;
    Distance min_eccentricity = INF;
    for (const auto& vertex : graph.vertices()) {
        Distance max_distance = 0;
        bool is_achievable = false;
        for (const auto& other_vertex : graph.vertices()) {
            std::vector<typename Graph<Vertex, Distance>::Edge> path = graph.shortest_path(other_vertex, vertex);
            Distance distance = 0;
            if (!path.empty())
                is_achievable = true;
            for (const auto& edge : path)
                distance += edge.distance;
            max_distance = std::max(max_distance, distance);
        }

        if (!is_achievable)
            max_distance = INF;

        if (max_distance < min_eccentricity) {
            min_eccentricity = max_distance;
            center = vertex;
        }
    }

    return center;
}

#endif