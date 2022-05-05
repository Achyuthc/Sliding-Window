/*Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/


class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        long long sum=0;
        int mn=INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=k&&i<n)
            {
                mn=min(mn,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(mn!=INT_MAX)
        return mn;
        return 0;
    }
};
