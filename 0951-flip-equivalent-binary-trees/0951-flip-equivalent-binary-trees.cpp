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
    void findCanonicalForm(TreeNode* root) {
        if (!root) return;

        findCanonicalForm(root->left);
        findCanonicalForm(root->right);

        if (!root->right) return;
        if (!root->left) {
            root->left = root->right;
            root->right = NULL;
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left->val > right->val) {
            root->left = right;
            root->right = left;
        }
    }

    bool areEquivalent(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return areEquivalent(root1->left, root2->left) &&
               areEquivalent(root1->right, root2->right);
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);
        return areEquivalent(root1, root2);
    }
};