struct points{
    int l, r;
    struct Hash {
        std::size_t operator()(const points& k) const {
            return std::hash<int>()(k.l) ^ std::hash<int>()(k.r);
        }
    };
 
    // 必须提供一个等价比较函数
    struct KeyEqual {
        bool operator()(const points& lhs, const points& rhs) const {
            return lhs.l==rhs.l && lhs.r==rhs.r;
        }
    };
};

class NumArray {
    vector<int> &arr;
    unordered_map<points, int, points::Hash, points::KeyEqual> mymap;
public:
    NumArray(vector<int>& nums) : arr(nums){

    }
    
    void update(int index, int val) {
        for(auto &v: mymap){
            if(v.first.l <= index && v.first.r >= index){
                v.second -= arr[index];
                v.second += val;
            }
        }
        
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        points s;
        s.l = left, s.r = right;
        if(mymap.count(s) > 0) return mymap[s];
        int res =  accumulate(arr.begin()+left, arr.begin()+right+1, 0);
        mymap[s] = res;
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */