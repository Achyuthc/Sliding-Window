/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     
       int i=0;
       int sum=0,ans=0;
       unordered_map<int,int>mp;
       mp[0]=1;
       while(i<nums.size())
       {
           sum+=nums[i];
           if(mp[sum-goal])
               ans+=mp[sum-goal];
           mp[sum]++;
           i++;
       }
       return ans;
    }
};
