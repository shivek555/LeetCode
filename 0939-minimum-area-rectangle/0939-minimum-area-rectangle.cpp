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
    int minAreaRect(vector<vector<int>>& points, int res = INT_MAX) {
  unordered_map<int, set<int>> x;
  for (auto p : points) x[p[0]].insert(p[1]);
  for (auto i = x.begin(); i != x.end(); ++i)
    for (auto j = next(i); j != x.end(); ++j) {
      if (i->second.size() < 2 || j->second.size() < 2) continue;
      vector<int> y;
      set_intersection(begin(i->second), end(i->second),
        begin(j->second), end(j->second), back_inserter(y));
      for (int k = 1; k < y.size(); ++k)
        res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
    }
  return res == INT_MAX ? 0 : res;
}
};