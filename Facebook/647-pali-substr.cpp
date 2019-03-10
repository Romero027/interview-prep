//Runtime:N^2 worse case, N best case 
//Similar to 5


class Solution {
public:
    int countSubstrings(string s) {
        if( s.size() <= 1 ) return 1;
        int count = s.size();
        for( int i = 0; i < s.size(); ++i ) {
            int j = i, k = i;
            //Skip duplicates
            while( k < s.size() - 1 && s[k+1] == s[k] ) {
                k++;
                count++;
            }
            //Try to expand the substring
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
                k++;
                j--;
                count++;
            }
        }
        return count;
    }
};