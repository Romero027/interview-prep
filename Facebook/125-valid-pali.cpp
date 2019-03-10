class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        for(int i=0, j = s.length()-1;i<=j;i++, j--){
            while((!isalnum(s[i]))&&i<j) i++;
            while((!isalnum(s[j]))&&i<j) j--;
            if(i<j&&tolower(s[i])!=tolower(s[j])) return false;
        }
        return true;
    }
};