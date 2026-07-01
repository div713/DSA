#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int nums[] = {10, 20, 30, 40, 50, 40, 30, 20};

    int n = 8;

    vector<int> lis(n,1);

    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(nums[j] < nums[i]){
                if(lis[j] + 1 > lis[i]){
                    lis[i] = lis[j]+1;
                }
            }
        }
    }

    vector<int> lds(n,1);
    for(int i=n-2;i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(nums[j] < nums[i]){
                if(lds[j] + 1 > lds[i]){
                    lds[i] = lds[j] + 1;
                }
            }
        }
    }

    int maxlen = 0;

    for(int i=0; i<n; i++){
        maxlen = max(maxlen, lis[i]+lds[i]-1);
    }

    cout<<maxlen<<endl;

    return 0;
}