/*
Find out the longest length of subarrays with at most 2 different numbers?
Runtime: linear time and constant space
*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> count;
        int res = 0, d = 0;
        for( int i = 0; i < tree.size(); i++ ) {
            count[tree[i]]++;
            if( count.size() > 2 ) {
                count[tree[d]]--;
                if( count[tree[d]] == 0 ) count.erase(tree[d]);
                d++;
            }
            res = max(res, i - d + 1);
        }
        return res;
    } 
};

