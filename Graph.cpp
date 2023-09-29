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

#include "Graph.h"


Graph::Graph(int vertCount){
    this->vertCount = vertCount;
    graph = new list<int>[vertCount];
}
 
vector<int> Graph::DFS(int curr, bool visited[], vector<int> scc){
    visited[curr] = true;
    //add node to found
    scc.push_back(curr);
    list<int>::iterator i;
    for (i = graph[curr].begin(); i != graph[curr].end(); ++i){
        if (!visited[*i]){
            scc = DFS(*i, visited, scc);
        }
    }
    return scc;
}
 
Graph Graph::getReverse(){
    Graph g(vertCount);
    //reverse DFS
    for (int i = 0; i < vertCount; i++){
        list<int>::iterator j;
        for(j = graph[i].begin(); j != graph[i].end(); ++j){
            g.graph[*j].push_back(i);
        }
    }
    return g;
}
 
void Graph::addEdge(int curr, int to){
    graph[curr].push_back(to);
}
 
void Graph::fillStack(int curr, bool visited[], stack<int> &Stack){
    visited[curr] = true;
    list<int>::iterator i;
    for(i = graph[curr].begin(); i != graph[curr].end(); ++i){
        if(!visited[*i]){
            fillStack(*i, visited, Stack);
        }
    }
    Stack.push(curr);
}

vector<vector<int>> Graph::getSCC(){
    stack<int> Stack;
 
    //set vertices to not visited
    bool *visited = new bool[vertCount];
    for(int i = 0; i < vertCount; i++){
        visited[i] = false;
    }
 
    //fill stack with vertices depending on length of dfs
    for(int i = 0; i < vertCount; i++){
        if(visited[i] == false){
            fillStack(i, visited, Stack);
        }
    }
 
    //reverse dfs
    Graph g = getReverse();
 
    //set vertices to not visited
    for(int i = 0; i < vertCount; i++){
        visited[i] = false;
    }
 
    vector<int> scc;
    vector<vector<int>> total;
    while (Stack.empty() == false){
        //get vertex from top
        int curr = Stack.top();
        Stack.pop();
        //get scc
        if (visited[curr] == false){
            scc = g.DFS(curr, visited, scc);
            total.push_back(scc);
            scc.clear();
        }
    }
    return total;
}
