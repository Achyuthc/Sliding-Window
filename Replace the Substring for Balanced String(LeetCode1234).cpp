/*You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.*/


class Solution {
public:
    int balancedString(string s) {
        int j=0,i=0,n=s.size(),ans=n;
        unordered_map<char,int>mp;
        for(char c:s)
            mp[c]++;
        while(j<n)
        {
            mp[s[j]]--;
           // cout<<j<<" ";
            while((mp[s[i]]<(n/4))&&i<=j)
            {
                mp[s[i]]++;
                i++;
            }
            if((mp['Q']<=n/4)&&(mp['W']<=n/4)&&(mp['E']<=n/4)&&(mp['R']<=n/4))
            {
                    ans=min(ans,n-mp['Q']-mp['W']-mp['E']-mp['R']);
            }
            j++;
        }
        return ans;
        
        
    }
};
