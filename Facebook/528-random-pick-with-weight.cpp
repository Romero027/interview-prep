/*
w = [4,1,2]
lets create a sum_vector (vector s; in above code) = [4,5,7] where s[i] = sum of original vector till ith index.

Now imagine a number line between 0 to 7. PLEASE note the difference between two adjacent elements in vector s represent the share on a number line that the original element in vector w should have. if you request a random number between 0 to 7, you may get numbers in 3 buckets .

1between [0 to 4] (0,4 including)
2between (4 to 5 ]
3between (5,7]
*/
class Solution {
public:
    vector<int> s;
    Solution(vector<int> w) {
        for (int i : w) {
             s.push_back(s.empty() ? i : (i + s.back()));
            cout<< i << " " << s.back() << endl;
        }
       
        
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        auto it = upper_bound(s.begin(), s.end(), r);
        return it - s.begin();
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */