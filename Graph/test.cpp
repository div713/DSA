#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct DNode {
        int cost;
        int vertex;
        string path;
    
        DNode(int cost, int v, string p){
            this->cost = cost;
            vertex= v;
            path = p;
        }
};

struct compare
    {
        bool operator()(DNode* n1, DNode* n2){
            if(n1->cost == n2->cost){
                return n1->path > n2-> path;
            }
            return n1->cost > n2->cost ;
        }
    } ;


int main() {
    
    int V;
    int e;
    cin>>V>>e;
    
    int vertexW[V];
    
    for(int i=0; i<V; i++){
        cin>>vertexW[V];
    }
    
    vector<vector<pair<int,int>>> adj(V);
    
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    int src;
    int dest;
    
    cin>>src>>dest;
    
    priority_queue< DNode* , vector<DNode*>, compare> pq;
    
    
    
    
    int finalcost=0;
    
    pq.push(new DNode(vertexW[0],0,"0"));
    
    while(pq.size() != 0){
        DNode* rn= pq.top();
        
        pq.pop();
        
        if(rn->vertex == dest){
            cout<< rn->path << endl;
            finalcost = rn->cost;
            break;
        }
        
        
        
        for(long unsigned int i=0; i<adj[rn->vertex].size(); i++){
            
            int nbr= adj[rn->vertex][i].first;
            int cost= adj[rn->vertex][i].second;
            
            
            pq.push(new DNode(rn->cost + cost + vertexW[nbr], nbr, rn-> path + to_string(nbr)));
            
        }
    }
    
    cout<<finalcost;
    
      
    return 0;
}