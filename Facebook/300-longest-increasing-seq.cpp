class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Base case
        if(nums.size() <= 1)
            return nums.size();
        
		// This will be our array to track longest sequence length
        vector<int> T(nums.size(), 1);


		// Mark one pointer at i. For each i, start from j=0.
		for(int i=1; i < nums.size(); i++)
		{
			for(int j=0; j < i; j++)
			{
				// It means next number contributes to increasing sequence.
				if(nums[j] < nums[i])
				{
					// But increase the value only if it results in a larger value of the sequence than T[i]
					// It is possible that T[i] already has larger value from some previous j'th iteration
					if(T[j] + 1 > T[i])
					{
						T[i] = T[j] + 1;
					}
				}
			}
		}

		// Find the maximum length from the array that we just generated 
		int longest = 0;
		for(int i=0; i < T.size(); i++)
			longest = max(longest, T[i]);

		return longest;
        
    }
};


https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation