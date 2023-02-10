#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
void count(queue<int> &q,  int &length, int &sum);
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int length, m;
        cin >> length;
        length*=100;
        cin >> m;
        queue<int> first;
        queue<int> second;
        for(int j = 0; j < m; j++)
        {
            int centimeters;
            cin >> centimeters;
            string bank;
            cin >> bank;
            if (bank == "left")
            {
                second.push(centimeters);
            }else {
                first.push(centimeters);
            }
        }
        bool beg = true;
        int cross = 0;
        while(!(first.empty() && second.empty())) {
            int sum = 0;
            if (beg) {
                count(second,  length, sum);
                beg = false;
            }else {
                count(first, length, sum);
                beg = true;
            }
            cross++;
        }
        cout << cross << endl;
    }

}

void count(queue<int> &q,  int &length, int &sum) {
    if (!q.empty() && sum + q.front() <= length)
    {
        sum += q.front();
        q.pop();
        count( q,  length, sum);
    }
}
