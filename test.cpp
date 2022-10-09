#include "graph.h"
#include <iostream>

int main() {
	graph g;
	g.insert_vertex(1);
	g.insert_vertex(2);
	g.insert_vertex(3);
	g.insert_vertex(4);
	g.insert_vertex(5);
	g.insert_edge(1, 2, 3);
	g.insert_edge(1, 4, 5);
	g.insert_edge(2, 4, 3);
	g.insert_edge(3, 2, 12);
	g.insert_edge(3, 5, 9);
	g.insert_edge(4, 5, 6);
	g.erase_vertex(2);
	std::cout << g << std::endl;
	
	/*std::vector<int> verts = g.get_vertex_set();
	for (int i = 0; i < verts.size(); ++i) {
		std::cout << verts[i];
	}
	std::cout << std::endl;*/
	return 0;
}