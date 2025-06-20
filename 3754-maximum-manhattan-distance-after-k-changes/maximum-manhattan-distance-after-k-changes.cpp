class Solution {
public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0,ans=0;
        for (int i=0;i<s.size();i++) {
            char ch = s[i];
            if (ch == 'N') y++;
            else if (ch == 'S') y--;
            else if (ch == 'E') x++;
            else if (ch == 'W') x--;

            ans = max(ans , min(i+1, abs(x) + abs(y) + 2 * k));
        }
        return ans;
    }
};
