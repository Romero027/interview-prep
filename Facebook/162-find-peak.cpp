class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return bsHelper(nums, 0 ,nums.size()-1);
    }
    
    
    int bsHelper(vector<int>& nums, int low, int high) {
        if( low == high ) {
            return low;
        } else {
            int midL = low + ( high - low ) / 2;
            int midR = midL + 1;
            if( nums[midL] > nums[midR] )
                return bsHelper(nums, low, midL);
            else 
                return bsHelper(nums, midR, high);
        }
    }
};
