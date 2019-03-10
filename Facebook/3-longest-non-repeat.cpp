class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128, 0);
        int d = -INT_MAX, begin = 0, end = 0, counter = 0;
        while(end<s.size()){
            if(map[s[end++]]++>0) counter++;
            while(counter>0){
                if(map[s[begin++]]-- > 1){
                    counter--;
                }
            }
            d = max(d, end-begin);
        }
        
        return d==-INT_MAX?0:d;
    }
};
