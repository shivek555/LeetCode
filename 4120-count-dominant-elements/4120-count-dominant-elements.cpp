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
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0, neighbors = 0;
            if (i > 0) {
                sum += nums[i - 1];
                neighbors++;
            }
            if (i < n - 1) {
                sum += nums[i + 1];
                neighbors++;
            }
            if (nums[i] * neighbors >= sum) {
                count++;
            }
        }
        return count;
    }
};