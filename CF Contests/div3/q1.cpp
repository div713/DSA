#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
        }

        cout<<maxi-mini+1<<endl;
    }
    return 0;
}