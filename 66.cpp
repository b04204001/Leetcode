class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        for(int i= digits.size()-1 ; i>=0; i--){
            if( digits[i] ==10){
                if(i==0){
                    vector<int> d2;
                    d2.push_back(1);
                    d2.push_back(0);
                    for(int j=1;j<digits.size();j++){
                        d2.push_back(digits[j]);
                    }
                    return d2;
                }
                digits[i] = 0;
                digits[i-1] ++;
            }
            else{
                break;
            }
        }
        return digits;
    }
};
