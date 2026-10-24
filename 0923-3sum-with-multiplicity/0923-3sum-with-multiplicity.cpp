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
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = 0; 
        int mod = 1e9+7;
        for (int i=0; i<n-2; ++i) {
            int lo = i+1, hi = n-1;
            while (lo < hi) {
                if (A[i] + A[lo] + A[hi] == target) {
                    int cntlo=1, cnthi=1;
                    while (lo < hi && A[lo] == A[lo+1]) {cntlo++; lo++;}
                    while (lo < hi && A[hi] == A[hi-1]) {cnthi++; hi--;}
					
                    if (lo == hi) ans =(ans+cntlo*(cntlo-1)/2)%mod;
					
                    else ans = (ans+cntlo*cnthi)%mod;
                    lo++; hi--; 
                } else if (A[i] + A[lo] + A[hi] > target) {
                    hi--;
                } else {
                    lo++;
                }
            }
            //cout << ans << endl;
        }
        return ans;
    }
};