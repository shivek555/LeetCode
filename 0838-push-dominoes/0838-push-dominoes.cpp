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
    string pushDominoes(string s) {
        s = 'L' + s + 'R';
        string res;

        int prev = 0;
        for (int curr = 1; curr < s.size(); ++curr) {
            if (s[curr] == '.') {
                continue;
            }

            int span = curr - prev - 1;
            if (prev > 0) 
                res += s[prev];

            if (s[prev] == s[curr]) {
                res += string(span, s[prev]);
            }
            else if (s[prev] == 'L' && s[curr] == 'R') {
                res += string(span, '.');
            }
            else { 
                res += string(span / 2, 'R')
                     + string(span % 2, '.')
                     + string(span / 2, 'L');
            }
            prev = curr;
        }
        return res;
    }
};