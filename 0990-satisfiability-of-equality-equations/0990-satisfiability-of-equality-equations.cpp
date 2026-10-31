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
   int uf_find(vector<int> &uf, int i) {
  return uf[i] == -1 || uf[i] == i ? i : uf_find(uf, uf[i]);
}
bool equationsPossible(vector<string>& equations) {
  vector<int> uf('z' + 1, -1);
  for (auto s : equations)
    if (s[1] == '=') uf[uf_find(uf, s[0])] = uf_find(uf, s[3]);
  for (auto s : equations)
    if (s[1] == '!' && uf_find(uf, s[0]) == uf_find(uf, s[3])) return false;
  return true;
}
};