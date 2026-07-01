#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

class graphlist
{

public:
    unordered_map<T,list<T>> adj;

    void addEdge(T u,T v,bool direction){
        //direction=0->undirected
        //direction=1->directed

        //create an edge from u to v
        adj[u].push_back(v);

        if(direction) adj[v].push_back(u);
    }

    void printAdj(){

        for(auto i:adj){
            cout<<i.first<<"->";
            for (auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int n;
    cout<<"enter no of nodes "<<endl;
    cin>>n;

    int m;
    cout<<"enter no of edges "<<endl;

    graphlist<int> g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating undirected graph

        g.addEdge(u,v,0);

    }
    //printing
    g.printAdj();

    return 0;
}