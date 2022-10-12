#include "graph.h"
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>

template<class T>
bool Contains(std::stack<T> source, T value){
	while (!source.empty() && source.top() != value)
		source.pop();
	if (!source.empty())
		return true;
	return false;
}

template<class T>
bool Contains(std::queue<T> q, T x) {
	while (!q.empty()) {
		if (q.front() == x) {
			return true;
		}
		q.pop();
	}
	return false;
}

template<class T>
bool is_visited(std::vector<T>& vec, T val) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == val) {
			return true;
		}
	}
	return false;
}

template<class T>
bool Graph<T>::vertex_exists(T value) {
	if (this->_vertices.find(value) == this->_vertices.end()) {
		return false;
	}
	return true;
}

template<class T>
void insert_in_queue_if_unique(std::queue<T>& q, std::vector<T>& vec, T& val) {
	// add vertex to queue if it is not visited
	// and is not already in queue
	if (!is_visited(vec, val)) {
		if (!Contains(q, val)) q.push(val);
	}
}

template<class T>
void insert_in_stack_if_unique(std::stack<T>& s, std::vector<T>& vec, T& val) {
	// add vertex to stack if it is not visited
	// and is not already in stack
	if (!is_visited(vec, val)) {
		if (!Contains(s, val)) {
			s.push(val);
		}
	}
}

template<class T>
void Graph<T>::print_edges() {
	std::cout << "E = {";
	std::vector<std::tuple<T,T,T>> edges = this->get_edge_set();
	int size = edges.size();
	for (int i = 0; i < size; ++i) {
		std::cout << " (" << std::get<0>(this->get_edge_set()[i]) 
			<< "," << std::get<1>(this->get_edge_set()[i]) << ", w = " 
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
Graph<T> Graph<T>::operator=(const Graph<T>& graph) {
	this->_vertices = graph._vertices;
	return *this;
}

template<class T>
void Graph<T>::insert_vertex(T value) {
	std::list<Edge<T>> adjacents;
	this->_vertices.insert({ value, adjacents });
}

template<class T>
void Graph<T>::insert_edge(T vertex1, T vertex2,int weight) {
	// add vertices if they don`t exist
	this->insert_vertex(vertex1);
	this->insert_vertex(vertex2);
	Edge<T> new_edge(vertex1,vertex2, weight);
	this->_vertices.at(vertex1).push_back(new_edge);
}

template<class T>
std::vector<std::tuple<T, T, T>> Graph<T>::get_edge_set() {
	// returns vector with elements of kind (vertex1,vertex2,weight)
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
	// if vertex doesn`t exist, nothing to delete
	if (!this->vertex_exists(vertex)) {
		return;
	}
	for (auto it : this->_vertices) {
		erase_edge(it.first, vertex);
	}
	this->_vertices.erase(vertex);
}

template<class T>
std::vector<T> Graph<T>::get_vertex_set() {
	// returns vector with vertices
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
	//returns number of vertices
	return this->get_vertex_set().size();
}

template<class T>
bool Graph<T>::operator==(const Graph<T>& compare_graph) {
	Graph<T> compare = compare_graph;
	if (this->get_vertex_set() != compare.get_vertex_set()) {
		return false;
	}
	if (this->get_edge_set() != compare.get_edge_set()) {
		return false;
	}
	return true;
}

template<class T>
bool Graph<T>::operator!=(const Graph<T>& compare_graph) {
	return !this->operator==(compare_graph);
}

template<class T>
void Graph<T>::BFS(T start_vertex) {
	// check vertex existence
	if (!this->vertex_exists(start_vertex)) return;
	// check over,vertex exists
	std::queue<T> vert_queue;
	std::vector<T> visited_vertices;
	visited_vertices.push_back(start_vertex);
	vert_queue.push(start_vertex);
	std::cout << "BFS from " << start_vertex << " vertex: ";
	while (!vert_queue.empty()) {
		for (auto it = this->_vertices.at(start_vertex).begin(); it != this->_vertices.at(start_vertex).end(); ++it) {
			insert_in_queue_if_unique(vert_queue, visited_vertices, (*it)._vertex2);
		}
		std::cout << vert_queue.front() << " ";
		vert_queue.pop();
		if (vert_queue.empty()) {
			std::cout << std::endl;
			return;
		}
		start_vertex = vert_queue.front();
		visited_vertices.push_back(start_vertex);
	}
}

template<class T>
void Graph<T>::DFS(T start_vertex) {
	// check vertex existence
	if (!this->vertex_exists(start_vertex)) return;
	// check over,vertex exists
	std::stack<T> vertices_to_visit;
	std::vector<T> visited_vertices;
	visited_vertices.push_back(start_vertex);
	std::cout << "DFS from " << start_vertex << " vertex: " << start_vertex << " ";
	while (true) {
		for (auto it = this->_vertices.at(start_vertex).begin(); it != this->_vertices.at(start_vertex).end(); ++it) {
			insert_in_stack_if_unique(vertices_to_visit, visited_vertices, (*it)._vertex2);
		}
		if (vertices_to_visit.empty()) {
			std::cout << std::endl;
			return;
		}
		std::cout << vertices_to_visit.top() << " ";
		start_vertex = vertices_to_visit.top();
		vertices_to_visit.pop();
		visited_vertices.push_back(start_vertex);
	}
}

template<class T>
int Graph<T>::find_path(T vertex1, T vertex2) {
	// checking if vertices exist
	if (!this->vertex_exists(vertex1) || !this->vertex_exists(vertex2)) return 0;
	// check over,vertices exist
	std::queue<T> vert_queue;
	std::vector<T> visited_vertices;
	std::unordered_map<T, int> paths;
	visited_vertices.push_back(vertex1);
	vert_queue.push(vertex1);
	// sort by BFS algorithm
	while (!vert_queue.empty()) {
		for (auto it = this->_vertices.at(vertex1).begin(); it != this->_vertices.at(vertex1).end(); ++it) {
			insert_in_queue_if_unique(vert_queue, visited_vertices, (*it)._vertex2);
		}
		paths.insert({ vert_queue.front(), 0 });
		vert_queue.pop();
		if (vert_queue.empty()) {
			std::cout << std::endl;
			break;
		}
		vertex1 = vert_queue.front();
		visited_vertices.push_back(vertex1);
	}
	// if there is no path to vertex2
	if (!is_visited(visited_vertices, vertex2)) return 0;
	// such path exists
	for (auto it1 : paths) {
		if (it1.first == vertex2) break;
		for (auto it2 : this->_vertices.at(it1.first)) {
			if (paths.at(it2._vertex2) == 0 && (it1.second + it2._weight > paths.at(it2._vertex2))) {
				paths.at(it2._vertex2) = it1.second + it2._weight;
			}
			else if (paths.at(it2._vertex2) != 0 && (it1.second + it2._weight < paths.at(it2._vertex2))) {
				paths.at(it2._vertex2) = it1.second + it2._weight;
			}
		}
	}
	return paths.at(vertex2);
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& graph) {
	Graph<T> new_gr = graph;
	os << "G = (V,E)\nV = {";
	for (auto it : graph._vertices) {
		os << " " << it.first;
	}
	os << " }\nE = {";
	std::vector<std::tuple<T, T, T>> edges = new_gr.get_edge_set();
	int size = edges.size();
	for (int i = 0; i < size; ++i) {
		os << " (" << std::get<0>(new_gr.get_edge_set()[i])
			<< "," << std::get<1>(new_gr.get_edge_set()[i]) << ","
			<< std::get<2>(new_gr.get_edge_set()[i]) << ")";
	}
	os << " }\n";
	return os;
}
