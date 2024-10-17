class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirX = 0,dirY=1;
        int finalX = 0,finalY = 0;
        for(char c:instructions){
            if(c=='G'){
                finalY = finalY + 1*dirY;
                finalX = finalX + 1*dirX;
            }
            else if(c=='L'){
                if(dirX==0 && dirY == 1){
                    dirX = -1;
                    dirY = 0;
                }
                else if(dirX==-1 && dirY==0){
                    dirX = 0;
                    dirY = -1;
                }
                else if(dirX==0 && dirY==-1){
                    dirX=1;
                    dirY=0;
                }
                else if(dirX==1 && dirY==0){
                    dirX=0;
                    dirY=1;
                }
            }
            else if(c=='R'){
                if(dirX==0 && dirY==1){
                    dirX=1;
                    dirY=0;
                }
                else if(dirX==1 && dirY==0){
                    dirX=0;
                    dirY=-1;
                }
                else if(dirX==0 && dirY==-1){
                    dirX=-1;
                    dirY=0;
                }
                else if(dirX==-1 && dirY==0){
                    dirX = 0;
                    dirY =1;
                }
            }
        }
        if((finalX==0 && finalY==0) || !(dirX==0 && dirY==1)){
            return true;
        }
        return false;
    }
};