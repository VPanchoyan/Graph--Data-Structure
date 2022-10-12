#include "graph.hpp"
#include <iostream>

int main() {
	Graph<int> g;
	g.insert_vertex(1);
	g.insert_vertex(2);
	g.insert_vertex(3);
	g.insert_vertex(4);
	g.insert_vertex(5);
	g.insert_vertex(6);
	g.insert_vertex(7);
	g.insert_vertex(8);
	g.insert_edge(1, 2, 3);
	g.insert_edge(1, 3, 6);
	g.insert_edge(2, 3, 4);
	g.insert_edge(2, 4, 4);
	g.insert_edge(2, 5, 11);
	g.insert_edge(3, 4, 8);
	g.insert_edge(3, 7,11);
	g.insert_edge(4, 5,-4);
	g.insert_edge(4, 6, 5);
	g.insert_edge(4, 7, 2);
	g.insert_edge(5, 8, 9);
	g.insert_edge(6, 8, 1);
	g.insert_edge(7, 8, 2);
	std::cout << g;
	g.BFS(2);
	g.DFS(1);
	return 0;
}