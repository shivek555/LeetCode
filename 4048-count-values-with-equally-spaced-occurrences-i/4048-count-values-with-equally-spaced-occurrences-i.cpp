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
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        vector<int> freq(100, 0);
        for (int c : nums) {
            freq[c - 1]++;
        }
        for (int i = 0; i < n; i++) {
            int c = nums[i];
            if (freq[c - 1] != 3) continue;
            freq[c - 1] = -1;
            for (int distance = 1; i + (distance * 2) < n; distance++) {
                if (nums[i + distance] == c && nums[i + (distance * 2)] == c) {
                    r++;
                    break;
                }
            }
        }
        return r;
    }
};
    