#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if(s[8]=='A'){
        if(s[0]=='1' && s[1]=='2'){
          s[0]='0';
          s[1]='0';
          return s.substr(0,8) ; 
        }else{
            return s.substr(0,8);
        }
    }else{
        if(s[0]=='1' && s[1]=='2'){
            return s.substr(0,8);
        }else{
            int convert=stoi(s.substr(0,2))+12;
            string out = to_string(convert);
            if(convert<10){
                s[1]=out[0];
            }else{
                s[0]=out[0];
                s[1]=out[1];
            }
            return s.substr(0,8);
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
