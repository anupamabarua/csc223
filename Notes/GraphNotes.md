# Chapter 13 notes
## 13.1 Introduction
- A graph is an abstract data structure that is used to implement the mathematical concept of graphs.
- collection of vertices aka nodes and edeges that connect the vertices
- Graphs are useful to model any situation where entities or things are related to each other in pairs
- Definition: A graph G is defined as an ordered set (V, E), where V(G) represents the set of
vertices and E(G) represents the edges that connect these vertices.
### Undirected Graph - edges do not have any direction associated with them
![unidrected graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/cycleGraph-300x156.png)

### Directed Graph - edges form an ordered pair
![directed graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/SCC1.png)

## 13.2 Graph Terminolgy
- Adjacent nodes or neighbours: For every edge, e = (u, v) that connects nodes u and v, the nodes u and v are the end-points and are said to be the adjacent nodes or neighbours.
- Degree of a node: egree of a node u, deg(u), is the total number of edges containing the node u. If deg(u) = 0, it means that u does not belong to any edge and such a node is known as an isolated node
- Regular graph: Where each vertex has the
same number of neighbours-every node has the
same degree-A regular graph with vertices of degree k is called a k–regular graph or a regular graph of degree k.

### Regular graph
![regular graph](https://thomasvilhena.com/images/p19/regular-graphs.png)

- Closed path: A path P is known as a closed path if the edge has the same end-points. That is, if v0 = v
- Simple path: A path P is known as a simple path if all the nodes in the path are distinct with an
exception that v0 may be equal to v n. If v0= vn, then the path is called a closed simple path.
- Cycle: A path in which the first and the last vertices are same. A simple cycle has no repeated
edges or vertices (except the first and last vertices).
- Connected graph: A graph is said to be connected if for any two vertices (u, v) in V there is a
path from u to v. That is to say that there are no isolated nodes in a connected graph. A connected
graph that does not have any cycle is called a tree
- Clique: In an undirected graph G= (V, E), clique is a subset of the vertex set C Õ V, such that for every two vertices in C, there is an edge that connects two vertices.
- Labelled graph or weighted graph: A graph is said to be labelled if every edge in the graph
is assigned some data. In a weighted graph, the edges of the graph are assigned some weight or
length. The weight of an edge denoted by w(e) is a positive value which indicates the cost of
traversing the edge. Figure 13.4(c) shows a weighted graph
- Multiple Edges
  - Distinct edges connecting the same pair of vertices
  - Example: (u, v) and (u, v)
- Loop
  - An edge that connects a vertex to itself
  - Example: (u, u)
- Multi-graph
  - A graph with multiple edges and/or loops
- Size of a Graph
  - Total number of edges in the graph
## Directed Graph (Digraph)
- A directed graph is a graph in which every edge has a direction
- Each edge is represented as an ordered pair (u, v)

### Properties of (u, v)
- Edge begins at u and terminates at v
- u is the origin (initial vertex)
- v is the destination (terminal vertex)
- u is the predecessor of v
- v is the successor of u
- u and v are adjacent
- Out-degree (outdeg(u))
  - Number of edges leaving node u
- In-degree (indeg(u))
  - Number of edges entering node u
- Degree of a node
  - deg(u) = indeg(u) + outdeg(u)
- Isolated Vertex
  - Degree = 0
  - Not connected to any edge
- Pendant Vertex (Leaf)
  - Degree = 1
- Cut Vertex
  - Removing it disconnects the graph

### Special Nodes
- Source
  - Positive out-degree and zero in-degree
- Sink
  - Positive in-degree and zero out-degree
## Reachability
- A node v is reachable from node u if there exists a directed path from u to v
## Connectivity Types
- Strongly Connected Digraph
  - There is a path between every pair of nodes in both directions
- Unilaterally Connected Digraph
  - For every pair (u, v), either u → v or v → u
- Weakly Connected Digraph
  - Graph is connected when edge directions are ignored

## Edge Types
- Parallel / Multiple Edges
  - Edges connecting the same pair of vertices
- Simple Directed Graph
  - No parallel edges
  - May contain cycles
  - At most one loop per node

## Transitive Closure

### Definition
- For G = (V, E), the transitive closure G* = (V, E*)
- (v, w) is in E* if and only if there is a path from v to w in G
### Purpose
- Used to determine reachability between nodes

### Applications
- Reachability analysis in distributed and parallel systems
- Compiler design (parsing automata)
- Recursive database queries

## Matrix Representation

- T[i][j] = 1 → j is reachable from i
- T[i][j] = 0 → otherwise

## Transitive Closure Algorithm (Warshall’s Algorithm)
### Initialization
```
if (i, j) is an edge:
    T[i][j] = 1
else:
    T[i][j] = 0
```
### Update Rule
```
T[i][j] = T[i][j] OR (T[i][k] AND T[k][j])
```
- Repeat for k = 1 to n
## Key Idea
- A path exists from i to j if:
  - It already exists, OR
  - It exists through an intermediate node k