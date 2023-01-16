// tc=o(n)
// sc=o(n/2)
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    long n=s.size();
    if(n%2==1) return -1;
    unordered_map<char,int> map;
    for(long i=0;i<n/2;i++){
        map[s[i]]++;
    }
    long res=0;
    for(long i=n/2;i<n;i++){
        if(map.find(s[i])!=map.end()){
            map[s[i]]--;
            if(map[s[i]]==0) map.erase(s[i]);
        }else{
            res++;
        }
    }
    return res;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
