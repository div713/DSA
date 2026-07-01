#include <iostream>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n= matrix.size();

    for(int i=0; i<n; i++){
        for(int j=i; j<n ; j++){
            if(i==j) continue;
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    vector<vector<int>> matrix= {{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    rotate(matrix);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}