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
    vector<int> prevPermOpt1(vector<int>& A) {
        int l = -1, n= A.size();
        for(int i = n-1; i>0; i--){
            if(A[i-1]>A[i]){
                l = i-1;
                break;
            }
        }
        if(l == -1)
            return A;
        int r = l+1;
        for(int i = l+1; i<n; i++){
            if(A[i]< A[l] && A[r] < A[i]) 
                r = i;
        }
        swap(A[l], A[r]);
        return A;
    }
};