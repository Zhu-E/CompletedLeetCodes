class Solution {
public:
    string getPermutation(int n, int k) {
        set<int> s;
        for(int i = 1; i <= n; ++i){
            s.insert(i);
        }
        int permutations=1;
        for(int i = 1; i < n; ++i){
            permutations*=i;
        }
        int permMult = n-1;
        string ans = "";
        for(int i = 0; i < n; ++i){
            cout<<permutations<<" "<<k<<endl;
            int index = (k-1)/permutations;
            k = k-permutations*((k-1)/permutations);
            auto it = s.begin();
            advance(it, index);
            ans+=to_string(*it);
            s.erase(*it);
            if(permMult!=0){
                permutations/=permMult;
            }
            --permMult;
        }
        return ans;
    }
};
