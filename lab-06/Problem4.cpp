#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, double> m;

    int N, G;
    cin >> N;
    cin >> G;

    while(N--)
    {
        string s;
        cin >> s;
        double t;
        cin >> t;
        m[s] = 10*t;
    }
    cin.ignore();
    for (int i = 1; i <= G; i++)
    {
        string st;
        getline(cin, st);
        istringstream ss(st);
        string temp;
        int sum = 0;
        bool  correct = false;
        while(ss >> temp)
        {
            if (m[temp] != 0)
            {
                sum += m[temp];
            }else if(temp == "<=" || temp == ">" || temp == "<" || temp == ">=" || temp == "="){
                int n;
                ss >> n;
                if (temp == "=")
                {
                    if (n*10 == sum){
                        correct = true;
                    }
                }
                if (temp == "<")
                {
                    if (sum < n*10){
                        correct = true;
                    }
                }
                if(temp == "<=")
                {
                    if (sum <= n*10)
                    {
                        correct = true;
                    }
                }
                if (temp == ">")
                {
                    if (sum > n*10)
                    {
                        correct = true;
                    }
                }
                if(temp == ">=")
                {
                    if (sum >= n*10)
                    {
                        correct = true;
                    }
                }
            }
        }
        if(correct)
            cout << "Guess #" << i << " was correct." << endl;
        else
            cout << "Guess #" << i << " was incorrect." << endl;

    }
}