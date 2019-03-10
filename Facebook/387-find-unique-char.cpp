class Solution {
public:
    int firstUniqChar(string s) {
       vector<int> vec(128,0);
        for(int i=0;i<s.length();i++){
            vec[s[i]]++;
        }
        for(int i=0;i < s.length();i++){
            if(vec[s[i]]==1) return i;
        }
        return -1;
    }
};