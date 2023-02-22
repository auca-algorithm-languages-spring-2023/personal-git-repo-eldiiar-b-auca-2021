#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void iteration(int &totalTime, queue<pair<int, int>> v[2],vector<int> &result, int &time, int &pos, int &capacity, int &i)
{
    if (!v[pos].empty() && v[pos].front().second <= totalTime && i < capacity) {
        result[v[pos].front().first] = totalTime + time ;
        v[pos].pop();
        i++;
        iteration(totalTime, v, result, time, pos, capacity, i);
    }
}
void solve(int &totalTime, queue<pair<int, int>> v[2],vector<int> &result, int &time, int &pos, int &capacity)
{
    if(!v[0].empty() || !v[1].empty()) {
        int i = 0, t = 0;
        if (!v[1].empty() && !v[0].empty())
        {
            t = min(v[1].front().second, v[0].front().second);
        }else if (!v[1].empty())
        {
            t = v[1].front().second;
        }else
            t = v[0].front().second;
        totalTime = max(t, totalTime);
        iteration(totalTime, v, result, time, pos, capacity, i);
        pos ^= 1;
        totalTime += time;
        solve(totalTime, v, result, time, pos, capacity);
    }
}
int main() {
    int N;
    cin >> N;
    while (N--) {
       queue<pair<int, int>> v[2];
        int capacity, time, testCases;
        cin >> capacity >> time >> testCases;
        for (int i = 0; i < testCases; i++) {
            int temp;
            cin >> temp;
            string shoreSide;
            cin >> shoreSide;
            if (shoreSide == "left") {
                v[0].emplace(i, temp);
            } else if (shoreSide == "right") {
                v[1].emplace(i, temp);
            }
        }
        int totalTime = 0;
        int pos = 0;
        if (!v[0].empty() && !v[1].empty() && v[0].front().second > v[1].front().second)
        {
            totalTime = v[1].front().second+time;
            pos ^= 1;
        }else{
            totalTime = v[0].front().second;
        }
        vector<int> result(testCases);
        solve(totalTime, v, result, time, pos, capacity);
        for (int i = 0; i < testCases; i++)
        {
            cout << result[i] << endl;
        }
        if (N != 0)
            cout << endl;
    }
}