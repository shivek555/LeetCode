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
    int numberOfSets(int n, int k) {
    long long p = 1000000007;
    int limit = k << 1;
    int upper = n + k - 1;

    if (limit > upper) return 0;

    long long accum = 1;
    for (int step = 1; step <= limit; ++step) {
        accum = (accum * (upper - step + 1)) % p;

        long long inv = 1, base = step, power = p - 2;
        while (power) {
            if (power & 1) inv = (inv * base) % p;
            base = (base * base) % p;
            power >>= 1;
        }

        accum = (accum * inv) % p;
    }

    return accum;
}
};