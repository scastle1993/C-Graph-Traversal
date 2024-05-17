
/**********************************************************************************************
 *
 * CIS269 - Data Structures
 * Pima College - Spring 2024
 * Chapter 20 - Pg 1452- Ex #1 & 2
 * Graph Traversal - "main.cpp"
 *
 * This program demonstrates the graphType ADT and its depth-first and breadth-first methods 
 * of traversal.
 *
 * Author: Sean Castle
 *
**********************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include "graphType.h"

using namespace std;

int main() {
    int maxVertices = 10;
    graphType<int> graph(maxVertices);
    
    // Input
    ifstream infile("graph.txt");
    if (!infile) {
        cout << "Cannot open input file." << endl;
        return 1;
    }

    int gSize;
    infile >> gSize;

    vector<vector<int>> adjLists(gSize);
    for (int i = 0; i < gSize; i++) {
        int vertex;
        infile >> vertex;

        int adjacentVertex;
        infile >> adjacentVertex;
        while (adjacentVertex != -999) {
            adjLists[vertex].push_back(adjacentVertex);
            infile >> adjacentVertex;
        }
    }

     // Processing
     graph.createGraph(gSize, adjLists);

     infile.close();

     // Output
     cout << "Graph Adjacency Lists:" << endl;
     graph.printGraph();
     cout << endl;
     
     cout << "Depth-First Traversal:" << endl;
     graph.depthFirstTraversal();
     cout << endl;

     cout << "Depth-First Traversal Starting from Vertex 2:" << endl;
     graph.dftAtVertex(2);
     cout << endl << endl;
     
     cout << "Breadth-First Traversal:" << endl;
     graph.breadthFirstTraversal();
     cout << endl;


    return 0;
}