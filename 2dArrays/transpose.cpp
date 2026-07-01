#include <iostream>
using namespace std;

vector<vector<int>> transpose(int (*mat)[3], int n, int m){
    vector<vector<int>> ans(m, vector<int> (n));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[j][i] = mat[i][j];
        }
    }

    return ans;
}

int main(){
    int mat[2][3]={{1,2,3},{4,5,6}};

    vector<vector<int>> ans = transpose(mat,2,3);


    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}