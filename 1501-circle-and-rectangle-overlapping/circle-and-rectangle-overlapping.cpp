class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = max(x1,min(x2,xCenter));
        int nearestY = max(y1,min(y2,yCenter));

        int distX = nearestX - xCenter;
        int distY = nearestY - yCenter;

        return pow(distX,2) + pow(distY,2) <= pow(radius,2);



    }
};