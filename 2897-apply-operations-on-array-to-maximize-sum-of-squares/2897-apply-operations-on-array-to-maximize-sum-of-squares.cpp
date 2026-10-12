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
    int maxSum(vector<int>& nums, int k) {
        int freq[31] ;
        for (int x : nums) {
            for (int i = 0; i <= 30; i++) {
                if (((x >> i) & 1) == 1) {
                    freq[i]++;
                }
            }
        }
        long ans = 0;
        int MOD = (int) 1e9+7;

        for (int t = 0; t < k; t++) {
            int val = 0;
            for (int i = 30; i >= 0; i--) {
                if (freq[i] > 0) {
                    val |= (1 << i);
                    freq[i]--;
                }
            }
            ans = (ans + (long) val * val) % MOD;
        }

        return (int) ans;

    }
};