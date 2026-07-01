// Hacks are disabled in this problem.

// You are given two integers 𝑛 and 𝑘.

// Your task is to construct a sequence 𝑎 consisting of 𝑘 non-negative integers 𝑎1,𝑎2,…,𝑎𝑘 such that:

// ∑𝑘𝑖=1𝑎𝑖≤𝑛
// The total number of set bits, i.e., ∑𝑘𝑖=1popcount(𝑎𝑖), is as large as possible.
// You only need to output the maximum possible value of ∑𝑘𝑖=1popcount(𝑎𝑖).

// Here, popcount(𝑥) denotes the number of 1 bits in the binary representation of 𝑥. For example, popcount(6)=popcount((110)2)=2, and popcount(0)=0.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤103). The description of the test cases follows.

// Each of the next 𝑡 lines contains two integers 𝑛 and 𝑘 (1≤𝑛,𝑘≤106) — the maximum allowed sum of the sequence and the length of the sequence, respectively.

// Output
// For each test case, output a single integer — the maximum possible value of ∑𝑘𝑖=1popcount(𝑎𝑖).

#include <iostream>
using namespace std;

int maxpop = 0;

int popcount(int num){
    int cnt = 0;

    while(num){
        int bit = (num&1);

        if(bit) cnt ++;

        num = num >> 1;
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        

        cout<<maxpop<<endl;

        maxpop = 0;
    }

    return 0;
}