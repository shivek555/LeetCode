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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n1 = pushed.size();
        int n2 = popped.size();
        stack<int>st;

        int i1 = 0,i2 = 0;
        while(i1<n1 && i2<n2)
        {
            if(pushed[i1]==popped[i2])
            {
                i1++;
                i2++;

                while(!st.empty() && st.top()==popped[i2])
                {
                    st.pop();
                    i2++;
                }
            }
            else st.push(pushed[i1++]);
        } 

        while(i1<n1) st.push(pushed[i1++]);
        
        while(i2<n2)
        {
            if(!st.empty() && st.top()==popped[i2]) st.pop();i2++;
        }

        return st.empty();
    }
};