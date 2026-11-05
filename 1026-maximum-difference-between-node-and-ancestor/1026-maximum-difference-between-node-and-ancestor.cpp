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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {INT_MAX, INT_MIN};
        auto [leftMin, leftMax]   = dfs(root -> left);
        auto [rightMin, rightMax] = dfs(root -> right);
        auto curMin = min({root -> val, leftMin, rightMin}), 
		     curMax = max({root -> val, leftMax, rightMax});        
        ans = max({ans, root -> val - curMin, curMax - root -> val});
        return {curMin, curMax};
    }
};