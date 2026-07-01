#include <iostream>
#include <vector>
using namespace std;

/* The class implements a disjoint set data structure with path compression and union by rank
optimization. */
class disjointSet{
    public:
    int n;
    vector<int> par;
    vector<int> rank;

    disjointSet(int n){
        this->n = n;

        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

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

    void getinfo(){
        for(int i=0; i<n; i++){
            cout<<i<<": "<<par[i]<<", "<<rank[i]<<endl;
        }
    }
};

int main(){
    disjointSet dj(6);

    dj.unionByRank(0,2);
    cout<<dj.find(2)<<endl;

    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);

    cout<<dj.find(2)<<endl;
    cout<<dj.find(3)<<endl;

    dj.unionByRank(0,4);

    dj.getinfo();

    return 0;
}