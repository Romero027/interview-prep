class Solution {
     // when find a number i, flip the number at position i-1 to negative. 
    // if the number at position i-1 is already negative, i is the number that occurs twice.
public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i])-1;
            if (nums[index] < 0)
                res.push_back(abs(index+1));
            nums[index] = -nums[index];
        }
        return res;
    }
    
};