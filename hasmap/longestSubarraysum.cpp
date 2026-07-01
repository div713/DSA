#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarray(int nums[], int n, int k){
    unordered_map<int,int> map;
	map[0] = -1;
	
	int prefixsum = 0;

	int longest = 0;
	
	for(int i=0; i<n; i++){
		prefixsum += nums[i];
		if(map.find(prefixsum-k) != map.end()){
			longest = max(longest, i-map[prefixsum-k]);
		}
		
		if(map.find(prefixsum) == map.end()){
			map[prefixsum] = i;
		}	
    }

    return longest;
}

int main(){
	int nums[] = {1,-1,5,-2,3};
	int n = 5;
	int k = 3;
	
	cout<<longestSubarray(nums,n,k)<<endl;
    return 0;
}