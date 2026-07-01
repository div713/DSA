#include <iostream>
using namespace std;

pair<int,int> searchMatrix(int mat[][4], int n, int m , int key){
    int cr=n-1;
    int cc=0;

    int ansr = -1;
    int ansc = -1;

    while(cr >= 0 && cc <= m-1){
        if(mat[cr][cc] == key){
            ansr = cr;
            ansc = cc;
            break;
        }
        
        if(mat[cr][cc] < key){
            cc++;
        }
        else{
            cr --;
        }
    }

    return {ansr,ansc};
}

int main(){
    int mat[4][4]={{10,20,30,40},
                {15,25,35,45},
                {27,29,37,48},
                {32,33,39,50}};
    
    pair<int,int> p = searchMatrix(mat,4,4,45);

    cout<<p.first<<" "<<p.second<<endl;


}