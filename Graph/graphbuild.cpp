#include <iostream>
#include <queue>
#include<list>
#include<stack>
using namespace std;

class Graph {
public:
    
    int **matrix;
    int V;

    public:
    Graph(int V){
        this->V = V;
        matrix = new int*[V];
        for(int i = 0; i < V; i++) {
            matrix[i] = new int[V];
            for(int j = 0; j < V; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    void addEdge(int u, int v,int weight) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            matrix[u][v] = weight;
            matrix[v][u] = weight; // For undirected graph
        } else {
            std::cerr << "Error: Vertex out of bounds." << std::endl;
        }
    }   

    void display() {
        for(int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for(int j = 0; j < V; j++) {
                if (matrix[i][j] != 0)
                    cout << j << " ";
            }
            cout << endl;
        }
    }

    void bft() {
        queue<int> q;
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }
        for(int src=0; src < V; src++) {
            if (visited[src]) {
                continue;
            }
            q.push(src);
            visited[src] = true;

            while(!q.empty()) {
                int current = q.front();
                q.pop();
            
                
                cout << current << " ";

                for(int i = 0; i < V; i++) {
                    if(matrix[current][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
                     
            }
        }
        delete[] visited;
    }
    
    void dfsHelper(int u, bool *visited){
        cout << u << " ";
        visited[u] = 1;

        for(int i=0; i<V; i++){
            if(matrix[u][i] == 1 && !visited[i]){
                dfsHelper(i,visited);
            }
        }
    }

    void dfs() {
       
        // stack<int> s;
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }

        

        // for(int src=0; src < V; src++) {
        //     if (visited[src]) {
        //         continue;
        //     }

        //     s.push(src);

        //     while(!s.empty()) {
        //         int current = s.top();
        //         s.pop();

        //         if(!visited[current]) {
        //             visited[current] = true;
        //             cout << current << " ";

        //             for(int i = V - 1; i >= 0; i--) { // Reverse order for correct dfs
        //                 if(matrix[current][i] == 1 && !visited[i]) {
        //                     s.push(i);
        //                 }
        //             }
        //         }
        //     }
        // }

        for(int i=0 ; i<V; i++){
            if(!visited[i]){
                dfsHelper(i,visited);
            }
        }
        

       
        delete[] visited;
    }

    void topoS(int x,unordered_map<int,list<int>> &adj,vector<bool> &visited,stack<int> &s){
        visited[x]=1;
        
        for(auto neighbour :adj[x]){
            if(!visited[neighbour]){
                topoS(neighbour,adj,visited,s);
            }
        }
        
        s.push(x);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            
        }
        
        vector<bool> visited(V);
        stack<int> s;
        
        for(int i=0;i<V;i++){
            if(!visited[i]) topoS(i,adj,visited,s);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main() {
    Graph g(10) ;

    g.addEdge(0,1,2) ;
    g.addEdge(0,3,3) ;
    g.addEdge(1,2,4) ;
    g.addEdge(2,3,5) ;
    g.addEdge(3,4,6) ;
    g.addEdge(4,5,1) ;
    g.addEdge(5,6,10) ;
    g.addEdge(4,6,58) ;

    g.addEdge(7,8,1) ;
    g.addEdge(8,9,2) ;
    g.addEdge(7,9,3) ;

    g.display() ;
    cout<<endl;

    cout << "Depth First Traversal (starting from vertex 0): ";

    g.dfs();
    cout << endl;
    // cout << "Breadth First Traversal (starting from vertex 0): ";
    // g.bft();

    cout<<endl;
    
}