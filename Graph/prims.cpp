#include <iostream>
#include <vector>
#include <queue>
#include<list>
#include<stack>
using namespace std;

/* The class Edge represents an edge in a graph with two integer values, v and w. */
class Edge{
public:
    int v;
    int w;

    Edge(int v, int w){
        this->v = v;
        this->w = w;
    }
};

/**
 * The function implements Prim's algorithm to find the minimum spanning tree in a graph represented as
 * an adjacency list.
 */
int prims(vector<vector<Edge>> &graph,int V){
   /* The code snippet `vector<int> vis(V,false);` creates a vector named `vis` of size `V` initialized
   with `false` values. This vector is used to keep track of visited vertices during the execution
   of Prim's algorithm. */
    vector<int> vis(V,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    
    /* This code snippet is the implementation of Prim's algorithm for finding the minimum spanning
    tree in a graph. Here's a breakdown of what the code is doing: */
    pq.push({0,0});
    int cost = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        int v = pq.top().first;

        pq.pop();

        if(!vis[u]){
            vis[u] = true;
            cost += v;

            for(auto e : graph[u]){
                pq.push({e.w,e.v});
            }
        }
    }

    return cost;
}

int main(){
    int V = 4;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,10));
    graph[0].push_back(Edge(2,15));
    graph[0].push_back(Edge(3,30));

    graph[1].push_back(Edge(0,10));
    graph[1].push_back(Edge(3,40));

    graph[2].push_back(Edge(0,15));
    graph[2].push_back(Edge(3,50));

    graph[3].push_back(Edge(0,30));
    graph[3].push_back(Edge(1,40));
    graph[3].push_back(Edge(2,50));

    int ans = prims(graph,V);

    cout<<ans<<endl;
    return 0;
}