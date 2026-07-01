// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        int idealSum= (n*(n+1))/2;

        int a ;
        int b;

        int temp;
        int sum = nums[0];

        for(int i=1; i<n; i++){
            sum += nums[i];
            temp = nums[i-1] ^ nums[i];
            if(!temp){
                a = nums[i];
            }
        }

        b= idealSum - (sum - a);

        return {a,b};
    }
};

int main(){
    int n;
    cin>>n;

    Solution sol;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<int> ans = sol.findErrorNums(nums);

    for(int i=0; i<2; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}