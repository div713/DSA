// Construct an array of 4⋅𝑛 integers such that:

// each number 1,2,…,𝑛 appears in the array exactly 4 times;
// let 𝑝𝑥,𝑖 be the position of the 𝑖-th occurrence of number 𝑥 in the array; then, for each 𝑥 from 1 to 𝑛, the numbers (𝑝𝑥,2−𝑝𝑥,1),(𝑝𝑥,3−𝑝𝑥,2),(𝑝𝑥,4−𝑝𝑥,3) must be pairwise distinct.
// For example, for 𝑛=3, one possible array is [1,1,2,1,2,3,1,3,2,2,3,3], because:

// 𝑝1,2−𝑝1,1=1,𝑝1,3−𝑝1,2=2,𝑝1,4−𝑝1,3=3 — all numbers are distinct;
// 𝑝2,2−𝑝2,1=2,𝑝2,3−𝑝2,2=4,𝑝2,4−𝑝2,3=1 — all numbers are distinct;
// 𝑝3,2−𝑝3,1=2,𝑝3,3−𝑝3,2=3,𝑝3,4−𝑝3,3=1 — all numbers are distinct.
// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤200). The description of the test cases follows.

// The only line of each test case contains one integer 𝑛 (2≤𝑛≤200).

// Output
// For each test case, output the required array. If there are several


