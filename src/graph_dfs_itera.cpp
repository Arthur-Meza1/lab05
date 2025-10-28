#include "graph.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void GRAPHdfsIterativo(Graph G, int s) {
    vector<bool> visitado(G->V, false);   
    stack<int> pila;                       
    pila.push(s);

    cout << "DFS iterativa:" << endl;

    while (!pila.empty()) {
        int v = pila.top();
        pila.pop();

        if (!visitado[v]) {
            visitado[v] = true;
            cout << v << " ";

            vector<int> vecinos;
            for (link t = G->adj[v]; t != nullptr; t = t->next)  
                vecinos.push_back(t->w);                         

            for (auto it = vecinos.rbegin(); it != vecinos.rend(); ++it) {
                if (!visitado[*it])
                    pila.push(*it);
            }
        }
    }
    cout << endl;
}
