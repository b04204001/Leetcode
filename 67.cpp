class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.size()- 1;
        int bl = b.size()-1;

        int carry = 0;
        string ans = "";
        while(al >= 0 || bl >= 0 || carry > 0){
            int sum = carry;
            if (al >= 0){
                sum +=(a[al]-'0');
                al--;
            }
            if (bl >=0){
                sum +=(b[bl]-'0');
                bl--;
            }
            carry = sum / 2;
            int digit = sum % 2;
            ans += digit + '0';
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
