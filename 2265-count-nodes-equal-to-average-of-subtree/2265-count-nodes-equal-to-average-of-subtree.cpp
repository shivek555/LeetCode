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
    pair<int, int> trav(TreeNode* root, int& count) {
        if(root == nullptr) return {0, 0};

        auto [leftSum, leftCount] = trav(root->left, count);
        auto [rightSum, rightCount] = trav(root->right, count);

        int subtreeSum = leftSum + rightSum + root->val;
        int subtreeCount = leftCount + rightCount + 1;

        if(subtreeSum / subtreeCount == root->val) count++;

        return {subtreeSum, subtreeCount};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        trav(root, count);
        return count;
    }
};