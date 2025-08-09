class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA = 0, cntB = 0;
        int resA = 0, resB = 0;
        for (char c : colors) {
            if (c == 'A') {
                if (cntB) { resB += max(0, cntB - 2); cntB = 0; }
                cntA++;
            } else { 
                if (cntA) { resA += max(0, cntA - 2); cntA = 0; }
                cntB++;
            }
        }
        if (cntA) resA += max(0, cntA - 2);
        if (cntB) resB += max(0, cntB - 2);

        return resA > resB;
    }
};
