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
    
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        sort(nums.begin(), nums.end());
        map<int, int> DP;

        for (int i = 0; i < n; i++) {
            int a = 1, b = 1;

            if (DP.find(nums[i] - 1) != DP.end()) {
                a = DP[nums[i] - 1] + 1;
            }
            
            if (DP.find(nums[i]) != DP.end()) {
                b = DP[nums[i]] + 1;
            }
            
            if (DP.find(nums[i]) == DP.end()) DP[nums[i]] = a; else DP[nums[i]] = max(DP[nums[i]], a);
            if (DP.find(nums[i] + 1) == DP.end()) DP[nums[i] + 1] = b; else DP[nums[i] + 1] = max(DP[nums[i] + 1], b);
            
            ans = max(max(DP[nums[i]], DP[nums[i] + 1]), ans);
        }
        
        return ans;
    }
};