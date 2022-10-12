# Lab-projects

## Graph 

### Topics

- [What is Graph?](#Whatisgraph?)
  - [Types of Graphs](#TypesofGraphs)
    - [Undirected Graph](#UndirectedGraph)
    - [Directed Graph](#DirectedGraph)
    - [Weighted Graph](#WeightedGraph)
    - [Mixed Graph](#MixedGraph)
    
- [Graph Data Structure](#GraphDataStructure)
   - [Implementation methods](#implmethods)
   - [My implementation](#myimpl)
- [Applications of Graphs](#Applicationsofgraphs)

- [How to use this structure in your project?](#howtouse)

## What is Graph?
> A Graph is a non-linear data structure consisting of vertices and edges. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(E, V). The edges can be referred to as the connections between vertices.The edge of the graph sometimes contains the Weight, which is used to show the _strength_ of each connection between vertices.

### Types of Graphs
There are many types of Graphs but most common types are undirected,directed,weighted and mixed Graphs.

- [Undirected Graph](#UndirectedGraph)

<img src="https://user-images.githubusercontent.com/114210044/195458998-3779a49d-0ef8-4b6a-a4cf-0fcab6604b5d.png" alt="drawing" width="200"/>
The key factor is that the order of the two connected vertices is unimportant. So there are no directions.


- [Directed Graph](#DirectedGraph)
<img src="https://upload.wikimedia.org/wikipedia/commons/5/51/Directed_graph.svg" alt="drawing" width="200"/>
Here, the order of the two connected vertices is important. So there are directions.

- [Weighted Graph](#WeightedGraph)
<img src="https://i.stack.imgur.com/Mu6VZ.png" alt="drawing" width="200"/>
Here, the numbers on the edges are used to show the strength of each connection between vertices. By saying strength we can understand a cost,distance,etc.

- [Mixed Graph](#MixedGraph)
<img src="https://codepumpkin.com/wp-content/uploads/2017/03/graph.jpg" alt="drawing" width="200"/>
In Mixed Graph there can be undirected or directed weighted edges.

## Graph Data Structure

### Implementation methods
Graphs have a variety of different implementations, depending on the host language.
Most common representations are 
- with adjacency matrix
- with adjacency list

There are many algorithms to traverse the graph such as BFS (Breadth First Search), DFS (Depth First Search), etc.
More information about BFS and DFS: [https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/)

### My implementation
My implementation is for directed and weighted graphs.
In this implementation is used adjacency list.
Other data structures used: unordered_map, queue, stack, list

#### Defined operators

- `Copy operator assignment = `    (allow to copy)
- `Operator stream out (cout) <<`  (print graph in G = (V,E) form)
- `Operator is equal to ==`        (check equality of two graphs)
- `Operator is not equal to !=`    (check inequality of two graphs)

#### Defined functions
- `insert_vertex(value)`                 (create new vertex with value)
- `insert_edge(vertex1,vertex2,weight)`  (create new edge between vertex1 and vertex2 with some weight)
- `get_vertex_set()`                     (get all vertices of the graph)
- `get_edge_set()`                       (get all edges of the graph)
- `erase_vertex(value)`                  (erase the vertex with value from the graph)
- `erase_edge(vertex1,vertex2)`          (erase the edge between vertex1 and vertex2 from the graph)
- `get_number_of_vertex()`               (get quantity of all vertices of the graph)
- `BFS(start_vertex)`                    (traverse graph with BFS algorithm from some vertex)
- `DFS(start_vertex)`                    (traverse graph with DFS algorithm from some vertex)
- `find_path(vertex1,vertex2)`           (get the shortest path lenght from vertex1 to vertex2)

**In case of any emergency situation such as:
inserting already existing vertex,
erasing non-existing vertex,
inserting already existing edge,
erasing non-existing edge,
inserting edge between non-existing vertices,
traversing from non-existing vertex,
finding path between non-existing vertices,
the functions do nothing (they return void)**

## Applications of Graphs

Graphs are used in vast area of science and technologies. Some of them are given below:
1. Computer Science
2. Electrical Engineering
3. Linguistics
4. Physics and Chemistry
5. Computer Network
6. Social Sciences
7. Biology
8. Mathematics
9. General fields

## How to use this structure in your project?
The ease of use is undescribable!
1. Clone this repository
2. Add files to their location in your project (Header Files, Source Files)
3. Create objects of Graphs and enjoy !!!
