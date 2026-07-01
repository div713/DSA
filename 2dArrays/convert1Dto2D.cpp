#include <iostream>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size() != m*n){
            return ans;
        }

        int k = 0;

        for(int i=0;i<m; i++){
            vector<int> mini;
            for(int j=0; j<n; j++){
                mini.push_back(original[k]);
                k++;
            }
            ans.push_back(mini);
        }

        return ans;
    }

int main(){
    vector<int> org = {1,2,3,4,5,6,7,8,9,10,11,12};

    vector<vector<int>> matrix = construct2DArray(org, 4,3);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}