/*You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost.
If there is no substring from s that can be changed to its corresponding substring from t, return 0.*/


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=t.size();
        int length=0,presentCost=0,i=0,j=0;
        while(j<n)
        {
            presentCost+=abs(s[j]-t[j]);
            while(presentCost>maxCost&&i<j)
            {
                presentCost-=abs(s[i]-t[i]);
                i++;
            }
            if(presentCost<=maxCost)
            length=max(length,j-i+1);
            j++;
        }
        return length;
    }
};
