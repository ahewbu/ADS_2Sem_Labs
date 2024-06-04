#ifndef LAB_3_INCLUDE_GRAPH_H
#define LAB_3_INCLUDE_GRAPH_H

#define EPSILON 1e-10
#define INF 1e9

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

enum class Color { White, Black, Grey };

template<typename Vertex, typename Distance = double>
class Graph {
public:
    struct Edge {
        Vertex from;
        Vertex to;
        Distance distance;
    };

private:
    std::vector<Vertex> _vertices;
    std::unordered_map<Vertex, std::vector<Edge>> _edges;


public:
    bool has_vertex(const Vertex& v) const {
        return std::find(_vertices.begin(), _vertices.end(), v) != _vertices.end();
    }

    bool add_vertex(const Vertex& v) {
        if (has_vertex(v))
            return false;
        _vertices.push_back(v);
        _edges[v] = {};
        return true;
    }

    bool remove_vertex(const Vertex& v) {
        auto it = std::find(_vertices.begin(), _vertices.end(), v);
        if (it == _vertices.end())
            return false;
        _vertices.erase(it);
        _edges.erase(v);
        for (auto& vertex : _vertices) {
            auto& edges = _edges.at(vertex);
            edges.erase(std::remove_if(edges.begin(), edges.end(), [v](const Edge& edge) {return edge.to == v;}), edges.end());
        }
        return true;
    }

    const std::vector<Vertex>& vertices() const {
        return _vertices;
    }

    bool add_edge(const Vertex& from, const Vertex& to, const Distance& distance) {
        if (has_edge({ from, to, distance }))
            return false;
        _edges[from].push_back({ from, to, distance });
        return true;
    }

    bool remove_edge(const Vertex& from, const Vertex& to) {
        if (!has_edge(from, to))
            return false;
        auto& edges = _edges.at(from);
        edges.erase(std::remove_if(edges.begin(), edges.end(), [to](const Edge& edge) {return edge.to == to; }), edges.end());
        return true;
    }

//    bool remove_edge(const Edge& e) {
//        if (!has_edge({ e.from, e.to, e.distance }))
//            return false;
//        auto& edges = _edges.at(e.from);
//        edges.erase(std::remove_if(edges.begin(), edges.end(), [e](const Edge& edge) {return edge.to == e.to && abs(edge.distance - e.distance) < EPSILON; }), edges.end());
//        return true;
//    }

    bool has_edge(const Vertex& from, const Vertex& to) const {
        if (std::find(_vertices.begin(), _vertices.end(), from) == _vertices.end())
            return false;
        if (std::find(_vertices.begin(), _vertices.end(), to) == _vertices.end())
            return false;
        for (const Edge& edge : _edges.at(from))
            if (edge.to == to)
                return true;
        return false;
    }

    bool has_edge(const Edge& e) const {
        if (std::find(_vertices.begin(), _vertices.end(), e.from) == _vertices.end())
            return false;
        if (std::find(_vertices.begin(), _vertices.end(), e.to) == _vertices.end())
            return false;
        for (const Edge& edge : _edges.at(e.from))
            if (edge.to == e.to && abs(edge.distance - e.distance) < EPSILON)
                return true;
        return false;
    }

    const std::vector<Edge>& edges(const Vertex& vertex) {
        if (!has_vertex(vertex))
            throw std::invalid_argument("vertex is not found");
        return _edges[vertex];
    }

    size_t order() const {
        return _vertices.size();
    }

    size_t degree(const Vertex& v) const {
        if (!has_vertex(v))
            throw std::invalid_argument("vertex is not found");
        size_t deg_out = _edges.at(v).size();
        size_t deg_in = 0;
        for (auto& vertex : _vertices) {
            for (auto& edge : _edges.at(vertex)) {
                if (edge.to == v) {
                    ++deg_in;
                }
            }
        }
        return deg_in + deg_out;
    }

    void print() const {
        for (const auto& v : _vertices) {
            std::cout << v << " : ";
            for (const auto& e : _edges.at(v)) {
                std::cout << "(" << e.to << ", " << e.distance << "),  ";
            }
            std::cout << std::endl;
        }
    }
};

#endif