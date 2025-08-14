// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         char best = '\0';
//         int n = num.size();
//         for (int i = 0; i<n-2; ++i)
//             if (num[i] == num[i+1] && num[i] == num[i+2] && num[i] > best)
//                 best = num[i];
//         return best ? string(3, best) : "";
//     }
// };


class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_set<string> mp = {"999","888","777","666","555","444","333","222","111","000"};
        string ans = "";
        for (int i = 0; i + 2 < (int)num.size(); i++) {
            string t = num.substr(i, 3);
            if (mp.count(t) && t > ans)
                ans = t;
        }
        return ans;
    }
};

