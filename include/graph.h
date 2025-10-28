#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using vertex = int;

typedef struct node* link;
struct node {
    vertex w;   
    link next;  
};

typedef struct graph* Graph;
struct graph {
    int V;        
    int E;        
    link* adj;    
};


Graph GRAPHinit(int V);

void UGRAPHinsertEdge(Graph G, vertex v, vertex w);

void GRAPHshow(Graph G);

void GRAPHdestroy(Graph G);

Graph GRAPHreadFromFile(const std::string& filename);

void GRAPHdfs(Graph G);

void GRAPHdfsIterativo(Graph G, int s);

#endif
