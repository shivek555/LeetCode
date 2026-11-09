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
    vector<int> numMovesStonesII(vector<int>& A) {
	sort(A.begin(), A.end());
	int n = A.size(), low = n;
	for (int i = 0, j = 0; j < n; ++ j) {
		while (A[j]-A[i]+1 > n) ++ i;
		int already_store = (j-i+1);
		if (already_store == n - 1 &&  A[j] - A[i] + 1 == n-1) {
			low = min(low, 2);
		} else {
			low = min(low, n - already_store);
		}
	}
	return  {low, max(A[n-1]-A[1]-n+2, A[n-2]-A[0]-n+2)};
}
};