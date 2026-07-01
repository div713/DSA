#include <iostream>
using namespace std;

void countingSort(vector<int> &arr){
    vector<int> freq(arr.size(),0);

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i : arr){
        mini = min(mini, i);
        maxi = max(maxi, i);
    }

    for(int i : arr){
        freq[i] ++;
    }

    int idx = 0;
    for(int i = mini; i <= maxi ;i++){
        while(freq[i]){
            arr[idx++] = i;
            freq[i]--;
        }
    }
}

int main(){
    vector<int> arr = {1,4,1,3,2,4,3,7,6};

    cout<<"Before Sorting"<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    countingSort(arr);

    cout<<"After Sorting"<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}