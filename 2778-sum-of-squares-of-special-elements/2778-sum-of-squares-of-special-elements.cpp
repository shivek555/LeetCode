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
    int sumOfSquares(vector<int>& nums) {
         int n = nums.size();
        int ans = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];

                int div = n / i;
                if (div != i) {
                    ans += nums[div - 1] * nums[div - 1];
                }
            }
        }

        return ans;
    }
};