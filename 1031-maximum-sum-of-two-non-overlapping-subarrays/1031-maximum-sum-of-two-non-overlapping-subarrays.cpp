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
    int maxTwoNoOverlap(vector<int>& A, int L, int M, int sz, int res = 0) {
  vector<int> left(sz + 1), right(sz + 1);
  for (int i = 0, j = sz - 1, s_r = 0, s_l = 0; i < sz; ++i, --j) {
    s_l += A[i], s_r += A[j];
    left[i + 1] = max(left[i], s_l);
    right[j] = max(right[j + 1], s_r);
    if (i + 1 >= L) s_l -= A[i + 1 - L];
    if (i + 1 >= M) s_r -= A[j + M - 1];
  }
  for (auto i = 0; i < A.size(); ++i) {
    res = max(res, left[i] + right[i]);
  }
  return res;
}
int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
  return max(maxTwoNoOverlap(A, L, M, A.size()), maxTwoNoOverlap(A, M, L, A.size()));
}
};