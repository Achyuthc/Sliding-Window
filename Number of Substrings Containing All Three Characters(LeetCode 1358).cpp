/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.*/


class Solution {
public:
    int numberOfSubstrings(string s) {
     int a[3]={0,0,0};
     int j=0,n=s.size(),i=0;
     int ans=0;
     while(j<s.size())
     {
         a[s[j]-'a']++;
         
        while(i<n&&a[0]>0&&a[1]>0&&a[2]>0)
         {
            ans+=n-j;
            a[s[i]-'a']--;
            i++;
         }
        j++;
     }
    return ans;
    }
};
