#include "graph.h"
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>

template<class T>
bool Graph<T>::vertex_exists(T value) {
	if (this->_vertices.find(value) == this->_vertices.end()) {
		return false;
	}
	return true;
}

template<class T>
void Graph<T>::print_edges() {
	std::cout << "E = {";
	std::vector<std::tuple<T,T,T>> edges = this->get_edge_set();
	int size = edges.size();
	for (int i = 0; i < size; ++i) {
		std::cout << " (" << std::get<0>(this->get_edge_set()[i]) 
			<< "," << std::get<1>(this->get_edge_set()[i]) << "," 
			<< std::get<2>(this->get_edge_set()[i]) << ")";
	}
	std::cout << " }\n";
}

template<class T>
void Graph<T>::print_vertices() {
	std::cout << "V = {";
	for (auto it : this->_vertices) {
		std::cout << " " << it.first;
	}
	std::cout << " }\n";
}

template<class T>
Graph<T>::Graph(std::initializer_list<std::pair<T, std::initializer_list<T>>> list) {
	for (auto it : list) {
		this->_vertices.insert((*it).first);
		for (auto iter = (*it).second.begin(); iter != (*it).second.end();++iter) {
			this->insert_edge((*it)->first, *iter,1);
		}
	}
}

template<class T>
void Graph<T>::insert_vertex(T value) {
	std::list<Edge<T>> adjacents;
	this->_vertices.insert({ value, adjacents });
	++this->_size;
}

template<class T>
void Graph<T>::insert_edge(T vertex1, T vertex2,int weight) {
	// add vertices if they don`t exist
	this->insert_vertex(vertex1);
	this->insert_vertex(vertex2);
	Edge<T> new_edge(vertex1,vertex2, weight);
	this->_vertices.at(vertex1).push_back(new_edge);
	//this->_size = this->get_vertex_set().size();
}

template<class T>
std::vector<std::tuple<T, T, T>> Graph<T>::get_edge_set() {
	std::vector<std::tuple<T, T, T>> edge_set;
	for (auto it : this->_vertices) {
		std::list<Edge<T>> edges = it.second;
		for (auto iter = edges.begin(); iter != edges.end(); ++iter) {
			edge_set.push_back(std::tuple<T, T, T>((*iter)._vertex1, (*iter)._vertex2, (*iter)._weight));
		}
	}
	return edge_set;
}

template<class T>
void Graph<T>::erase_vertex(T vertex) {
	if (!this->vertex_exists(vertex)) {
		return;
	}
	for (auto it : this->_vertices) {
		erase_edge(it.first, vertex);
	}
	this->_vertices.erase(vertex);
	--this->_size;
}

template<class T>
std::vector<T> Graph<T>::get_vertex_set() {
	std::vector<T> vertices;
	for (auto it : this->_vertices) {
		vertices.push_back(it.first);
	}
	return vertices;
}

template<class T>
void Graph<T>::erase_edge(T vertex1, T vertex2) {
	// checking existence of vertices
	if (!this->vertex_exists(vertex1) || !this->vertex_exists(vertex2)) {
		return;
	}
	// check over, vertices exist
	for (auto it = this->_vertices.at(vertex1).begin(); it != this->_vertices.at(vertex1).end(); ++it) {
		if ((*it)._vertex2 == vertex2) {
			this->_vertices.at(vertex1).erase(it);
			return;
		}
	}
}

template<class T>
int Graph<T>::get_number_of_vertex() {
	return this->_size;
}

template<class T>
bool Graph<T>::operator==(const Graph<T>& compare_graph) {
	return (this->_vertices == compare_graph._vertices);
}

template<class T>
bool Graph<T>::operator!=(const Graph<T>& compare_graph) {
	return !this->operator==(compare_graph);
}

template<class T>
void Graph<T>::BFS(T start_vertex) {
	// checking vertex existence
	if (!this->vertex_exists(start_vertex)) {
		return;
	}
	// check over,vertex exists
	std::queue<T> vert_queue;
	std::vector<T> visited_vertices;
	T current_vertex = start_vertex;
	visited_vertices.push_back(current_vertex);
	std::cout << "BFS from " << start_vertex << " vertex: ";
	vert_queue.push(start_vertex);
	while (!vert_queue.empty()) {
		std::cout << vert_queue.front() << " ";
		vert_queue.pop();

	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& graph) {
	os << "G = (V,E)\nV = {";
	for (auto it : this->_vertices) {
		std::cout << " " << it.first;
	}
	std::cout << " }\nE = {";
	std::vector<std::tuple<T, T, T>> edges = this->get_edge_set();
	int size = edges.size();
	for (int i = 0; i < size; ++i) {
		os << " (" << std::get<0>(this->get_edge_set()[i])
			<< "," << std::get<1>(this->get_edge_set()[i]) << ","
			<< std::get<2>(this->get_edge_set()[i]) << ")";
	}
	os << " }\n";
	
	return os;
}

//void graph::BFS(int start_vertex) {
//	std::queue<int> vertex_queue;
//	int start_vertex_index = 0;
//	int size = this->vertices.size();
//	for (int i = 0; i < size; ++i) {
//		if (this->vertices[i].value == start_vertex) {
//			start_vertex_index = i;
//			break;
//		}
//		if (i == this->vertices.size() - 1) {
//			// no such vertex
//			return;
//		}
//	}
//	// vertex exists
//	vertex_queue.push(this->vertices[start_vertex_index].value);
//	std::cout << "BFS from " << start_vertex << " vertex: ";
//	std::vector<bool> visited_vertices(size,false);
//	visited_vertices[start_vertex_index] = true;
//	while (!vertex_queue.empty()) {
//		adjacent_vertex* ptr = this->vertices[start_vertex_index].connections_head;
//		while (ptr) {
//			int index = 0;
//			for (int i = 0; i < size; ++i) {
//				if (this->vertices[i].value == ptr->value) {
//					index = i;
//					break;
//				}
//			}
//			if (!visited_vertices[index]) {
//				vertex_queue.push(ptr->value);
//				visited_vertices[index] = true;
//			}
//			ptr = ptr->connect;
//		}
//		std::cout << vertex_queue.front() << " ";
//		vertex_queue.pop();
//		if (vertex_queue.empty()) {
//			std::cout << std::endl;
//			return;
//		}
//		int next_vertex = vertex_queue.front();
//		for (int i = 0; i < size; ++i) {
//			if (this->vertices[i].value == next_vertex) {
//				start_vertex_index = i;
//				visited_vertices[start_vertex_index] = true;
//				break;
//			}
//		}	
//	}
//}
//
//void graph::DFS(int start_vertex) {
//	int start_vertex_index = 0;
//	int size = this->vertices.size();
//	for (int i = 0; i < size; ++i) {
//		if (this->vertices[i].value == start_vertex) {
//			start_vertex_index = i;
//			break;
//		}
//		if (i == this->vertices.size() - 1) {
//			// no such vertex
//			return;
//		}
//	}
//	// vertex exists
//	std::cout << "DFS from " << start_vertex << " vertex: ";
//	std::stack<int> vertex_stack;
//	std::vector<bool> visited_vertices(size, false);
//	visited_vertices[start_vertex_index] = true;
//	std::cout << this->vertices[start_vertex_index].value << " ";
//	//vertex_stack.push(start_vertex);
//	while (true) {
//		adjacent_vertex* ptr = this->vertices[start_vertex_index].connections_head;
//		while (ptr) {
//			int index = 0;
//			for (int i = 0; i < size; ++i) {
//				if (this->vertices[i].value == ptr->value) {
//					index = i;
//					break;
//				}
//			}
//			if (!visited_vertices[index]) {
//				vertex_stack.push(ptr->value);
//				
//			}
//			ptr = ptr->connect;
//		}
//		if (vertex_stack.empty()) {
//			std::cout << std::endl;
//			return;
//		}
//		int next_vertex = vertex_stack.top();
//		for (int i = 0; i < size; ++i) {
//			if (this->vertices[i].value == next_vertex) {
//				visited_vertices[i] = true;
//				start_vertex_index = i;
//				break;
//			}
//		}
//		std::cout << next_vertex << " ";
//		vertex_stack.pop();
//	}
//}
//
//bool graph::operator==(const graph& graph_to_check) {
//	std::vector<int> check_vertices;
//	int size = graph_to_check.vertices.size();
//	for (int i = 0; i < size; ++i) {
//		check_vertices.push_back(graph_to_check.vertices[i].value);
//	}
//	if (this->get_vertex_set() != check_vertices) return false;
//	std::vector<std::vector<int>> edge_set;
//	for (int i = 0; i < size; ++i) {
//		adjacent_vertex* ptr = graph_to_check.vertices[i].connections_head;
//		while (ptr) {
//			std::vector<int> edge;
//			edge.push_back(graph_to_check.vertices[i].value);
//			edge.push_back(ptr->value);
//			edge_set.push_back(edge);
//			ptr = ptr->connect;
//		}
//	}
//	if (this->get_edge_set() != edge_set) return false;
//	return true;
//}
//
//bool graph::operator!=(const graph& graph_to_check) {
//	return !this->operator==(graph_to_check);
//}
//
//graph& graph::operator=(const graph& graph_to_copy) {
//	this->vertices = graph_to_copy.vertices;
//	return *this;
//}
//
//graph graph::operator+(const graph& graph_to_add) {
//	graph sum_graph(*this);
//	/*std::vector<vertex> new_vertices = this->vertices;
//	sum_graph.vertices = new_vertices;*/
//	int size = this->vertices.size();
//	int adding_size = graph_to_add.vertices.size();
//	for (int i = 0; i < adding_size; ++i) {
//		bool available = true;
//		for (int j = 0; j < size; ++j) {
//			if (sum_graph.vertices[j].value == graph_to_add.vertices[i].value) {
//				available = false;
//				break;
//			}
//		}
//		if (available) {
//			sum_graph.vertices.push_back(graph_to_add.vertices[i].value);
//		}
//	}
//	int extended_size = sum_graph.vertices.size();
//	for (int i = 0; i < size; ++i) {
//		for (int j = size; j < extended_size; ++j) {
//			sum_graph.insert_edge(sum_graph.vertices[i].value, graph_to_add.vertices[j].value);
//		}
//	}
//	return sum_graph;
//}
//
//void graph::operator+=(const graph& graph_to_add) {
//	*this = *this + graph_to_add;
//}
//
//std::ostream& operator<<(std::ostream& os, const graph& g) {
//	os << "G = (V,E)\n";
//	os << "V = {";
//	for (int i = 0; i < g.vertices.size(); ++i) {
//		os << " " << g.vertices[i].value;
//	}
//	os << " }\n";
//	os << "E = {";
//	for (int i = 0; i < g.vertices.size(); ++i) {
//		adjacent_vertex* ptr = g.vertices[i].connections_head;
//		while (ptr) {
//			os << " (" << g.vertices[i].value << "," << ptr->value << ")";
//			ptr = ptr->connect;
//		}
//	}
//	os << " }\n";
//	return os;
//}