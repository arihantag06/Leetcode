class Solution {
public:
    vector<int> getLps(string pat){
    int m = pat.size();

    // Vector to store the LPS array.
    vector<int>lps(m);

    /*
    Prev is the last longest proper prefix
    which is also a suffix
    */
    int prev = 0;
    int ind = 1;
    while (ind < m){
 
        // If both are equal
        if (pat[ind]==pat[prev]){
            prev++;
            lps[ind]=prev;
            ind++;
        }
 
        /*
        If the current elements are unequal
        And LPS is 0
        */
        else if (prev==0){
            lps[ind]=0;
            ind++;
        }
 
        /*
        If the current elements are unequal
        But LPS is not 0
        */
        else{
            prev = lps[prev-1];
        }
    }
    return lps;
}
 
/*
Function to find
All occurrences of the pattern in the string
*/
    vector<int> solve(string str, string pat){
        if(!pat.size()) return vector<int>();
        vector<int> lps = getLps(pat);
        vector<int> ans;
        // Initializing variables
        int n = str.size();
        int m = pat.size();
        int patIdx = 0;
        int strIdx = 0;
     
        while (strIdx < n){
     
            // If both the elements match
            if (str[strIdx] == pat[patIdx]){
                patIdx++;
                strIdx++;
            }
            if (patIdx == m){
     
                /*
                This means that the entire pattern has matched
                Printing all occurrences of the pattern in the string
                */
                ans.push_back(strIdx - m);
     
                // Updating patIdx to the last element matched.
                patIdx = lps[patIdx-1];
            }
            else if (strIdx < n){
                if (str[strIdx]!=pat[patIdx]){
                    if (patIdx != 0)
     
                        // Updating lps to the last element matched
                        patIdx = lps[patIdx-1];
                    else
     
                        // If no element matched, we move to next index
                        strIdx++;
                }
            }
        }
        return ans;
    }
    int shortestMatchingSubstring(string s, string p)
{
    string p1, p2, p3;
    {
        int i = 0;
        while (p[i] != '*')
        {
            p1 += p[i];
            i++;
        }
        i++;
        while (p[i] != '*')
        {
            p2 += p[i];
            i++;
        }
        i++;
        while (i < p.size())
        {
            p3 += p[i];
            i++;
        }
    }

    vector<int> v1 = solve(s, p1);
    vector<int> v2 = solve(s, p2);
    vector<int> v3 = solve(s, p3);
    assert(is_sorted(v1.begin(), v1.end()));
    assert(is_sorted(v2.begin(), v2.end()));
    assert(is_sorted(v3.begin(), v3.end()));

    if (p1.size() == 0 && p3.size() == 0)
    {
        if (p2.size() == 0)
            return 0;
        else if (v2.size() != 0)
            return p2.size();
        else
            return -1;
    }

    if (p2.size() == 0)
    {
        for (int i = 0; i <= s.size(); i++)
        {
            v2.push_back(i);
        }
    }

    int ans = INT_MAX;

    for (auto x : v2)
    {
        int sum = p2.size();
        if (p1.size())
        {
            auto it = upper_bound(v1.begin(), v1.end(), x - (int)p1.size());
            if (it == v1.begin())
            {
                continue;
            }
            it--;
            sum += x - *it;
        }
        if (p3.size())
        {
            auto it = lower_bound(v3.begin(), v3.end(), x + (int)p2.size());
            if (it == v3.end())
                continue;
            sum += *it - x - p2.size() + p3.size();
        }
        ans = min(ans, sum);
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}
};