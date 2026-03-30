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

//優解
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;

            int sum = x ^ y ^ carry;  // XOR = 無進位加法
            carry = (x & y) | (x & carry) | (y & carry); // 進位

            res += sum + '0';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
