#include "graph.cpp"
#include <vector>
#include <iostream>

int main() {
	graph<char> g;
	g.insert_vertex('a');
	g.insert_vertex('b');
	g.insert_vertex('c');
	g.insert_vertex('d');
	g.insert_vertex('h');
	std::vector<vertex<char>> vertices = g.get_vertex_set();
	std::cout << "Vertices: {";
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		std::cout << (*it).value << ' ';
	}
	std::cout << "}" << std::endl;
	g.insert_edge(1, 'a', 'b');
	g.insert_edge(1, 'b', 'c');
	g.insert_edge(1, 'd', 'a');
	std::vector<edge<char>> edges = g.get_edge_set();
	std::cout << "Edges: {";
	for (auto it = edges.begin(); it != edges.end(); ++it) {
		std::cout << "(" << (*it).left << "," << (*it).right << "),";
	}
	std::cout << "}" << std::endl;
	return 0;
}