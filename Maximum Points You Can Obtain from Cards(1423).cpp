/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int j,n,i,ans=0,rightSum=0,leftSum=0;
        n=cardPoints.size();
        for(j=n-1;j>=n-k;j--)
        {
            rightSum+=cardPoints[j];
        }
        j++;
        //cout<<j<<" "<<n-k<<" ";
        ans=rightSum;
        for(i=0;i<k;i++)
        {
            leftSum+=cardPoints[i];
            rightSum-=cardPoints[j];
            if(ans<leftSum+rightSum)
                ans=leftSum+rightSum;
            j++;
        }
        
        return ans;
        
    }
};
