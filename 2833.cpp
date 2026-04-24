class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int ans = 0;
        int count = 0;
        for(char c : moves){
            switch (c) {
                case 'L':
                    ans -= 1;
                    break;
                case 'R':
                    ans += 1;
                    break;
                case '_':
                    count +=1;
                    break;
                default:
                    break;
            }
        }
        return abs(ans) + count;
    }
};
