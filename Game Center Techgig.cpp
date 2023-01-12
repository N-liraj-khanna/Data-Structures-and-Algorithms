// Game Center (100 Marks)
// You and your friend go to a game arcade where you choose to play the game Lucky Pick. In the game, there is a square grid and on each block, some money is placed on it. When a player chooses a block, the machine randomly chooses a block from the neighboring ones and the chosen block (consider 8 neighborhood). The player is awarded the money that is placed on the block that the machine selects. Your friend needs help choosing the block.

// Your job is to return the block position(s) that will maximize the minimum amount your friend will win for sure. If there are more than one such block positions then the output must return for all these positions.

// Input Format
// You will be given the Grid Description as -
// The first line consists of the size of the square grid (N)
// The next N lines each containing N numbers separated by '#', each number representing the amount of money put on that block


// Constraints
// 1 < N < 500

// Output Format
// You need to print the array of string containing the position(s) of a block choosing which will give the maximum amount of money which your friend will definitely win.

// Sample TestCase 1
// Input

// 3

// 12#45#33

// 94#54#23

// 98#59#27
// Output

// 3#1
// Explanation

// In the above example, if he selects the block (3,1), then under the best case, he could win is 98 and under the worst case the maximum he could win is 54. In such scenario, the worst case of block (3,1) gives your friend more money than the worst case of other blocks.

/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<iostream>
#include<vector>
using namespace std;

int min_comp(vector<vector<int>>& arr, int a, int b){
    int mini=INT_MAX;
    for(int i=a-1;i<=a+1;i++){
        for(int j=b-1;j<=b+1;j++){
            i=i>=0?i:0;
            // i=i<arr.size()?i:arr.size()-1;
            j=j>=0?j:0;
            // j=j<arr[0].size()?j:arr[0].size()-1;
            mini=min(mini,arr[i<arr.size()?i:arr.size()-1][j<arr[0].size()?j:arr[0].size()-1]);
        }
    }
    return mini;
}

int main(int argc, char *a[]){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int t=0;
        vector<int> temp;
        for(int j=0;j<=s.size();j++){
            if(j==s.size() || s[j]=='#'){ 
                temp.push_back(t);
                t=0;
            }else{
                t=t*10+(s[j]-'0');
            }
        }
        arr.push_back(temp);
    }

    int m=arr[0].size();
    int maxi=INT_MIN;
    vector<vector<int>> min_arr(n,vector<int> (m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            min_arr[i][j]=min_comp(arr, i, j);
            maxi=max(maxi,min_arr[i][j]);
        }
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(min_arr[i][j]==maxi){
                cout<<i+1<<"#"<<j+1<<endl;
            }
        }
    }
}   