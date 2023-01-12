// tc=o(3*n^2)
// sc=o(1)
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    for(int len=1;len<=s.size()/2;len++){
        long pref=0,i,j;
        for(i=0;i<len;i++){
            pref=pref*10+(s[i]-'0');
        }
        bool flag=true;
        string target;
        long start=pref;
        while(flag && i<s.size()){
            flag=true;
            target=to_string(++pref);
            for(j=0;j<target.size() && i<s.size();j++,i++){
                if(target[j]!=s[i]){
                    flag=false;
                    break;
                }
            }    
            if(j!=target.size() && i==s.size()) flag=false;
        }
        if(flag){
            cout<<"YES "<<start<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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


// tc=o(4*n^2)
// sc=o(1)
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    for(int len=1;len<=s.size()/2;len++){
        long start=0;
        for(int i=0;i<len;i++){
            start=start*10+(s[i]-'0');
        }
        long first=start;
        string pref=to_string(start);
        while(pref.size()<s.size()){
            pref+=to_string(++start);
        }
        if(pref==s){
            cout<<"YES "<<first<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
