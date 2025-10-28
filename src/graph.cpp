#include "graph.h"
using namespace std;

Graph GRAPHinit(int V) {
    Graph G = new graph;
    G->V = V;
    G->E = 0;
    G->adj = new link[V];
    for (int v = 0; v < V; ++v)
        G->adj[v] = NULL;
    return G;
}

void UGRAPHinsertEdge(Graph G, vertex v, vertex w) {
    if (v == w) return; 

    link nw = new node{w, G->adj[v]};
    G->adj[v] = nw;

    link nv = new node{v, G->adj[w]};
    G->adj[w] = nv;

    G->E++;
}

void GRAPHshow(Graph G) {
    cout << "Grafo con " << G->V << " vertices y " << G->E << " aristas:\n";
    for (int v = 0; v < G->V; ++v) {
        cout << v << ":";
        for (link a = G->adj[v]; a != NULL; a = a->next)
            cout << " " << a->w;
        cout << "\n";
    }
}

void GRAPHdestroy(Graph G) {
    for (int v = 0; v < G->V; ++v) {
        link a = G->adj[v];
        while (a != NULL) {
            link t = a->next;
            delete a;
            a = t;
        }
    }
    delete[] G->adj;
    delete G;
}

Graph GRAPHreadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "error al abrir " << filename << "\n";
        exit(1);
    }

    int V;
    fin >> V;
    Graph G = GRAPHinit(V);

    std::string line;
    std::getline(fin, line);

    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        int v, w;
        ss >> v;
        while (ss >> w) {
            if (v < V && w < V)
                UGRAPHinsertEdge(G, v, w);
        }
    }

    fin.close();
    return G;
}
