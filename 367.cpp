class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int temp,i;
        for(i=1;;i++){
            temp=i*i;
            if(temp==num){
                return true;
            }
            if(temp>num){
                break;
            }
        }

            return false;
    }
};
