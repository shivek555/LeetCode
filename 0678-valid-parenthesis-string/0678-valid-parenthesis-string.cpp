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
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;
        
        for (int i = 0; i <= length; i++) {
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
      
        return true;
    }
};