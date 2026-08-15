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
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size() ;
        int m = discounts.size() ;

        sort( prices.rbegin() , prices.rend() ) ;
        sort( discounts.rbegin() , discounts.rend() ) ;

        double ans = 0 ;

        int i = 0 ;
        int j = 0 ;
        
        while ( i < n && j < m ) {

            ans += (double)( prices[i] * (double)(100-discounts[j]) / 100 ) ;
            i++ ;
            j++ ;
            
        }

        while ( i < n ) ans += prices[i++] ;

        return ans ;
        
    }
};