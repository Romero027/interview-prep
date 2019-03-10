class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if( n <= 0 ) return {};
        
        
        //For length of 1
        vector<string> res1 = {"0", "1", "8"};
        if( n == 1 ) return res1;
        vector<string> res = {""};
        if( n & 1 ) res = res1;
        for(int len = res[0].size(); len < n; len += 2 ) {
            vector<string> tmp;
            for( auto str : res ) {
                if(len + 2 < n){ string s0 = '0' + str + '0'; tmp.push_back(s0);}
                string s1 = '1' + str + '1'; tmp.push_back(s1);
                string s2 = '6' + str + '9'; tmp.push_back(s2);
                string s3 = '8' + str + '8'; tmp.push_back(s3);
                string s4 = '9' + str + '6'; tmp.push_back(s4);
            }
            res = tmp;
        }
        return res;
    }
};