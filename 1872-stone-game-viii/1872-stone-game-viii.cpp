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
    int stoneGameVIII(vector<int>& stones) {
        vector<int> dp (stones.size()-1);
        dp[0] = stones[0]+stones[1];
        for (int i=1; i<dp.size(); i++) dp[i] = dp[i-1] + stones[i+1];
        int max1 = dp[dp.size()-1];
        for (int i=dp.size()-2; i>=0; i--) max1 = max(max1,dp[i]-max1);
        return max1;
    }
};