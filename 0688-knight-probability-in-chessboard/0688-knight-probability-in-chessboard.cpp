#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    unordered_map<int, unordered_map<int, unordered_map<int, double>>>dp;
// public:
    double knightProbability(int N, int K, int r, int c) {
        if(dp.count(r) && dp[r].count(c) && dp[r][c].count(K)) return dp[r][c][K];
        if(r < 0 || r >= N || c < 0 || c >= N) return 0;
        if(K == 0) return 1;
        double total = knightProbability(N, K - 1, r - 1, c - 2) + knightProbability(N, K - 1, r - 2, c - 1) 
                     + knightProbability(N, K - 1, r - 1, c + 2) + knightProbability(N, K - 1, r - 2, c + 1) 
                     + knightProbability(N, K - 1, r + 1, c + 2) + knightProbability(N, K - 1, r + 2, c + 1) 
                     + knightProbability(N, K - 1, r + 1, c - 2) + knightProbability(N, K - 1, r + 2, c - 1);
        double res = total / 8;
        dp[r][c][K] = res;
        return res;
    }
};