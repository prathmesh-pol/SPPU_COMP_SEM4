#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;

vector<int> adj[N];
bool vis[N];

void dfs(int vertex){
    // Take action on vertex after entering the vertex;
    cout << vertex <<endl;
    vis[vertex] = true;

    for(int child : adj[vertex]){
        //Take action on child before entering the child node
        cout << "parent" << vertex << ", child" << child << endl;
        if(vis[child]) continue;

        dfs(child);
        // Take action on child after existing child node
    }
    //Take action on vertex before existing the vertex
}


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i< m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

}