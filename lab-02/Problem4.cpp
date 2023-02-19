#include <iostream>
#include <queue>

using namespace std;

static int map[1000000];
int main()
{
    int T, count = 1;
    while(cin >> T) {
        for (int i = 1; i <= T; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int t;
                cin >> t;
                map[t] = i;
            }
        }
        queue<int> teamControl;
        queue<int> teams[1100];
        cout << "Scenario #" << count++ << "\n";
        while (true) {
            string str;
            cin >> str;
            if (str[0] == 'S')
                break;
            else if (str[0] == 'E') {
                int number;
                cin >> number;
                if (teams[map[number]].empty()) {
                    teamControl.push(map[number]);
                }
                teams[map[number]].push(number);
            }else
            if (str[0] == 'D') {
                int result = teams[teamControl.front()].front();
                cout << result << "\n";
                teams[teamControl.front()].pop();
                if (teams[teamControl.front()].empty())
                    teamControl.pop();
            }
        }
        cout << "\n";
    }


}