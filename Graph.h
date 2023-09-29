/*
Author: Michael Mathews
Assignment Title: Strongly Connected Components
Assignment Description: Find the members at the UN that should be uninvited
    based on their lack of ability to communicate based on the languages
    they speak
Due Date: 10/3/22
Date Created: 10/3/22
Date Last Modified: 10/3/22
*/

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;
 
class Graph{
private:
    int vertCount;
    list<int> *graph;
public:
    /*
    precondition: no graph created
    postcondition: graph created
    return type: none
    description: default constructor for graph
    */
    Graph(int);
    /*
    precondition: no edge between vertices
    postcondition: edge created between vertices
    return type: none
    description: adds an edge between two vertices in a graph
    */
    void addEdge(int, int);
    /*
    precondition: nothing on stack
    postcondition: stack is full
    return type: none
    description: populates stack based on DFS and which vertices need to
     searched first
    */
    void fillStack(int v, bool[], stack<int>&);
    /*
    precondition: no vertex is found
    postcondition: vertices found
    return type: vector<int> that holds members of scc
    description: finds the members of a scc through dfs
    */
    vector<int> DFS(int, bool[], vector<int>);
    /*
    precondition: graph is in order
    postcondition: graph is reversed
    return type: Graph that holds vertices
    description: Reverses a graph according to KOSARAJU'S algorithm
    */
    Graph getReverse();
    /*
    precondition: list of scc not found
    postcondition: sccs found
    return type: vector<vector<int>> that holds vectors of each scc and
        their vertices
    description: performs KOSARAJU's algorithm on an adjacency list of vertices
     in a graph
    */
    vector<vector<int>> getSCC();
};

#endif /* Graph_h */
