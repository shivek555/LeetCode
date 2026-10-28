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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
  sort(begin(deck), end(deck));
  list<int> l(deck.size());
  iota(begin(l), end(l), 0);    
  vector<int> res(deck.size());
  auto lp = l.begin();
  for (int i = 0, skip = 0; !l.empty(); skip = !skip) {
      if (lp == l.end()) lp = l.begin();
      if (skip) ++lp;
      else {
          res[*lp] = deck[i++];
          l.erase(lp++);
      }
  }
  return res;
}
};