#include <iostream>

using namespace std;
#include <string>

void merge(string z, string x, string y, int k, int i, int j, bool &solved){
    if(k == z.length()){
        return;  
    }
    if(i<x.length() && z[k] == x[i]){
        merge(z,x,y,k+1,i+1,j,solved);
        return;
    }
    else if(j<y.length() && z[k] == y[j]) {
        merge(z,x,y,k+1,i,j+1,solved);
        return;
    }
    else{
        solved = false;
        return;
    }
}

int main(){
    bool solved = true;

    string x= "data";
    string y= "structuresalgo";

    string z= "stdaructturesaalg  o";

    merge(z,x,y,0,0,0,solved);

    cout<<solved<<endl;


}