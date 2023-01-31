//
// Created by eldii on 1/31/2023.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    for (string s; (getline(cin, s));)
    {
        list<char> l;
        auto it = l.begin();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                it = l.begin();
                while(s[i] == '[')
                {
                    i++;
                }
                i--;
            }
            else if (s[i] == ']')
            {
                it = l.end();
                while(s[i] == ']')
                {
                    i++;
                }
                i--;
            }else {
                l.insert(it, s[i]);
            }
        }
        for (auto i = l.begin(); i != l.end(); i++)
        {
            cout << *i;
        }
        //cout << endl;

    }



}
