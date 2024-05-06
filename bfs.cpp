#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int>adj[N];
bool vis[N];



void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

}



int main(){
    cout << "Enter number of vertices: ";
    int n; 
    cin >> n;
    cout << "Enter number of edges: ";
    int e; cin >> e;

    for(int i = 0; i< e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(v);
    }  

    bfs(1);
}