//Loop from left to right maintaining a balance variable when it gets an L increase it by one otherwise
// decrease it by one.Whenever the balance variable reaches zero then we increase the answer by one.
/*Using Stack*/
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        stack<char> LRcheck;

        for (int i = 0; i < s.size(); i++) {
            if (LRcheck.empty() || s[i] == LRcheck.top())
                LRcheck.push(s[i]);
            else
                LRcheck.pop();
            if (LRcheck.empty())
                count++;
        }
        return count;
    }
};

/*Using Variable*/
class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0;
        int LRcheck=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='L')
                LRcheck++;
            else if(s[i]=='R')
                LRcheck--;
            if(LRcheck==0)
                count++;
        }
        return count;
    }
};