#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

int minOperations(std::string s1, std::string s2) {
    if (s1 == s2) return 0;

    std::queue<std::string> q;
    std::unordered_map<std::string, int> visited;

    q.push(s1);
    visited[s1] = 0;

    int n = s1.length();

    while (!q.empty()) {
        std::string curr = q.front();
        q.pop();

        int dist = visited[curr];

        // Try Operation 1: Change '0' to '1'
        for (int i = 0; i < n; ++i) {
            if (curr[i] == '0') {
                std::string next = curr;
                next[i] = '1';
                if (visited.find(next) == visited.end()) {
                    visited[next] = dist + 1;
                    if (next == s2) return dist + 1;
                    q.push(next);
                }
            }
        }

        // Try Operation 2: Change adjacent '1's to '0's
        for (int i = 0; i < n - 1; ++i) {
            if (curr[i] == '1' && curr[i + 1] == '1') {
                std::string next = curr;
                next[i] = '0';
                next[i + 1] = '0';
                if (visited.find(next) == visited.end()) {
                    visited[next] = dist + 1;
                    if (next == s2) return dist + 1;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}

int main() {
    std::string s1 = "11";
    std::string s2 = "00";
    
    int result = minOperations(s1, s2);
    std::cout << "Minimum operations: " << result << std::endl;

    return 0;
}