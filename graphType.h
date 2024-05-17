#ifndef GRAPH_TYPE_H
#define GRAPH_TYPE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "linkedQueueType.h"

using namespace std;

template <typename T>
class graphType {
public:
    bool isEmpty() const;
    //Function to determine whether the graph is empty.
    //Postcondition: Returns true if the graph is empty;
    // otherwise, returns false.

    void createGraph(int size, const vector<vector<int>>& adjLists);
    //Function to create a graph.
    //Postcondition: The graph is created using the
    // adjacency list representation.

    void clearGraph();
    //Function to clear graph.
    //Postcondition: The memory occupied by each vertex
    // is deallocated.

    void printGraph() const;
    //Function to print graph.
    //Postcondition: The graph is printed.

    void depthFirstTraversal();
    //Function to perform the depth first traversal of
    //the entire graph.
    //Postcondition: The vertices of the graph are printed
    // using depth first traversal algorithm.

    void dftAtVertex(int vertex);
    //Function to perform the depth first traversal of
    //the graph at a node specified by the parameter vertex.
    //Postcondition: Starting at vertex, the vertices are
    // printed using depth first traversal
    // algorithm.

    void breadthFirstTraversal();
    //Function to perform the breadth first traversal of
    //the entire graph.
    //Postcondition: The vertices of the graph are printed
    // using breadth first traversal algorithm.

    graphType(int size = 0);
    //Constructor
    //Postcondition: gSize = 0; maxSize = size;
    // graph is a vector of vectors.

    ~graphType();
    //Destructor
    //The storage occupied by the vertices is deallocated.

private:
    int maxSize; //maximum number of vertices
    int gSize; //current number of vertices
    vector<vector<T>> graph; //vector to create adjacency lists

    void dft(int v, vector<bool>& visited);
    //Function to perform the depth first traversal of
    //the graph at a node specified by the parameter vertex.
    //This function is used by the public member functions
    //depthFirstTraversal and dftAtVertex.
    //Postcondition: Starting at vertex, the vertices are
    // printed using depth first traversal
    // algorithm.
};

template <typename T>
bool graphType<T>::isEmpty() const {
    return (gSize == 0);
}//end isEmpty

template <typename T>
void graphType<T>::createGraph(int size, const vector<vector<int>>& adjLists) {
    if (gSize != 0) {
        clearGraph();
    }

    gSize = size;
    graph.resize(gSize);

    for (int i = 0; i < gSize; i++) {
        graph[i] = vector<T>(adjLists[i].begin(), adjLists[i].end());
    }
}//end createGraph

template <typename T>
void graphType<T>::clearGraph() {
    gSize = 0;
    graph.clear();
}

template <typename T>
void graphType<T>::printGraph() const {
    for (int i = 0; i < gSize; i++) {
        cout << i << ": ";
        for (const auto& vertex : graph[i]) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    cout << endl;
}//end clearGraph

template <typename T>
void graphType<T>::depthFirstTraversal() {
    vector<bool> visited(gSize, false);
    for (int index = 0; index < gSize; index++) {
        if (!visited[index]) {
            dft(index, visited);
        }
    }
}//end depthFirstTraversal

template <typename T>
void graphType<T>::dftAtVertex(int vertex) {
    vector<bool> visited(gSize, false);
    dft(vertex, visited);
}//end dftAtVertex

template <typename T>
void graphType<T>::breadthFirstTraversal() {
    vector<bool> visited(gSize, false);
    vector<int> queue;

    for (int index = 0; index < gSize; index++) {
        if (!visited[index]) {
            queue.push_back(index);
            visited[index] = true;
            cout << " " << index << " ";

            while (!queue.empty()) {
                int u = queue.front();
                queue.erase(queue.begin());

                for (const auto& w : graph[u]) {
                    if (!visited[w]) {
                        queue.push_back(w);
                        visited[w] = true;
                        cout << " " << w << " ";
                    }
                }
            }
        }
    }
}//end breadthFirstTraversal

template <typename T>
graphType<T>::graphType(int size) {
    maxSize = size;
    gSize = 0;
}//end default constructor

template <typename T>
graphType<T>::~graphType() {
    clearGraph();
}//end destructor

template <typename T>
void graphType<T>::dft(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << " " << v << " ";

    for (const auto& w : graph[v]) {
        if (!visited[w]) {
            dft(w, visited);
        }
    }
}//end dft

#endif // GRAPH_TYPE_H