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
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> seen;

        for (string S : A) {
            int count[52] = {0};

            for (int i = 0; i < S.length(); ++i) {
                count[S[i] - 'a' + 26 * (i % 2)]++;
            }

            string key;
            for (int i = 0; i < 52; ++i) {
                key += to_string(count[i]) + ",";
            }

            seen.insert(key);
        }

        return seen.size();
    }
};