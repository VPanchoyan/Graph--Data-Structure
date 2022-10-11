#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <initializer_list>


template<class T>
struct Edge{
	Edge(T v1,T v2,int w) : _vertex1(v1), _vertex2(v2), _weight(w) {}
	T _vertex1;
	T _vertex2;
	int _weight;
};

template<class T>
class Graph {
	friend std::ostream& operator<<(std::ostream& os, const Graph<T>&);
private:
	int _size;
	std::unordered_map<T,std::list<Edge<T>>> _vertices;
public:
	Graph() : _size(0) {};
	//Graph(std::initializer_list<std::pair<T, std::initializer_list<T>>> list);
	//graph(const graph& graph_to_copy) {	this->vertices = graph_to_copy.vertices;}; // copy operator assingment
	//graph& operator=(const graph&); // move operator assignment
	void insert_vertex(T value);
	void insert_edge(T vertex1,T vertex2,int weight);
	void erase_vertex(T vertex);
	void erase_edge(T vertex1, T vertex2);
	std::vector<T> get_vertex_set();
	std::vector<std::tuple<T,T,T>> get_edge_set();
	bool operator==(const Graph&);
	bool operator!=(const Graph&);
	int get_number_of_vertex();
	void BFS(T start_vertex);
	//void DFS(Tstart_vertex);
	//void find_path(T vertex1, T vertex2);

	bool vertex_exists(T vertex);
	void print_edges();
	void print_vertices();
};
