/*You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).*/
/class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        unordered_map<int,int> index;
        vector<int>prefix;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            prefix.push_back(sum);
        }
        sum=0;
        int ans=0;
        i=0;
        int tmp;
        while(j<nums.size())
        {
            sum+=nums[j];
            if(index.find(nums[j])!=index.end())
            {
               
                i=max(i,index[nums[j]]);
            }
            index[nums[j]]=j+1;
            tmp=0;
            if(i-1>=0)
                tmp=prefix[i-1];
            
            ans=max(ans,sum-tmp);

            j++;
        }
        return ans;
        
    }
};
