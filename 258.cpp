class Solution {
public:
    int add(int num){
        int ans =0;
        while(num>0){
            ans += num %10;
            num /=10;
        }
        return ans;
    }

    int addDigits(int num) {
        while(num >=10){
            num = add(num);
        }
        return num;
    }
};
