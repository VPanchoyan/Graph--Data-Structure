#include "graph.h"

//template<class T>
//bool graph<T>::operator==(const graph<T>&);
//
//template<class T>
//bool graph<T>::operator!=(const graph<T>&);
//
//template<class T>
//void graph<T>::operator+(const graph<T>&);
//
//template<class T>
//graph<T>& operator+=(const graph<T>&);

template<class T>
void graph<T>::insert_vertex(T new_vertex_val){
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        if ((*it).value == new_vertex_val) {
            std::cout << "Vertex " << new_vertex_val << " already exists." << std::endl;
            return;
        }
    }
    vertex<T> new_vx_val(new_vertex_val);
    this->vertices.push_back(new_vx_val);
    ++(this->size);
}

template<class T>
void graph<T>::insert_edge(int weight,T v1,T v2,bool bidirectional){
    vertex<T> ver1;
    vertex<T> ver2;
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        if ((*it).value == v1) {
            ver1 = *it;
        }
        if ((*it).value == v2) {
            ver2 = *it;
        }
    }        
    if (ver1.value == v1 && ver2.value == v2) {
        for (auto it = this->edges.begin(); it != this->edges.end(); ++it) {
            if ((*it).left == v1 && (*it).right == v2) {
                std::cout << "Edge already exists." << std::endl;
                return;
            }
        }
        edge<T> new_edge(weight,v1,v2);
        this->edges.push_back(new_edge);
        if (bidirectional) {
            ver1.links.push_back(ver2);
            ver2.links.push_back(ver1);
        }
        else {
            ver1.links.push_back(ver2);
        }
    }
    else {
        std::cout << "No vertices to connect." << std::endl;
        return;
    }
}

template<class T>
std::vector<vertex<T>> graph<T>::get_vertex_set() {
    return this->vertices;
}

template<class T>
std::vector<edge<T>> graph<T>::get_edge_set() {
    return this->edges;
}

//template<class T>
//void graph<T>::erase_vertex(T);
//
//template<class T>
//void graph<T>::erase_edge(T,T);
//
//template<class T>
//int graph<T>::get_number_of_vertex();
//
//template<class T>
//void graph<T>::DFS();
//
//template<class T>
//void graph<T>::BFS();
//
//template<class T>
//int graph<T>::find_path(T,T);
