#include <iostream>
using namespace std;

int diagonalSum(int (*mat)[3], int n){

    cout<< *(*(mat + 1) + 2)<<" "<<mat[1][2]<<" "; //accesing 1,2 using pointer

    int ans = 0;

    //0(n)
    for(int i=0; i<n; i++){
        ans += mat[i][i] + mat[i][n-i-1];
        if(i == n-i-1){
            ans -= mat[i][i];
        }
    }

    return ans;
}

int main(){
    int mat[3][3]= {{1,2,3},
                    {4,5,6},
                    {7,8,9}
                };
    
    cout<<diagonalSum(mat,3);
    return 0;
}