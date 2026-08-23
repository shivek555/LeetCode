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
    bool sumGame(string num) {
        int n = num.size();

        auto get = [](string&& s) -> pair<int, int> {
            int nn = 0, qq = 0;
            for (char ch : s) {
                if (ch == '?') {
                    ++qq;
                } else {
                    nn += (ch - '0');
                }
            }
            return {nn, qq};
        };

        auto [n0, q0] = get(num.substr(0, n / 2));
        auto [n1, q1] = get(num.substr(n / 2, n / 2));

        return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
    }
};