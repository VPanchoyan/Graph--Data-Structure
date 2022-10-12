#include "graph.hpp"
#include <iostream>

int main() {
	Graph<int> g;
	g.insert_vertex(1);
	g.insert_vertex(2);
	g.insert_vertex(3);
	g.insert_vertex(4);
	g.insert_vertex(5);
	g.insert_edge(1, 4, 1);
	g.insert_edge(2, 4, 1);
	g.insert_edge(1, 2, 1);
	g.insert_edge(3, 2, 1);
	g.insert_edge(4, 5, 1);
	g.insert_edge(3, 5, 1);
	g.print_vertices();
	g.print_edges();
	//std::cout << t;
	g.BFS(2);
	g.DFS(1);
	return 0;
}