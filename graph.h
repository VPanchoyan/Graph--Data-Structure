#pragma once
#include <iostream>
#include <vector>


struct adjacent_vertex {
	adjacent_vertex() : weight(0),value(NULL),connect(nullptr) {}
	int weight;
	int value;
	adjacent_vertex* connect;
};

struct vertex {
	vertex(int val) : value(val),connections_head(nullptr) {}
	int value;
	adjacent_vertex* connections_head;
};

class graph {
	friend std::ostream& operator<<(std::ostream& os, const graph&);
private:
	std::vector<vertex> vertices;
public:
	graph() {};
	graph(const graph&) {}; // copy operator assingment
	graph& operator=(const graph&); // move operator assignment
	void insert_vertex(int);
	void insert_edge(int, int,int);
	void erase_vertex(int);
	void erase_edge(int, int);
	std::vector<int> get_vertex_set();
	std::vector<std::vector<int>> get_edge_set();
	bool operator==(const graph&);
	bool operator!=(const graph&);
	void BFS(int);
};

