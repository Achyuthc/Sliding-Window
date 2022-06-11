/*You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.*/

Step by Step process:

solving by recursion by taking left or right element of vector Time Complexity(2^(n/2))
solving by dp[][][] where dp[i][[j][x] is min number of operations required to get x from ith index to jth index Time Complexity ((N^2)X)
solve by sliding window Time Complexity (N) space(1)
we can see that we take only right or left elements of array , so we can say that used elements to to get X is left sum(of some elements)+right sum(of some elemensts).{X=left[i]+right[j]}
this can be calculated by maintaining prefix ,suffix sum having 2 loops for i, j respectively.
the other Approach is finding SUM-X by sliding Window
Sliding Window:

calculate sum,cursum=0,reqsum=sum-x
while loop for finding answer
add present element to cursum
remover ith element from cursum because cursum>reqsum
if cursum==reqsum ans =min(ans,lengthof array -present length) maintain ans for global min for all possible solutions
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        for(int n:nums)
            sum+=n;
        int i=0,j=0;
        long long cursum=0,reqsum=sum-x;
        int ans=INT_MAX;
        while(j<nums.size())
        {
            cursum+=nums[j];
            while(cursum>reqsum&&j>=i)
            {
                cursum-=nums[i];
                i++;
            }
            if(cursum==reqsum)
                ans=min(ans,(int)nums.size()-(j-i+1));
            j++;
        }
        return (ans==INT_MAX)?-1:ans;
        
        
    }
};
