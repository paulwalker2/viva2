#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void jobSchedule(Job arr[], int n)
{

    sort(arr, arr + n, comparison);

    char result[n];
    bool slots[n];

    for (int i = 0; i < n; i++)
        slots[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slots[j] == false)
            {
                slots[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    // print result
    for (int i = 0; i < n; i++)
    {
        if (slots[i])
        {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << "\n";
}

int main()
{

    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);

    jobSchedule(arr, n);
    return 0;
}