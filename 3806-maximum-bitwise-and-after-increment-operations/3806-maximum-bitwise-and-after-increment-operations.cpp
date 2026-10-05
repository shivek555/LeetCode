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
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> ops(n); 
        int ans = 0;

        int max_width = bit_width((uint32_t) ranges::max(nums) + k / m);
        for (int bit = max_width - 1; bit >= 0; bit--) {
            int target = ans | (1 << bit); 
            for (int i = 0; i < n; i++) {
                int x = nums[i];
                int j = bit_width((uint32_t) target & ~x);
                int mask = (1u << j) - 1;
                ops[i] = (target & mask) - (x & mask);
            }

            ranges::nth_element(ops, ops.begin() + m);
            if (reduce(ops.begin(), ops.begin() + m, 0LL) <= k) {
                ans = target; 
            }
        }
        return ans;
    }
};