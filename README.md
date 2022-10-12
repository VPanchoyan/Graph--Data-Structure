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

- [Applications of Graphs](#Applicationsofgraphs)

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

Graphs have a variety of different implementations, depending on the host language.
Most common representations are 
- with adjacency matrix
- with adjacency list


There are many algorithms to traverse the graph such as BFS (Breadth First Search), DFS (Depth First Search), etc.
More information about BFS and DFS: [https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/)
