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
    bool isValid(string s) {
        stack<char> st;
        int depth = 0;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()==char(s[i]-1)){
                depth++;
                st.pop();
            }
            if((depth<=1 && s[i]=='c')|| s[i]!='c')
            st.push(s[i]);
            if((depth<=1 && s[i]=='c')) return false;
            if(depth==2 && s[i]=='c') depth-=2;
        }
        return st.empty();
    }
};