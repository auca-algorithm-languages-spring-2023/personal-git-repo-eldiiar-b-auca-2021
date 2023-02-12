#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    list<char> l;
    int N;
    cin >> N;
    cin.ignore();
    while(N--)
    {
        auto it = l.begin();
        getline(cin,line);
        for(char ch : line)
        {
            if (ch == ']'){
                it = l.end();
            }else if (ch == '[')
            {
                it = l.begin();
            }else if (ch == '<')
            {
                if (it != l.begin())
                {
                    it--;
                    it=l.erase(it);
                }
            }else {
                it = l.insert(it, ch);
                it++;
            }
        }
        while(!l.empty())
        {
            cout << l.front();
            l.pop_front();
        }
        line = "";
        cout << endl;
    }

}
