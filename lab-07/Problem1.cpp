#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    map<string, long long> mp;
    char ch;
    string s;
    long long sum = 0;
    for (int i = 1; i <= 26; i++)
    {
        s ="";
        sum++;
        ch = 96+i;
        s += ch;
        mp[s] = sum;

    }

    for (int i = 1; i <= 25; i++)
    {
        for (int j = i+1; j <=26; j++)
        {
            s = "";
            ch = 96+i;
            s += ch;
            ch = 96 + j;
            sum++;
            s += ch;
//            cout << s << " " << sum;
            mp[s] = sum;
        }
   }
    for (int i = 1; i <= 24; i++)
    {
        for (int j = i+1; j <=25; j++)
        {
            for (int k = j+1; k <= 26; k++) {
                s = "";
                ch = 96 + i;
                s += ch;
                ch = 96 + j;
                s += ch;
                ch = 96 + k;
                s += ch;
                sum++;
                mp[s] = sum;
            }
        }
    }
    for (int i = 1; i <= 23; i++)
    {
        for (int j = i+1; j <=24; j++)
        {
            for (int k = j+1; k <= 25; k++) {
                for (int l = k + 1; l <= 26; l++) {
                    s = "";
                    ch = 96 + i;
                    s += ch;
                    ch = 96 + j;
                    s += ch;
                    ch = 96 + k;
                    s += ch;
                    ch = 96 + l;
                    s += ch;
                    sum++;
                    mp[s] = sum;
                }
            }
        }
    }
    for (int i = 1; i <= 22; i++)
    {
        for (int j = i+1; j <=23; j++)
        {
            for (int k = j+1; k <= 24; k++) {
                for (int l = k + 1; l <= 25; l++) {
                    for (int m = l+1; m <= 26; m++) {
                        s = "";
                        ch = 96 + i;
                        s += ch;
                        ch = 96 + j;
                        s += ch;
                        ch = 96 + k;
                        s += ch;
                        ch = 96 + l;
                        s += ch;
                        ch = 96 + m;
                        s += ch;
                        sum++;
                        mp[s] = sum;
                    }
                }
            }
        }
    }
    for (string text; cin >> text; ) {
        cout << mp[text] << endl;
    }
}