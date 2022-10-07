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
std::ostream& operator<<(const std::ostream& os, const graph<T>& g) {
    std::vector<vertex<char>> vertices = g.get_vertex_set();
    std::vector<edge<char>> edges = g.get_edge_set();
    std::cout << "G = (V,E)" << std::endl;
    std::cout << "V = {";
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        os << ' ' << (*it).value;
    }
    std::cout << " }" << std::endl << "E = { ";
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        os << "(" << (*it).left << "," << (*it).right << ") ";
    }
    std::cout << "}" << std::endl;
    return os;
}

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

template<class T>
void graph<T>::erase_vertex(T vertex) {
    for (auto it1 = this->vertices.begin(); it1 != this->vertices.end(); ++it1) {
        if ((*it1).value == vertex) {
            this->vertices.erase(it1);
            break;
        }
    }
    for (auto it2 = this->edges.begin(); it2 != this->edges.end(); ++it2) {
        if ((*it2).right == vertex || (*it2).left == vertex) {
            this->edges.erase(it2);
        }
    }
    for (auto it3 = this->vertices.begin(); it3 != this->vertices.end(); ++it3) {
        for (auto it4 = (*it3).links.begin(); it4 != (*it3).links.end(); ++it4) {
            if ((*it3).value == vertex) {
                (*it3).links.erase(it4);
                break;
            }
        }
    }
}

template<class T>
void graph<T>::erase_edge(T v1, T v2) {
    for (auto it1 = this->edges.begin(); it1 != this->edges.end(); ++it1) {
        if ((*it1).left == v1 && (*it1).right == v2 || (*it1).left == v2 && (*it1).right == v1) {
            edges.erase(it1);
        }
    }
    for (auto it2 = this->vertices.begin(); it2 != this->vertices.end(); ++it2) {
        if ((*it2).value == v1) {
            for (auto it4 = (*it2).links.begin(); it4 != (*it2).links.end(); ++it4) {
                if ((*it4).value == v2) {
                    (*it2).links.erase(it4);
                }
            }
        }
        if ((*it2).value == v2) {
            for (auto it5 = (*it2).links.begin(); it5 != (*it2).links.end(); ++it5) {
                if ((*it5).value == v1) {
                    (*it2).links.erase(it5);
                }
            }
        }
    }
}

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

template <class T>
void graph<T>::print_graph() {
    std::vector<vertex<char>> vertices = this->get_vertex_set();
    std::vector<edge<char>> edge = this->get_edge_set();
    std::cout << "G = (V,E)" << std::endl;
    std::cout << "V = {";
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        std::cout << ' ' << (*it).value;
    }
    std::cout << " }" << std::endl << "E = { ";
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        std::cout << "(" << (*it).left << "," << (*it).right << ") ";
    }
    std::cout << "}" << std::endl;
}