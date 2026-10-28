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
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<bitset<1024>> dp(n);  
        dp[0][0] = 1;
        for (auto& row : grid)
            for (int j = 0; j < n; j++) {
                auto reach = j ? dp[j] | dp[j - 1] : dp[j];  
                dp[j].reset();
                for (int x = 0; x < 1024; x++)
                    if (reach[x]) dp[j][x ^ row[j]] = 1;
            }
        int x = 0;
        while (!dp[n - 1][x]) x++;
        return x;
    }
};