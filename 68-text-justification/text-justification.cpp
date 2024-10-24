class Solution {
public:
    int MW;

    string findLine(int i,int j,int eachEvenSpace,int extraEvenSpace,vector<string>&words){
        string line;

        for(int k=i;k<j;k++){
            line+=words[k];
            if(k==j-1){
                continue;
            }
            for(int z = 1;z<=eachEvenSpace;z++){
                line+=" ";
            }
            if(extraEvenSpace>0){
                line+=" ";
                extraEvenSpace--;
            }
        }
        while(line.length()<MW){
            line+=" ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int N = words.size();
        MW = maxWidth;

        int i=0;
        while(i<N){
            int lettersCount=  words[i].length();
            int j=i+1;
            int spaces = 0;
            while(j<N && words[j].length()+1+spaces+lettersCount<=MW){
                lettersCount+=words[j].length();
                spaces+=1;
                j++;
            }

            int remainingSlots = MW-lettersCount;

            int eachEvenSpace = spaces==0?0:remainingSlots/spaces;
            int extraEvenSpace = spaces==0?0:remainingSlots%spaces;

            if(j==N){
                eachEvenSpace = 1;
                extraEvenSpace = 0;
            }
            result.push_back(findLine(i,j,eachEvenSpace,extraEvenSpace,words));
            i=j;
        }
        return result;
    }
};