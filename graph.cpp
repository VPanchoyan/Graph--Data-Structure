#include "graph.h"
#include <set>
#include <vector>

bool graph::operator==(const graph&);
bool graph::operator!=(const graph&);
void graph::operator+(const graph&);
graph& operator+=(const graph&);
void graph::insert_vertex(int new_vertex_val){
    if(std::__count_if(this->vertices.begin(), this->vertices.end(), new_vertex_val)){
        std::cout << "Vertex already exists." << std::endl;
        return;
    }
    vertex new_vertex_val(new_vertex_val);
    this->vertices.push_back(new_vertex_val);
    ++(this->size);
}
void graph::insert_edge(int weight,vertex& v1,vertex& v2){
    if(std::__count_if(v1.links.begin(),v1.links.end(),&v2) || std::__count_if(v2.links.begin(),v2.links.end(),&v1)){
        std::cout << "Edge already exists." << std::endl;
        return;
    }
    edge new_edge(weight,v1,v2);
    this->edges.push_back(new_edge);
    v1.links.push_back(v2);
}
std::vector<vertex> graph::get_vertex_set();
std::vector<edge> graph::get_edge_set();
void graph::erase_vertex(vertex&);
void graph::erase_edge(edge&);
int graph::get_number_of_vertex();
void graph::DFS();
void graph::BFS();
int graph::find_path(vertex,vertex);
