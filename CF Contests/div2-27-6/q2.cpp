// Milkcat2009 has a matrix 𝑎 with 𝑛 rows and 𝑚 columns consisting of integers 0 and 1. The rows are numbered from 1 to 𝑛, and the columns are numbered from 1 to 𝑚. The element in the 𝑖-th row and 𝑗-th column is denoted as 𝑎𝑖,𝑗.

// Milkcat2009's AI scans every single submatrix∗ of 𝑎 consisting of 𝑟 rows and 𝑐 columns. The AI considers the matrix clean if the bitwise XOR sum of elements in each such submatrix is equal to 0.

// Formally, the matrix 𝑎 is valid if and only if for all 1≤𝑖≤𝑛−𝑟+1 and 1≤𝑗≤𝑚−𝑐+1:
// ⨁𝑥=𝑖𝑖+𝑟−1⨁𝑦=𝑗𝑗+𝑐−1𝑎𝑥,𝑦=0

// where ⊕ denotes summation with the bitwise XOR operation.

// Your task is, given various sets of integers 𝑛,𝑚,𝑟,𝑐, to count the number of clean matrices of 𝑛 rows and 𝑚 columns with respect to scanning dimensions 𝑟 and 𝑐. Since the answer can be very large, calculate it modulo 998244353.

// ∗A submatrix of a matrix is obtained by removing some rows (from the beginning and/or end) and/or columns (from the beginning and/or end) from the original matrix.
// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤104). The description of the test cases follows.

// Each test case consists of a single line containing four integers 𝑛,𝑚,𝑟,𝑐 (1≤𝑟≤𝑛≤109, 1≤𝑐≤𝑚≤109), representing the dimensions of the matrix and the dimensions of the scanning area, respectively.

// Output
// For each test case, output a single integer representing the answer modulo 998244353.

