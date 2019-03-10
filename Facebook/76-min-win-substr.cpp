class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int begin = 0, end = 0, head, d = INT_MAX, counter = t.length();
        for(auto i : t) ++map[i];
        while(end<s.length()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d){
                    d = end-begin;
                    head = begin;
                }
                if(map[s[begin++]]++==0)  counter++;//make it invalid
            }
        }
        return d==INT_MAX?"":s.substr(head, d);
    }
};