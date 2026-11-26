class Disjoint{
  public:
    vector<int> parent;
    Disjoint(int n){
        parent.resize(n+1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int ult_p(int x){
        if(parent[x]==x) return x;
        return parent[x]=ult_p(parent[x]);
    }

    void unionbysize(int u,int v){
        int UP=ult_p(u);
        int VP=ult_p(v);
        if(UP==VP) return;

        if(UP<VP)
            parent[VP]=UP;
        else
            parent[UP]=VP;
    }  
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjoint d(26);

        for(int i=0;i<s1.size();i++){
            d.unionbysize(s1[i]-'a',s2[i]-'a');
        }

        for(auto& ch:baseStr){
            ch=char(d.ult_p(ch-'a')+'a');
        }

        return baseStr;
    }
};