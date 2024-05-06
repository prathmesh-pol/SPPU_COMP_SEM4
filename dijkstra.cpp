#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 +1;
const int N = 1e5 +10;

vector<pair<int, int>> adj[N];

void dijkstra(int source, int n){

    vector<int>dist(N, M);
    vector<int>vis(N, 0);

    set<pair<int,int>>st;
    st.insert({0,source});
    dist[source] = 0;


    while(st.size() > 0){
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        // if(vis[v] == 1) continue;

        // vis[v] = 1;
        for(auto child : adj[v]){
            int child_v = child.first;
            int wt = child.second;

            // agr hm curr distance ko chota kr skte hain toh chota kr denge:
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    for(int i = 1; i<= n; i++){
        cout << dist[i] <<" ";
    }


}

int main(){
    cout << "Number of vertices: ";
    int v; cin >> v;
    cout << "Number of edges: ";
    int e; cin >> e;

    for(int i = 0; i< e; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
    }

    cout << "Enter source: ";
    int s; cin >> s;

    dijkstra(s, v);

}