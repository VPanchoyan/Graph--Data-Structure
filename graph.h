#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <initializer_list>





template<class T>
class Graph {
	template<class S>
	struct Edge {
		Edge(S v1, S v2, int w) : _vertex1(v1), _vertex2(v2), _weight(w) {}
		S _vertex1;
		S _vertex2;
		int _weight;
	};
	friend std::ostream& operator<<(std::ostream& os, const Graph<T>&);
private:
	int _size;
	std::unordered_map<T,std::list<Edge<T>>> _vertices;
public:
	Graph() : _size(0) {};
	//Graph(std::initializer_list<std::pair<T, std::initializer_list<T>>> list);
	Graph<T> operator=(const Graph<T>&);
	void insert_vertex(T value);
	void insert_edge(T vertex1,T vertex2,int weight);
	void erase_vertex(T vertex);
	void erase_edge(T vertex1, T vertex2);
	std::vector<T> get_vertex_set();
	std::vector<std::tuple<T,T,T>> get_edge_set();
	//bool operator==(const Graph&);
	//bool operator!=(const Graph&);
	int get_number_of_vertex();
	void BFS(T start_vertex);
	void DFS(T start_vertex);
	//void find_path(T vertex1, T vertex2);
	bool vertex_exists(T vertex);
	void print_edges();
	void print_vertices();
};
