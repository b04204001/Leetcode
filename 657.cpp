class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0;
        int j = 0;
        for(char c : moves){
            if(c == 'L'){
                i -= 1;
            }
            else if (c == 'R'){
                i += 1;
            }
            else if(c == 'U'){
                j += 1;
            }
            //D
            else{
                j-=1;
            }
        }
        return i == 0 && j == 0;
    }
};
