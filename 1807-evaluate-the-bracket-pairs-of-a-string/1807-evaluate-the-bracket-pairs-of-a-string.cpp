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
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& kd : knowledge) {
            dict[kd[0]] = kd[1];
        }
        bool addKey = false;
        string key, res;
        for (char c : s) {
            if (c == '(') {
                addKey = true;
            } else if (c == ')') {
                if (dict.count(key) > 0) {
                    res += dict[key];
                } else {
                    res.push_back('?');
                }
                addKey = false;
                key.clear();
            } else if (addKey) {
                key.push_back(c);
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};