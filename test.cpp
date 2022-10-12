#include "graph.hpp"
#include <iostream>

int main() {
	std::cout << "Creating 2 graphs...\ng1 and g2 coppied from g1" << std::endl;
	Graph<int> g1;
	g1.insert_vertex(1);
	g1.insert_vertex(2);
	g1.insert_vertex(3);
	g1.insert_vertex(4);
	g1.insert_vertex(5);
	g1.insert_vertex(6);
	g1.insert_vertex(7);
	g1.insert_vertex(8);
	g1.insert_edge(1, 2, 3);
	g1.insert_edge(1, 3, 6);
	g1.insert_edge(2, 3, 4);
	g1.insert_edge(2, 4, 4);
	g1.insert_edge(2, 5, 11);
	g1.insert_edge(3, 4, 8);
	g1.insert_edge(3, 7,11);
	g1.insert_edge(4, 5,-4);
	g1.insert_edge(4, 6, 5);
	g1.insert_edge(4, 7, 2);
	g1.insert_edge(5, 8, 9);
	g1.insert_edge(6, 8, 1);
	g1.insert_edge(7, 8, 2);
	Graph<int> g2 = g1;
	std::cout << "\ng1 graph\n" << g1;
	std::cout << "\ng2 graph\n" << g2;
	
	if (g1 == g2) std::cout << "\ng1 and g2 are equal!\n\n";
	std::cout << "\nAdding new vertex to g1!\n";
	g1.insert_vertex(9);
	std::cout << "\ng1 now is\n" << g1;

	std::cout << "\nRemoving first three vertices of g2!\n";
	g2.erase_vertex(1);
	g2.erase_vertex(2);
	g2.erase_vertex(3);
	std::cout << "\ng2 now is\n" << g2;

	if (g1 != g2) std::cout << "\ng1 and g2 are no longer equal!\n";

	std::cout << "\nRemoving edge (4,7,2) and non-existing edge (11,2,4) from g1!\n";
	g1.erase_edge(4, 7);
	g1.erase_edge(11, 2);
	std::cout << "\ng1 now is\n" << g1;

	std::cout << "\nNumber of vertices in g1: " << g1.get_number_of_vertex();
	std::cout << "\nNumber of vertices in g2: " << g2.get_number_of_vertex() << "\n";
	std::cout << "For g1: \n";
	g1.BFS(1);
	g1.DFS(1);
	std::cout << "\n\nShortest path lenght from vertex 1 to vertex 8 is " << g1.find_path(1, 8);
	// get_vertex_set() and get_edge_set() are used in operator<<
	return 0;
}