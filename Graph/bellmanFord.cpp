#include <iostream>
#include <vector>
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

void bellmanFord(int src, vector<vector<Edge>> &graph, int V){
    vector<int> dist(V,INT_MAX);

    dist[src] = 0;

    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){
            for(auto edge : graph[u]){
                if(dist[edge.v] > dist[u] + edge.w){
                    dist[edge.v] = dist[u] + edge.w;
                }
            }
        }
    }

    for(int d : dist){
        cout<<d<<" ";
    }
    cout<<endl;
}

int main(){
    int V = 6;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,-4));
    graph[1].push_back(Edge(3,-1));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(5,-5));
    graph[4].push_back(Edge(3,2));

    bellmanFord(0,graph,6);
}