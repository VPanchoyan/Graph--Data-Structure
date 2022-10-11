#include "graph.hpp"
#include <iostream>

int main() {
	Graph<int> g;
	g.insert_vertex(1);
	g.insert_vertex(2);
	g.insert_vertex(3);
	g.insert_vertex(4);
	g.insert_vertex(5);
	g.insert_edge(1, 2, 3);
	g.insert_edge(1, 4, 5);
	g.insert_edge(2, 4, 3);
	g.insert_edge(3, 2, 12);
	g.insert_edge(4, 5, 6);
	g.insert_edge(3, 5, 9);

	Graph<int> t;
	t.insert_vertex(1);
	t.insert_vertex(2);
	t.insert_vertex(3);
	t.insert_vertex(4);
	t.insert_vertex(5);
	t.insert_edge(1, 2, 3);
	t.insert_edge(1, 4, 5);
	t.insert_edge(2, 4, 3);
	t.insert_edge(3, 2, 12);
	t.insert_edge(4, 5, 6);
	t.insert_edge(3, 5, 9);
	//std::cout << (g == t) << "\n";
	/*g.print_vertices();
	g.print_edges();*/
	std::cout << t;
	return 0;
}