// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int end= numbers.size()-1;

        vector<int> ans(2);

        while(start < end){
            if(numbers[start] + numbers[end] == target){
                ans[0]= start + 1;
                ans[1]= end + 1;
                return ans;
            }
            else if(numbers[start] + numbers[end] > target){
                end -- ;
            }
            else{
                start ++;
            }
        }
        return {};
    }
};

int main(){
    Solution sol;

    int size;
    cin>>size;
    vector<int> numbers(size);
    
    for(int i=0; i<size; i++){
        cin>> numbers[i];
    }

    int target;
    cin>>target;

    vector<int> ans = sol.twoSum(numbers,target);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}