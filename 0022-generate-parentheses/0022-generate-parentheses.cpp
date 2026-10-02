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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
    void backtrack(vector<string> &res, string cur, int open,int close,int n){
        if (cur.length() == 2*n){
            res.push_back(cur);
            return;
        }
        if (open < n) backtrack(res, cur + "(", open + 1, close, n);
        if (close < open) backtrack(res, cur + ")", open, close + 1, n);
    }
};