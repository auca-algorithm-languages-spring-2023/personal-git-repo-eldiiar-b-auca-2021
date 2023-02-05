#include <iostream>
#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void deleteTheTop(vector<int> &v, int &index)
{
    if (!s.empty() && v[index] == s.top())
    {
        index++;
        s.pop();
        deleteTheTop(v, index);
    }
}
int main()
{
    for (int n; cin >> n && n != 0;)
    {
        for (;;) {
            vector<int> v(n);
            int firstEl;
            cin >> firstEl;
            if (firstEl == 0){
                cout << endl;
                break;
            }
            v[0] = firstEl;
            for (int i = 1; i < n; i++) {
                cin >> v[i];
            }
            int c = 1, index = 0;
            for (; c <= n; c++)
            {
                s.push(c);
                deleteTheTop(v, index);
            }
            if (s.empty())
            {
                cout <<  "Yes" << endl;
            }else {
                cout << "No" << endl;
            }
            while(!s.empty())
            {
                s.pop();
            }
            v.clear();
        }
    }

}
