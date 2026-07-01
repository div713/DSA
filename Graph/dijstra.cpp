#include <iostream>
#include <vector>
#include <queue>
#include<list>
#include<stack>
using namespace std;

class Edge{
public:
    int v;
    int w;

    Edge(int v, int w){
        this->v = v;
        this->w = w;
    }
};

void dijstra(int src, vector<vector<Edge>> &graph, int V){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V,INT_MAX);
    dist[src] = 0;

    pq.push({dist[src],src});

    while(!pq.empty()){
        int u = pq.top().first;
        int s = pq.top().second;
        pq.pop();

        for(auto edge : graph[s]){
            if(dist[edge.v] > dist[s] + edge.w){
                dist[edge.v] = dist[s] + edge.w;
                pq.push({dist[edge.v], edge.v});
            }
        }
    }

    for(int i=0; i<V; i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    int V = 6;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(5,5));
    graph[4].push_back(Edge(3,2));


    dijstra(0,graph,V);
}