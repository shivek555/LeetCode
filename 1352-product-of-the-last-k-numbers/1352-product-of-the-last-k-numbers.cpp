class ProductOfNumbers {
    private:
    vector<int> prefixP;
    int size=0;

public:
    ProductOfNumbers() {
    prefixP.push_back(1);
    size=0;    
    }
    
    void add(int num) {
        if(num ==0) {
            prefixP={1};
            size=0;
        }else{
            prefixP.push_back(prefixP[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size) return 0;
        return prefixP[size]/prefixP[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */