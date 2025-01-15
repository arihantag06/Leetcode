class Solution {
public:
    int setBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int countA = setBits(num1);
        int countB = setBits(num2);
        if (countA == countB) return num1;

        int x = 0;
        if (countB < countA) {
            for (int i = 31; i >= 0; --i) {
                if (countB == 0) break;
                if (num1 & (1 << i)) {
                    x |= (1 << i);
                    --countB;
                }
            }
        } else {
            for (int i = 0; i < 32; ++i) {
                if (countB == 0) break;
                if (num1 & (1 << i)) {
                    x |= (1 << i);
                    --countB;
                }
            }
            for (int i = 0; i < 32; ++i) {
                if (countB == 0) break;
                if ((x & (1 << i)) == 0) {
                    x |= (1 << i);
                    --countB;
                }
            }
        }

        return x;
    }
};
