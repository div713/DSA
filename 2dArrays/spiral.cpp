#include <iostream>
using namespace std;

void spiralMatrix(int mat[][5],int n, int m){
    int sr= 0;
    int sc= 0;
    int er= n-1;
    int ec= m-1;

    while(sr <= er && sc <= ec){
        //top
        for(int j=sc; j<= ec; j++){
            cout<< mat[sr][j]<<" ";
        }  

        //right
        for(int i=sr+1; i<=er; i++){
            cout<<mat[i][ec]<<" ";
        }

        //bottom
        for(int j=ec-1; j>=sc; j--){
            if(sr == er) break; // already done by top in case of middle row
            cout<<mat[er][j]<<" ";
        }

        //left
        for(int i=er-1; i>=sr+1; i--){
            if(sc == ec) break; // already done by right in case of middle column
            cout<<mat[i][sc]<<" ";
        }

        sr++,sc++,er--,ec--;
    }
}

int main(){
    int mat[2][5]= {{1,2,3,4,5},
                    {6,7,8,9,10},
                };
    spiralMatrix(mat,2,5);
    return 0;
}