/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.*/


class Solution {
public:
    int atmost(vector<int> &nums,int k)
    {
        int i=0,j=0,n=nums.size();
        int numberOfOdd=0;
        int ans=0;
        while(j<n)
        {
            if(nums[j]&1)
                numberOfOdd++;
            while(numberOfOdd>k&&i<=j)
            {
                if(nums[i]&1)
                numberOfOdd--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
      return atmost(nums,k)-atmost(nums,k-1);  
    }
};
