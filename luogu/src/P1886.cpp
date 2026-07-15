#include <iostream>
#include <queue>
using namespace std;

const int NUM = 1000010;
int arr[NUM];

int main()
{
    int n = 0, k = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    /**
     * realization 1
     */
    deque<int> q1;
    for (int i = 0; i < n; i++)
    {
        if (!q1.empty() && q1.front() + k <= i)
            q1.pop_front();

        if (!q1.empty() && arr[i] <= arr[q1.back()])
        {
            while (!q1.empty() && arr[i] <= arr[q1.back()])
                q1.pop_back();
        }
        q1.push_back(i);
        if (i >= k - 1)
            cout << arr[q1.front()] << " ";
    }
    cout << endl;

    /**
     * realization 2
     */
    deque<int> q2;
    for (int i = 0; i < n; i++)
    {
        if (!q2.empty() && arr[i] >= arr[q2.back()])
        {
            while (!q2.empty() && arr[i] >= arr[q2.back()])
                q2.pop_back();
        }
        q2.push_back(i);
        if (i >= k - 1)
        {
            while(q2.front() + k <= i)
                q2.pop_front();
            cout << arr[q2.front()] << " ";
        }
    }
    cout << endl;

    return 0;
}