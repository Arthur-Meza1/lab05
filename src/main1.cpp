#include "graph.h"
#include <iostream>
using namespace std;

int main() {

    Graph G = GRAPHinit(5);

    UGRAPHinsertEdge(G, 0, 1);
    UGRAPHinsertEdge(G, 0, 2);
    UGRAPHinsertEdge(G, 1, 3);
    UGRAPHinsertEdge(G, 1, 4);
    UGRAPHinsertEdge(G, 2, 4);

    cout << "\nLista de adyacencia:" << endl;
    for (int v = 0; v < G->V; v++) {
        cout << v << ": ";
        for (link t = G->adj[v]; t != nullptr; t = t->next)
            cout << t->w << " ";  
        cout << endl;
    }

    GRAPHdfsIterativo(G, 0);

    GRAPHdestroy(G);
    return 0;
}
