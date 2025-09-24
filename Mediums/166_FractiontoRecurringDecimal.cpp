class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg=false;
        long long numerator2=numerator;
        long long denominator2=denominator;
        if(numerator2*denominator2<0){
            neg=true;
        }
        if(numerator2<0){
            numerator2*=-1;
        }
        if(denominator2<0){
            denominator2*=-1;
        }
        string ans;
        unordered_map<int, int> seen_remainder;
        long long remainder = numerator2;
        if(numerator2%denominator2==0){
            ans = to_string(numerator2/denominator2);
            if(neg){
                ans.insert(0,1,'-');
            }
            return ans;
        }
        ans+=to_string(numerator2/denominator2)+".";
        remainder%=denominator2;
        remainder*=10;
        int index = ans.size();
        while(remainder!=0){
            // cout<<remainder<<" "<<index<<endl;
            while(remainder<denominator2){
                if(seen_remainder.count(remainder)==1){
                    break;
                }
                seen_remainder[remainder]=index;
                ++index;
                if(remainder<denominator2){
                    ans+="0";
                }
                remainder*=10;
            }
            if(seen_remainder.count(remainder)==1){
                break;
            }
            int quotient = remainder/denominator2;
            seen_remainder[remainder]=index;
            ++index;
            remainder = remainder%denominator2;
            ans+=to_string(quotient);
            remainder*=10;
        }
        if(remainder!=0){
            ans+=")";
            ans.insert(seen_remainder[remainder],1,'(');
        }
        if(neg){
            ans.insert(0,1,'-');
        }
        return ans;
    }
};
