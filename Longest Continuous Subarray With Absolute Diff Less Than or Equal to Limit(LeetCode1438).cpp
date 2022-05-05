/*Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two 
elements of this subarray is less than or equal to limit.*/




class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int mini=nums[0],maxi=nums[0];
        int l=0,r=0,n=nums.size();
        int ans=0;
        map<int,int> mp;
        while(r<n)
        {
            mp[nums[r]]=r;
            mini=min(mini,nums[r]);
            maxi=max(maxi,nums[r]);
            
            while((abs(maxi-mini)>limit)&&l<=r)
            {
                if(mp[nums[l]]==l)
                 mp.erase(mp.find(nums[l]));
                mini=mp.begin()->first;
                maxi=mp.rbegin()->first;
                l++;
            }
            if(abs(maxi-mini)<=limit)
            ans=max(ans,r-l+1);
           //cout<<abs(maxi-mini)<<" "<<mp.begin()->first<<" "<<mp.rbegin()->first<<" "<<r-l+1<<" \n";
            r++;
        }
        return ans;
        
    }
};
//[]
