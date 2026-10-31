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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>ans;
        vector<int>pre;

        unordered_map<int,int>mp;
        for(int i = 0 ; i < voyage.size() - 1; i++)  
            mp[voyage[i]] = voyage[i+1];

        bool possible = true;
        auto dfs = [&](auto &self , TreeNode* root) -> void{
            if(root == NULL)
                return ;
            
            pre.push_back(root->val);

            if(root -> left){
                if(mp[root->val] != root->left->val){
                    ans.push_back(root->val);
                    if(!root -> right)
                        possible = false;
                    swap(root -> left , root -> right);
                }

                self(self , root->left);
            }
            if(root -> right)   
                self(self, root->right);
        };

        dfs(dfs, root);

        if(!possible)
            return {-1};
        
        for(int i = 0 ; i < pre.size() ;i++){
            if(pre[i] != voyage[i])
                return {-1};
        }

        return ans;
    }
};