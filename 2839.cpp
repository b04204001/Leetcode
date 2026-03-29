class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // 2種交換 (0,2) (1,3) 
        //不換
        if( s1 == s2) return true;
        //只換02
        swap(s1[0],s1[2]);
        if( s1 == s2) return true;
        //換了02 + 13
        swap(s1[1],s1[3]);
        if( s1 == s2) return true;
        //只換13
        swap(s1[0],s1[2]);
        if( s1 == s2) return true;
        return false;
    }
};



class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
                (s1[0] == s2[2] && s1[2] == s2[0]))
            &&
               ((s1[1] == s2[1] && s1[3] == s2[3]) ||
                (s1[1] == s2[3] && s1[3] == s2[1]));
    }
};
