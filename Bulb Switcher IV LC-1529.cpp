//Most Optimal Implementation
//TC=>O(N) SC=>O(1)
//The intuition is, we have to calculate the number of transistion in the given string
//i.e., for 101, we changing from 1 to 0 once then 0 to 1 once then again reaching 1
//so in this case 3 flips required, in case the given switches is starting from 0,
//we've to ignore all starting zeroes, cuz its in resting position so no need of change
//If we observe properly, thats the number of times we fliping while doing normal operation
//like actually flipping in the second approach with a method for flipping itself
class Solution {
public:
    int minFlips(string target) {

        int n = target.size() - 1;
        int count = 0;
        char status = '0';   //says which is the current state

        for (int j = 0;j <= n; j++) {
            if (target[j] != status) {
                count++;
                // status = status=='0'?'1':'0'; //for more understanding
                status = target[j]; //flips the transition, when actual transition occurs
            }               //in the given switch string
        }

        return count;
    }
}; 
//Much Better than before method using single loop
//TC=>O(N^2) SC=>O(1)
class Solution {
public:
     void flipSwitch(string& s, int start) {
        for (int i = start; i < s.size(); i++) {
            s[i] = (s[i] == '0') ? '1' : '0';
        }
    }
    
    int minFlips(string target) {

        int n = target.size() - 1;
        int count = 0;

        for (int j = 0;j <= n; j++) {
            if (target[j] == '1') {
                flipSwitch(target, j);
                count++;
            }
        }

        return count;
    }
};

//using two loops, dumb  method
//TC=>O(N^3) SC=>O(1)
class Solution {
public:
     void flipSwitch(string& s, int start) {
        for (int i = start; i < s.size(); i++) {
            s[i] = (s[i] == '0') ? '1' : '0';
        }
    }
    int minFlips(string target) {

        int n = target.size() - 1;
        int i = 0, j = n, count = 0;

        for (i = 0; i <= n; i++) {
            for (j = i; target[j] != '1' && j <= n; j++) {}
            if (j == n + 1) return count;
            flipSwitch(target, j);
            count++;
        }
        return count;
    }
};