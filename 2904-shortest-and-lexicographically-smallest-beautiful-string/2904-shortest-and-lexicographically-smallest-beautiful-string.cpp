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
int bit_width(__uint128_t x) {
    uint64_t hi = x >> 64;
    return hi ? 128 - countl_zero(hi) : 64 - countl_zero((uint64_t)x);
}
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), start = n;
        __uint128_t curr = 0, best = -1;

        for (int i = 0; i < n; i++) {
            curr = (curr << 1) | (s[i] & 1);
            k -= s[i] & 1;
            if (k < 0)
                k = 0, curr &= ((__uint128_t)1 << (bit_width(curr) - 1)) - 1;
            if (k == 0 && curr < best)
                start = i - bit_width(curr) + 1, best = curr;
        }

        return move(s).substr(start, bit_width(best));
    }
};