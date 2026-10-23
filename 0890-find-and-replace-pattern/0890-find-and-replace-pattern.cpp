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
    bool isValid(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';

            if (freq1[a] != 0 && freq1[a] != b + 1)
                return false;

            if (freq2[b] != 0 && freq2[b] != a + 1)
                return false;

            freq1[a] = b + 1;
            freq2[b] = a + 1;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        for (int i = 0; i < words.size(); i++) {
            if (isValid(words[i], pattern)) {
                res.push_back(words[i]);
            }
        }

        return res;
    }
};