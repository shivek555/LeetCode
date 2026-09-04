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
     vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool inBlock = false;
        string curr;
        for (int i = 0, n = source.size(); i < n; ++i) {
            int j = 0, m = source[i].length();
            while (j < m) {
                if (!inBlock && j + 1 < m && source[i][j] == '/' && source[i][j + 1] == '*') {
                    inBlock = true;
                    j += 2;
                } 
                else if (inBlock && j + 1 < m && source[i][j] == '*' && source[i][j + 1] == '/') {
                    inBlock = false;
                    j += 2;
                }
                else if (!inBlock && j + 1 < m && source[i][j] == '/' && source[i][j + 1] == '/') break;
                else if (!inBlock) curr += source[i][j++];
                else ++j;
            }
            if (!inBlock && !curr.empty()) {
                res.push_back(curr);
                curr.clear();
            }
        }
        return res;
    }
};