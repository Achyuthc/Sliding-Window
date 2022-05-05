/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.*/


class Solution {
public:
    int characterReplacement(string s, int k) {
      int freq[26];
      memset(freq,0,sizeof(freq));
      int j=0,i=0,length=0;
      int maxi=0,maxiIndex=0;
      while(j<s.size())
      {
          freq[s[j]-'A']++;
          maxi=max(maxi,freq[s[j]-'A']);
          //cout<<maxi<<" ";
          while((j-i+1>k+maxi)&&(i<j))
          {
              maxi=0;
              freq[s[i]-'A']--;
              for(int p=0; p<26;p++){
                  //cout<<freq[p]<<" ";
                    if(maxi < freq[p]){
                        maxi = freq[p];
                    }
                }
              i++;
          }
          
          length=max(length,j-i+1);
          //cout<<j-i+1<<" "<<maxi<<"\n";
          j++;
      }
       return length;
    }
   
};
