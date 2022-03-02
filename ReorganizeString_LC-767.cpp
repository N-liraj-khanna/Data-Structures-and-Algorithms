#include <bits/stdc++.h>

using namespace std;

struct PQstr
{
    char c;
    int n;
    PQstr(char character,int count)
    {
        c = character;
        n = count;
    }
};

struct CompareStr
{
    bool operator()(PQstr const &p1, PQstr const &p2)
    {
        return p1.n < p2.n;
    }
};

string reorganizer(string s)
{
    map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
    }
    priority_queue<PQstr, vector<PQstr>, CompareStr> pq;
    for (auto i : map)
        pq.push(PQstr(i.first, i.second));
    if (pq.top().n > (s.size()+1)/ 2)
        return "";
    string ans = "";
    while (!pq.empty())
    {
        if (pq.size() > 1)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.c + p2.c;
            if (p1.n > 0)
            {
                p1.n--;
                pq.push(p1);
            }
            if (p2.n > 0)
            {
                p2.n--;
                pq.push(p2);
            }
        }
        else
        {
            ans+=pq.top().c;
            pq.pop();
        }
    }
    return ans;
}

int main()
{
    cout << reorganizer("KKhaaannnaa");
    return 0;
}
