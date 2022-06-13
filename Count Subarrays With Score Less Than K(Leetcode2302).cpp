/*The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,sum=0;
        int j=0,i=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum*((long long)j-i+1)>=k)
                sum-=nums[i++];
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};
