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
    const long long MOD = 1000000007LL;
    int countStableSubsequences(vector<int>& v) {
        long long e1 = 0, e2 = 0, o1 = 0, o2 = 0;
        for (int x : v) 
        {
            if ((x & 1) == 0) 
            { 
                long long ne1 = (e1 + (o1 + o2 + 1)) % MOD;
                long long ne2 = (e2 + e1) % MOD;
                e1 = ne1; e2 = ne2;
            } 
            else 
            {
                long long no1 = (o1 + (e1 + e2 + 1)) % MOD;
                long long no2 = (o2 + o1) % MOD;
                o1 = no1; o2 = no2;
            }
        }
        long long ans = (e1 + e2 + o1 + o2) % MOD;
        return (int)ans;
    }
};