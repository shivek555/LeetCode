#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void* operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void*>(&BUFFER[pos - size]);
}

void* operator new[](const size_t size) { return operator new(size); }
void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*, size_t) noexcept {}

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool check(string& a, string& b) {
        int i = 0;
        for (char& c : b)
            if (isupper(c) && a[i] != c)
                return false;
            else if (c == a[i])
                i++;
        return i == a.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (string& q : queries)
            result.push_back(check(pattern, q));
        return result;
    }
};