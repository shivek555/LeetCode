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
    int distinctSubseqII(string s) {
        int n = s.length(), mod = 1e9 + 7;
        long last[26] = {};
        long total =0;

        for(auto c: s){
            int idx = c-'a';
            long newt= (total+1)%mod;
            long add =(newt-last[idx]+mod)%mod;
            total = (total+add)%mod;
            last[idx]= newt;
        }
        return (int) total;
    }
};