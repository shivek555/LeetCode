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
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            up = nums[i - 1] < nums[i] ? up + 1 : 1; 
            down = nums[i - 1] > nums[i] ? down + 1 : 1;  
            best = max({best, up, down});
        }
        return best;
    }
};