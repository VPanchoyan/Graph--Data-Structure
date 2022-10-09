#include "graph.h"
#include <queue>
#include <iostream>


void graph::insert_vertex(int vertex_value) {
	auto vertex_count = this->vertices.size(); // quantity of vertices in graph
	for (int i = 0; i < vertex_count; ++i) {  // checking if such vertex already exists
		if (this->vertices[i].value == vertex_value) {
			// found vertex with the same value
			// exit process,nothing was done
			return;
		}
	}
	//check over,no such vertex
	vertex* new_vertex = new vertex(vertex_value); // creating new vertex
	this->vertices.push_back(*new_vertex); // adding it to vertices set of graph
}

void graph::insert_edge(int vertex1, int vertex2,int weight) {
	auto vertex_count = this->vertices.size(); // quantity of vertices in graph
	int index_of_vertex1 = 0;
	// checking vertex1 and vertex2 existence
	for (int i = 0; i < vertex_count; ++i) {  
		if (this->vertices[i].value == vertex1) {
			index_of_vertex1 = i; // saving vertex1 index in vertices set
			break;
		}
		else if (i == vertex_count - 1) {
			return;
		}
	}
	for (int i = 0; i < vertex_count; ++i) { 
		if (this->vertices[i].value == vertex2) {
			break;
		}
		else if (i == vertex_count - 1) {
			return;
		}
	}
	// check over,vertices exist
	adjacent_vertex* ptr = this->vertices[index_of_vertex1].connections_head;
	if (ptr) {
		while (ptr->connect) { //ptr for iterating on adjacency list of vertex1
			if (ptr->value == vertex2) return; // edge between vertex1 and vertex2 already exists
			ptr = ptr->connect;
		}
		adjacent_vertex* new_adj_ver = new adjacent_vertex; //creating new adjacent vertex
		new_adj_ver->value = vertex2;
		new_adj_ver->weight = weight;
		ptr->connect = new_adj_ver; // adding it to the end of vertex1 adjacecny list
	}
	else {
		adjacent_vertex* new_adj_ver = new adjacent_vertex; //creating new adjacent vertex
		new_adj_ver->value = vertex2;
		new_adj_ver->weight = weight;
		this->vertices[index_of_vertex1].connections_head = new_adj_ver; // adding it to the end of vertex1 adjacecny list
	}
}

void graph::erase_vertex(int vertex_value) {
	auto vertex_count = this->vertices.size(); // quantity of vertices in graph
	int index_of_vertex = 0;
	for (int i = 0; i < vertex_count; ++i) { // checking if such vertex exists
		if (this->vertices[i].value == vertex_value) {
			index_of_vertex = i; // saving vertex index
			break;
		}
		if (i == vertex_count - 1) {
			return; // no such vertex to delete
		}
	}
	//check over,vertex exists
	// deleting all connections with vertex
	for (int i = 0; i < vertex_count; ++i) {
		this->erase_edge(vertex_value, this->vertices[i].value);
		this->erase_edge(this->vertices[i].value, vertex_value);
	}
	while (this->vertices[index_of_vertex].connections_head) { // deleting vertex adjacency list
		adjacent_vertex* ptr = this->vertices[index_of_vertex].connections_head;
		this->vertices[index_of_vertex].connections_head = this->vertices[index_of_vertex].connections_head->connect;
		delete ptr;
	}
	// adjacency list deleted
	this->vertices.erase(this->vertices.begin() + index_of_vertex);// deleting vertex from vertices set
}

void graph::erase_edge(int vertex1, int vertex2) {
	if (vertex1 == vertex2) return;
	auto vertex_count = this->vertices.size(); // quantity of vertices in graph
	int index_of_vertex1 = 0;
	//checking vertex1 and vertex2 existence
	for (int i = 0; i < vertex_count; ++i) {
		if (this->vertices[i].value == vertex1) {
			index_of_vertex1 = i; // saving vertex1 index in vertices set
			break;
		}
		else if (i == vertex_count - 1) {
			return;
		}
	}
	for (int i = 0; i < vertex_count; ++i) {
		if (this->vertices[i].value == vertex2) {
			break;
		}
		else if (i == vertex_count - 1) {
			return;
		}
	}
	// check over,vertices exist
	//checking edge existence between vertex1 and vertex2 and deleting
	adjacent_vertex* ptr = this->vertices[index_of_vertex1].connections_head;
	adjacent_vertex* ptr_previous = this->vertices[index_of_vertex1].connections_head;
	while (ptr) {
		if (this->vertices[index_of_vertex1].connections_head->value == vertex2) {
			this->vertices[index_of_vertex1].connections_head = this->vertices[index_of_vertex1].connections_head->connect;
			return;
		}
		if (ptr->value == vertex2 && ptr->connect == nullptr) {
			ptr_previous->connect = nullptr;
			return;
		}
		if (ptr->value == vertex2) {
			ptr_previous->connect = ptr->connect;
			ptr->connect = nullptr;
			return;
		}
		ptr_previous = ptr;
		ptr = ptr->connect;
	}
	return;
}

std::vector<int> graph::get_vertex_set() {
	std::vector<int> vertices;
	for (int i = 0; i < this->vertices.size(); ++i) {
		vertices.push_back(this->vertices[i].value);
	}
	return vertices;
}

std::vector<std::vector<int>> graph::get_edge_set() {
	std::vector<int> edge;
	std::vector<std::vector<int>> edge_set;

	return edge_set;
}

void graph::BFS(int start_vertex) {
	std::queue<int> vertex_queue;
	int start_vertex_index = 0;
	for (int i = 0; i < this->vertices.size(); ++i) {
		if (this->vertices[i].value == start_vertex) {
			start_vertex_index = i;
			break;
		}
		if (i == this->vertices.size() - 1) {
			// no such vertex
			return;
		}
	}
	// vertex exists
	vertex_queue.push(this->vertices[start_vertex_index].value);
	std::cout << "BFS from " << start_vertex << ": ";
	int size = this->vertices.size();
	std::vector<bool> visited_vertices(size,false);
	visited_vertices[start_vertex_index] = true;
	while (!vertex_queue.empty()) {
		adjacent_vertex* ptr = this->vertices[start_vertex_index].connections_head;
		while (ptr) {
			int index = 0;
			for (int i = 0; i < size; ++i) {
				if (this->vertices[i].value == ptr->value) {
					index = i;
					break;
				}
			}
			if (!visited_vertices[index]) {
				vertex_queue.push(ptr->value);
				visited_vertices[index] = true;
			}
			ptr = ptr->connect;
		}
		std::cout << vertex_queue.front() << " ";
		vertex_queue.pop();
		if (vertex_queue.empty()) return;
		int next_vertex = vertex_queue.front();
		for (int i = 0; i < size; ++i) {
			if (this->vertices[i].value == next_vertex) {
				start_vertex_index = i;
				visited_vertices[start_vertex_index] = true;
				break;
			}
		}	
	}
	std::cout << std::endl;
}



bool graph::operator==(const graph& g) {
	return true;
}

bool graph::operator!=(const graph& g) {
	return true;
}

graph& graph::operator=(const graph& g) {
	return *this;
}



std::ostream& operator<<(std::ostream& os, const graph& g) {
	os << "G = (V,E)\n";
	os << "V = {";
	for (int i = 0; i < g.vertices.size(); ++i) {
		os << " " << g.vertices[i].value;
	}
	os << " }\n";
	os << "E = {";
	for (int i = 0; i < g.vertices.size(); ++i) {
		adjacent_vertex* ptr = g.vertices[i].connections_head;
		while (ptr) {
			os << " (" << g.vertices[i].value << "," << ptr->value << ")";
			ptr = ptr->connect;
		}
	}
	os << " }\n";
	return os;
}