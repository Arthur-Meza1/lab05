#include "graph.h"
#include <iostream>

int main() {
    const char* filename = "/home/arthur-max/Documentos/ADA_lab/lab05/src/grafo.txt";

    Graph G = GRAPHreadFromFile(filename);
    if (!G) return 1;

    GRAPHshow(G);

    GRAPHdfs(G);

    return 0;
}
