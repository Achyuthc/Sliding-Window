/*You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> mp;
    int j=0,i=0;
    vector<int> ans;
    while(j<A.size())
    {
        mp[A[j]]++;
        if(j>=B-1)
        {
            ans.push_back(mp.size());
            mp[A[i]]--;
            if(mp[A[i]]==0)
                mp.erase(A[i]);
            i++;
        }
        j++;
    }
    return ans;
}
