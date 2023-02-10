#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    list<char> l;
    auto it = l.begin();
    auto it2 = l.begin();
    int N;
    cin >> N;
    cin.ignore();
    while(N--)
    {
        getline(cin,line);
        bool first = false;
        for(char ch : line)
        {
            if (ch == ']'){
                it = l.end();
            }else if (ch == '[')
            {
                it = l.begin();
                first = true;
            }else if (ch == '<')
            {
                if (first && !l.empty())
                {
                    l.erase(it2);
                }else if (!l.empty())
                {
                    l.pop_back();
                }
            }else {
                it2 = l.insert(it, ch);
            }
        }
        while(!l.empty()){
            cout << l.front();
            l.pop_front();
        }



    }

}
