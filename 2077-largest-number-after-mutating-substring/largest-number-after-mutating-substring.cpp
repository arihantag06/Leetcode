class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.length(), i = 0;
        while (i < n && change[num[i] - '0'] <= (num[i] - '0')){
            i++;
        }

        if(i == n) return num;
        while (i < n && change[num[i] - '0'] >= (num[i] - '0')){
         num[i++] = '0' + change[num[i] - '0'];
        }
        return num;
    }
};