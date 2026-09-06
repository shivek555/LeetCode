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
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }
        vector<int> sum(maxVal + 1, 0);
        for (int num : nums) {
            sum[num] += num;
        }

      
        vector<int> dp(maxVal + 1, 0);
        dp[0] = sum[0];
        dp[1] = max(sum[0], sum[1]);

        for (int i = 2; i <= maxVal; i++) {
            int pick = sum[i] + dp[i - 2];
            int npick = dp[i - 1];
            dp[i] = max(pick, npick);
        }

        return dp[maxVal];
    }
};
 
