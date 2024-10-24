class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int wordLen = words[0].size();
        int numWords = words.size();
        int windowLen = wordLen * numWords;
        int sLen = s.size();

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> currentCount;
            int left = i, count = 0;

            for (int j = i; j + wordLen <= sLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    currentCount[word]++;
                    count++;

                    while (currentCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        res.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return res;
    }
};
