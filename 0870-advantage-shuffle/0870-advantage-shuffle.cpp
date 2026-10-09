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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if(n < 2 ) return nums1;
    
        sort(nums1.begin(), nums1.end());
        vector<pair<int,int>> C;
        for(int i=0; i<n; ++i)
            C.push_back( make_pair(nums2[i], i));    
        sort(C.begin(), C.end());
       
        int l = 0, r = n-1;
        vector<int> D(n); 
        for(int i = n-1; i >=0; i--){
           if(nums1[r]<=C[i].first)
                D[C[i].second] = nums1[l++];
            else
                D[C[i].second] = nums1[r--];       
        }   
        return D;
    }
};