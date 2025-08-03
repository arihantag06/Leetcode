class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> hashA(26, 0), hashB(26, 0);
        for (char c : a) hashA[c - 'a']++;
        for (char c : b) hashB[c - 'a']++;

        vector<int> prefA(26, 0), prefB(26, 0);
        prefA[0] = hashA[0];
        prefB[0] = hashB[0];
        for (int i = 1; i < 26; i++) {
            prefA[i] = prefA[i - 1] + hashA[i];
            prefB[i] = prefB[i - 1] + hashB[i];
        }

        int totalA = a.size(), totalB = b.size();
        int ans = totalA + totalB;

        for (int i = 0; i < 25; i++) {
            int op1 = totalA - prefA[i] + prefB[i]; 
            int op2 = totalB - prefB[i] + prefA[i]; 
            ans = min({ans, op1, op2});
        }

        int op3 = totalA + totalB;
        for (int i = 0; i < 26; i++) {
            op3 = min(op3, totalA - hashA[i] + totalB - hashB[i]);
        }

        return min(ans, op3);
    }
};
