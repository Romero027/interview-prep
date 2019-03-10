//Use HashMap to store a remainder and its associated index while 
//doing the division so that whenever a same remainder comes up, we know there is a repeating fractional part.


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0 ) return "0";
        
        string res = "";
        res += (numerator > 0) ^ (denominator > 0) ? "-" : "";
        long num =labs(numerator);
        long den = labs(denominator);
        
        res += to_string(num/den);
        num %= den;
        
        if(num == 0)
            return res;
        res += ".";
        unordered_map<long,int> m;
        m[num] = res.size();
        while(num != 0){
            num*=10;
            res += to_string(num/den);
            num %= den;
            if(m.count(num)){
                int index = m[num];
                res.insert(index, "(");
                res.append(")");
                break;
            }else{
                m[num] = res.size();
            }
        }
        return res;
    }
};