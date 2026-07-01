#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph{
    public:
    int n;
    unordered_map<int,vector<int>> neigh;
    vector<vector<int>> edges;

    Graph(int n){
        this->n = n;
    }

    void addEdge(int a, int b){
        edges.push_back({a,b});
        neigh[a].push_back(b);
    }

    void dfs(int node,vector<bool> &vis,stack<int> &st){
        if(vis[node]) return;

        vis[node] = true;

        for(int v : neigh[node]){
            dfs(v,vis,st);
        }

        st.push(node);
    }

    vector<int> topoSort(){
        vector<int> ans;
        stack<int> st;
        vector<bool> vis(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,vis,st);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    void reverseEdges(){
        neigh.clear();

        for(auto e : edges){
            neigh[e[1]].push_back(e[0]);
        }
    }

    void dfs2(int node, vector<bool> &vis){
        if(vis[node]) return;

        vis[node] = true;

        for(int v : neigh[node]){
            dfs2(v,vis);
        }
    }
};

int main(){
    int n = 5;
    Graph g(n);

    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);

    vector<int> topo = g.topoSort();
    g.reverseEdges();

    vector<bool> vis(n,false);
    int count = 0;

    for(int i=0; i<topo.size(); i++){
        if(!vis[topo[i]]){
            count++;
            g.dfs2(topo[i],vis);
        }
    }
    
    cout<<count<<endl;
    return 0;
}