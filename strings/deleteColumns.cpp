// You are given an array of n strings strs, all of the same length.

// The strings can be arranged such that there is one on each line, making a grid.

// For example, strs = ["abc", "bce", "cae"] can be arranged as follows:
// abc
// bce
// cae
// You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

// Return the number of columns that you will delete.

#include <iostream>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int maxColumn= strs[0].size();

        int rows= strs.size();

        int ans = 0;

        for(int i=0; i<maxColumn; i++){
            char el= strs[0][i];

            for(int j=1; j<rows; j++){
                if(strs[j][i] < el){
                    ans ++;
                    break;
                }
                el = strs[j][i];
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;

    int n,m;
    cin>>n>>m;

    vector<string> strs(n);

    for(int i=0; i<n; i++){
        cin >> strs[i];
    }

    int ans = sol.minDeletionSize(strs);

    cout<< ans << endl;

    return 0;
}