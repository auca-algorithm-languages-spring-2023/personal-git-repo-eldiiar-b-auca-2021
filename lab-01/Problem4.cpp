#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<string> s;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "Sleep")
        {
            string name;
            cin >> name;
            s.push(name);
        }
        if (command == "Test")
        {
            if (!s.empty())
            cout << s.top() << endl;
            else
                cout << "Not in a dream" << endl;
        }
        if (command == "Kick")
        {
            if (!s.empty())
            s.pop();
        }


    }
}