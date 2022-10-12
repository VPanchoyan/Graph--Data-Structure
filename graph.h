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
	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const Graph<T>&);
private:
	int _size;
	std::unordered_map<T,std::list<Edge<T>>> _vertices;
public:
	Graph() : _size(0) {};
	/*Graph(const Graph<T>&& new_graph) : _size(0), _vertices(NULL) {
		_vertices = new_graph._vertices;
		_size = new_graph._size;
		new_graph._size = 0;
		new_graph._size = NULL;
	}
	Graph<T>& operator=(const Graph<T>&& new_graph) {
		if (this != new_graph) {
			_vertices = new_graph._vertices;
			_size = new_graph._size;
			new_graph._size = 0;
			new_graph._size = NULL;
		}
		return *this;
	}*/
	Graph<T> operator=(const Graph<T>&);
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
	void DFS(T start_vertex);
	int find_path(T vertex1, T vertex2);
	bool vertex_exists(T vertex);
	void print_edges() ;
	void print_vertices() ;
};
