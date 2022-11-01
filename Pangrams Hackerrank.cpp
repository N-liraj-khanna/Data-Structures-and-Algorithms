#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    vector<int> alpha(26,0);
    int cnt=0;
    for(int c: s){
        if(c==' ') continue;
        if(c<91){
            if(alpha[c-'A']==0) cnt++;
            alpha[c-'A']++;
        } 
        else if(c<123){
            if(alpha[c-'a']==0) cnt++;
             alpha[c-'a']++;
        }
    }

    return cnt==26?"pangram":"not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
