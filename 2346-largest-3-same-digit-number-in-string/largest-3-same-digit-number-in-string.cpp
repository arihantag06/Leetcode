class Solution {
public:
    string largestGoodInteger(string num) {
        char best = 0;
        int n = num.size();
        for (int i = 0; i<n-2; ++i)
            if (num[i] == num[i+1] && num[i] == num[i+2] && num[i] > best)
                best = num[i];
        return best ? string(3, best) : "";
    }
};
