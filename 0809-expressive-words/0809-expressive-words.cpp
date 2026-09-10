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
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (int i = 0, n = words.size(); i < n; ++i) {
            if (isStretchy(s, words[i])) ++res;
        }
        return res;
    }
    bool isStretchy(const string& s, const string& w) {
        int i = 0, j = 0, n = s.length(), m = w.length();
        while (i < n && j < m) {
            if (s[i] != w[j]) return false;
            int len1 = 1, len2 = 1;
            while (i + len1 < n && s[i + len1] == s[i]) ++len1;
            while (j + len2 < m && w[j + len2] == w[j]) ++len2;
            if (len1 < len2) return false;
            if (len1 != len2 && len1 < 3) return false;
            i += len1;
            j += len2;
        }
        return i == n && j == m;
    }
};