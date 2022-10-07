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
	g.insert_edge(1, 'a', 'b');
	g.insert_edge(1, 'b', 'c');
	g.insert_edge(1, 'd', 'a');
	g.erase_edge('a', 'b');
	g.erase_vertex('c');
	g.print_graph();
	return 0;
}