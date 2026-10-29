#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[256 * 1024 * 1024];
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
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        int globalMax = 1;

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i+1] > nums[i]) {
                dp[i][1][0] = max(dp[i][1][0], 1 + dp[i+1][0][0]); 
                dp[i][1][1] = max(dp[i][1][1], 1 + dp[i+1][0][1]);
            }
            if (i + 2 < n && nums[i+2] > nums[i]) {
                dp[i][1][0] = max(dp[i][1][0], 1 + dp[i+2][0][1]); 
            }

            if (nums[i+1] < nums[i]) {
                dp[i][0][0] = max(dp[i][0][0], 1 + dp[i+1][1][0]);
                dp[i][0][1] = max(dp[i][0][1], 1 + dp[i+1][1][1]);
            }
            if (i + 2 < n && nums[i+2] < nums[i]) {
                dp[i][0][0] = max(dp[i][0][0], 1 + dp[i+2][1][1]);
            }
            
            globalMax = max({globalMax, 1 + dp[i][0][0], 1 + dp[i][1][0]});
        }
        return globalMax;
    }
};