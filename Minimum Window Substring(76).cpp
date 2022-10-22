/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
            return "";
        
        int count=0;
        unordered_map<char,int> frequency;

        for(char c:t)
        {
            frequency[c]++;
            if(frequency[c]==1)
                count++;
        }

        int i=0,j=0;
        int length=INT_MAX,begin=0;
        while(j<s.size()){
            frequency[s[j]]--;
            if(frequency[s[j]]==0)
                count--;
            
            while(count==0)
            {
                frequency[s[i]]++;
                if(j-i+1<length)
                {
                    length=j-i+1;
                    begin=i;
                }
                if(frequency[s[i]]==1)
                    count++;
                i++;
            }
            j++;
            
        }

        return length==INT_MAX?"":s.substr(begin,length);

    }
};

// [2,2,3 1,0,5,4]
// if 0 then cnt++
// if -1 
