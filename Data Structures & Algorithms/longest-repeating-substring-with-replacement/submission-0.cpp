class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>count;
        int res = 0;
        int maxchar = 0;

        int j=0;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;

            maxchar = max(maxchar,count[s[i]]);

            while(i-j+1 - maxchar > k)
            {
                count[s[j]]--;
                j++;
            }

            res = max(res,i-j+1);
        }

        return res;
    }
};