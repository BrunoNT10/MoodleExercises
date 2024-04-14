#include <iostream>
#include <list>

using namespace std;

#define VERTICES 10

bool verificar_conexao(bool vertices[VERTICES][VERTICES], int n_vertices, int start){
    list<int> fila_espera;
    bool visitado[n_vertices];
    
    for (int i=0; i<n_vertices; i++){
        visitado[i] = false;
    }
    
    fila_espera.push_back(start);
    int atual;
    
    while(!fila_espera.empty()){
        atual = fila_espera.front();
        visitado[atual] = true;
        
        for(int i=0; i<n_vertices; i++){
            if(vertices[atual][i] == true && visitado[i] == false){
                fila_espera.push_back(i);
            }
        }
        fila_espera.pop_front();
    }
    
    for (int i=0; i<n_vertices; i++){
        if(visitado[i] == false){
            return false;
        }
    }
    
    return true;
}

int main() {
    bool vertices[VERTICES][VERTICES];
    for (int i=0; i<VERTICES; i++){
        for (int j=0; j<VERTICES; j++){
            vertices[i][j] = false;
        }
    }   
    
    int n_vertices, start;
    
    cin >> n_vertices >> start;
    
    int V = 0, E = 0;
    while(V != -1 && E != -1){
        cin >> V >> E;
        vertices[V][E] = true;
    }
    
    bool conexo;
    conexo = verificar_conexao(vertices, n_vertices, start);
    
    if (conexo) {
        cout << "Conexo" << endl;
    }
    else {
        cout << "Nao conexo" << endl;
    }
    
}