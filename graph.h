#include <iostream>
#include <vector>
#include <set>

struct vertex{
    vertex(int vertex_value) : value(vertex_value){}
    int value;
    std::vector<vertex> links;
};

struct edge{
    edge(int w,vertex& v1,vertex& v2) : weight(w),left(&v1),right(&v2){}
    int weight;
    vertex* left;
    vertex* right;
};

class graph{
    friend std::ostream& operator<<(const std::ostream&,const graph&);
    private:
        std::vector<vertex> vertices;
        std::vector<edge> edges;
        int size;
    public:
        graph() : size(0){};
        graph(const graph&);
        bool operator==(const graph&);
        bool operator!=(const graph&);
        void operator+(const graph&);
        graph& operator+=(const graph&);
        void insert_vertex(int);
        void insert_edge(int,vertex&,vertex&);
        std::vector<vertex> get_vertex_set();
        std::vector<edge> get_edge_set();
        void erase_vertex(vertex&);
        void erase_edge(edge&);
        int get_number_of_vertex();
        void DFS();
        void BFS();
        int find_path(vertex,vertex);
};
