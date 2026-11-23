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
    long long modPow(long long base, long long exp, long long MOD) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int sumOfNumbers(int l, int r, int k) {
        const long long MOD = 1e9 + 7;

        long long d = r-l+1;                 // number of available digits
        long long s = (1LL * (l+r) * d) / 2;   // sum from l to r
        long long other_positions = modPow(d, k - 1, MOD);

        // now we mathematically need geosum = ((10^k - 1)/9)
        // but direct computation would cause problems due to large integers and mod with division
        long long pow10 = modPow(10, k, MOD);
        long long inv9 = modPow(9, MOD - 2, MOD);   // Fermat inverse of 9
        long long geosum = ((pow10 - 1 + MOD) % MOD * inv9) % MOD;

        return (s % MOD * other_positions % MOD * geosum) % MOD;
    }
};