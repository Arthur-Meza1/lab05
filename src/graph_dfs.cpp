#include <iostream>
#include "graph.h"

using namespace std;

static int cnt;        
static int indent = 0; 
static int* pre;       

static void printIndent() {
    for (int i = 0; i < indent; ++i)
        cout << "  "; 
}

static void dfsR(Graph G, vertex v) {
    printIndent();
    cout << "entrando a dfsR(" << v << ")\n";

    pre[v] = cnt++;

    indent++; 

    for (link a = G->adj[v]; a != NULL; a = a->next) {
        vertex w = a->w;
        printIndent();
        cout << "explorando arista (" << v << "," << w << ")\n";

        if (pre[w] == -1) {
            dfsR(G, w); 
        } else {
            printIndent();
            cout << "ya visitado " << w << "\n";
        }
    }

    indent--; 
    printIndent();
    cout << "saliendo de dfsR(" << v << ")\n";
}

void GRAPHdfs(Graph G) {
    pre = new int[G->V];
    cnt = 0;
    indent = 0;

    for (vertex v = 0; v < G->V; ++v)
        pre[v] = -1;

    cout << "iniciar el recorrido DFS\n";

    for (vertex v = 0; v < G->V; ++v) {
        if (pre[v] == -1) {
            cout << "\nOtra etapa desde  " << v << "\n";
            dfsR(G, v);
        }
    }

    cout << "\nfin del recorrido DFS\n";

    cout << "\norden de visita (pre): ";
    for (vertex v = 0; v < G->V; ++v)
        cout << pre[v] << " ";
    cout << "\n";

    delete[] pre;
}

