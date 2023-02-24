#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string word;
    set<string> set;
    for (char ch; cin >> ch;)
    {
        ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z')
        {
            word+=ch;
        }else{
            if (!word.empty())
            {
                set.insert(word);
                word = "";
            }
        }
    }
    for (auto it : set)
    {
        cout << it << endl;
    }
}