// tc=o(v) worst case
// sc=o(1)
#include <bits/stdc++.h> 
int findMinimumCoins(int V) 
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int M = 9;
    
    int res=0, val=0;
    for(int i=M-1;i>=0;i--){
        while(val+coins[i]<=V){
            val+=coins[i];
            res++;
        }
    }
    return val==V?res:-1;
}
