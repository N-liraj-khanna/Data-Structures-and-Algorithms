#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string p) {
    unordered_map<int,int> map;
    set<char>set({'!','@','#','$','%','^','&','*','(',')','-','+'});
    int op=0;
    if(p.size()<6){
        op=6-p.size();
    }
    for(char i: p){
        if(map.find(1)==map.end() && i>='0' && i<='9'){
          map[1]++;  
        } 
        else if(map.find(2)==map.end() && i>='a' && i<='z'){
          map[2]++;  
        } 
        else if(map.find(3)==map.end() && i>='A' && i<='Z'){
          map[3]++;  
        } 
        else if(map.find(4)==map.end() && set.find(i)!=set.end()){
          map[4]++;  
        } 
    }
    return 4-map.size()<op?op:4-map.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
