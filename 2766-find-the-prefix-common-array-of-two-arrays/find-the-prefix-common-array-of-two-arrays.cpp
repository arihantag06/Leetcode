class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n), frequency(n + 1, 0);
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            if (++frequency[A[i]] == 2) ++commonCount;

            if (++frequency[B[i]] == 2) ++commonCount;

            prefixCommonArray[i] = commonCount;
        }

        return prefixCommonArray;
    }
};