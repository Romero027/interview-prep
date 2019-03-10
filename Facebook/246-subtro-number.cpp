class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> dict{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for( int i = 0, j = num.size() - 1; i <= j; i++, j-- ) 
            if(dict.count(num[i]) == 0 || dict[num[i]] != num[j])
                return false;
        return true;
    }
};