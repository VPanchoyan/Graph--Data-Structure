#include <iostream>
#include <vector>

template<class T>
struct vertex{
    vertex(){}
    vertex(T vertex_value) : value(vertex_value){}
    T value;
    std::vector<vertex> links;
};

template<class T>
struct edge{
    edge(int w,T v1,T v2) : weight(w), left(v1),right(v2) {}
    T left;
    T right;
    int weight;
};

template<class T>
class graph{
    //friend std::ostream& operator<<(std::ostream&,const graph<T>&);
    friend bool operator==(const graph<T>&,const graph<T>&);
    friend bool operator!=(const graph<T>&,const graph<T>&);
    private:
        std::vector<vertex<T>> vertices;
        std::vector<edge<T>> edges;
        int size;
    public:
        graph<T>() : size(0){};
        /*graph<T>(const graph<T>&);*/
        
        /*void operator+(const graph<T>&);
        graph<T>& operator+=(const graph<T>&);*/
        void insert_vertex(T);
        void insert_edge(int,T,T,bool bidirectional = true);
        std::vector<vertex<T>> get_vertex_set();
        std::vector<edge<T>> get_edge_set();
        void erase_vertex(T);
        void erase_edge(T,T);
        /*int get_number_of_vertex();
        void DFS();
        void BFS();
        int find_path(T,T);*/
        void print_graph();
};
