#include<bits/stdc++.h>
using namespace std;

int main(){

    cout << "Enter number of vertices:";
    int V; cin >> V;
    cout << "Enter number of edges:";
    int m; cin >> m;

	vector<pair<int,int> > adj[V]; 
    for(int i = 0; i< m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
        adj[y].push_back({x, wt});
    }

    int parent[V];
    int key[V]; 
    bool mstSet[V]; 
  
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX, mstSet[i] = false; 
    } 

    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;

    for (int i = 0; i < V - 1; i++){ 
        int mini = INT_MAX, u; 
  
        for (int j = 0; j < V; j++) {
            if (mstSet[j] == false && key[j] < mini){
               mini = key[j], u = j; 
            }          
        }

        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    for(int i = 0; i < V; i++){
        ansWeight+= key[i];
    }
    cout << "MINMUM SUM : " <<  ansWeight << endl;

    for(int i = 0; i< V; i++){
        cout << "(" << parent[i] << " - " << i << ")"<< " " << endl;
    }
    cout << endl;
}