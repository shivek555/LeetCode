class CBTInserter {
public:
    TreeNode* root;
    vector<TreeNode*>nodes;
    int size;
    CBTInserter(TreeNode* root) {
        this->root=root;
        fill(root);
        this->size=nodes.size();
    }

    void fill(TreeNode* root){
        if(!root)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                nodes.push_back(temp);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
    }
    
    int insert(int val) {
        size++;
        TreeNode* parent= nodes[(size-2)/2];
        int res=parent->val;
        if(!parent->left){
            parent->left=new TreeNode(val);
            nodes.push_back(parent->left);
        }
        else if(parent->right==NULL){
            parent->right=new TreeNode(val);
            nodes.push_back(parent->right);
        }
        return res;
        
    }
    
    TreeNode* get_root() {
        return root;   
    }
};
