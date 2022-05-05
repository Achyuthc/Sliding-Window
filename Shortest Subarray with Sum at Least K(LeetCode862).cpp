/*Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 */


class Solution {
public:
    int shortestSubarray(vector<int>& v, int k) {
        int ans=INT_MAX;
        int i=0,n=v.size();
        vector<long> nums;
        for(int i=0;i<n;i++)
            nums.push_back(v[i]);
        deque<int> dq;
        while(i<n)
        {
            if(i>0)
                nums[i]+=nums[i-1];
            if(nums[i]>=k)
                ans=min(ans,i+1);
            while(dq.size()>0&&nums[i]-nums[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            while(dq.size()>0&&nums[i]<=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            
           i++;
        }
        if(ans!=INT_MAX)
        return ans;
        return -1;
    }
};
