#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int T, count = 1;
    while(cin >> T && T != 0) {
        int t, n;
        vector<int> map(1000000);
        for (int i = 1; i <= T; i++) {
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> t;
                map[t] = i;
            }
        }
        queue<int> teamControl;
        queue<int> teams[1000];
        cout << "Scenario #" << count++ << "\n";
        string str;
        int number;
        while (true) {
            cin >> str;
            if (str[0] == 'S')
                break;
            else if (str[0] == 'E') {
                cin >> number;
                if (teams[map[number]].empty()) {
                    teamControl.push(map[number]);
                }
                teams[map[number]].push(number);
            }else if (str[0] == 'D') {
                cout << teams[teamControl.front()].front() << "\n";
                teams[teamControl.front()].pop();
                if (teams[teamControl.front()].empty())
                    teamControl.pop();
            }
        }
        cout << "\n";
    }


}