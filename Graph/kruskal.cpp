#include <iostream>
#include <vector>
using namespace std;
/* The class Edge represents an edge in a graph with attributes for the source vertex, destination
vertex, and weight. */
class Edge{
    public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        wt = w;
    }
};

class Graph{
    public:
    vector<Edge> edges;
    int V;

    vector<int> par;
    vector<int> rank;

    Graph(int n){
        V = n;
        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    /**
     * The above C++ code defines functions for finding the parent of a set element and performing
     * union by rank in a disjoint-set data structure.
     * 
     * @param x The `find` function is used to find the parent of a given element in a disjoint set
     * data structure. It uses path compression technique to optimize the find operation.
     * 
     * @return The `find` function is returning the root parent of the element `x` after performing
     * path compression.
     */
    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int a , int b){
        int para = find(a);
        int parb = find(b);

        if(rank[para] == rank[parb]){
            rank[para]++;
            par[parb] = para;
        }
        else if(rank[para] > rank[parb]){
            par[parb] = para;
        }
        else{
            par[para] = parb;
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u,v,wt));
    }

    void getinfo(){
        for(int i=0; i<V; i++){
            cout<<i<<": "<<par[i]<<", "<<rank[i]<<endl;
        }
    }

    /**
     * The function `kruskals` implements Kruskal's algorithm to find the minimum spanning tree of a
     * graph.
     * 
     * @return The function `kruskals()` is returning the minimum cost of a spanning tree found using
     * Kruskal's algorithm.
     */
    int kruskals(){
        sort(edges.begin(),edges.end(),[](Edge &a, Edge &b){return a.wt < b.wt;});

        int cost = 0;
        /* The code snippet you provided is a part of the `kruskals` function in the Graph class, which
        implements Kruskal's algorithm to find the minimum spanning tree of a graph. */
        for(auto e : edges){
            int para = find(e.u);
            int parb = find(e.v);

            if(para != parb){
                cost += e.wt;
                unionByRank(para,parb);
            }
        }

        return cost;
    }
};

int main(){
    Graph g(4);

    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);

    cout<<g.kruskals()<<endl;

    return 0;
}