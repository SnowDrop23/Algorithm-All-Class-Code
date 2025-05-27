/* Input
 Activity:   a1  a2  a3  a4  a5  a6  a7  a8  a9
 Start Time: 5   2   4   1   0   5   3   3   2
 End Time:   9   3   7   3   2   8   5   3   4


 Output
 i. Number of maximum selected activities
 ii. The selected activities

  */

#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    string activity;
    double start_time, end_time;
};

bool comp(item i1, item i2)
{
    return (i1.end_time < i2.end_time);
}

int main()
{
    int n, count = 1;
    cout << "Enter the number of activities: ";
    cin >> n;

    item arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].activity >> arr[i].start_time >> arr[i].end_time;
    }
    sort(arr, arr+n, comp);



    cout << "Activity\tStart Time\tEnd Time\n";
    cout << arr[0].activity << "\t\t" << arr[0].start_time << "\t\t" << arr[0].end_time << endl;
    double last_end = arr[0].end_time;


    for(int i = 1; i < n; i++)
    {
        if(arr[i].start_time >= last_end)
        {
            cout << arr[i].activity << "\t\t"
                 << arr[i].start_time << "\t\t" 
                 << arr[i].end_time << "\t" << endl;
            last_end = arr[i].end_time;
            count++;
        }
    }
    cout << "Selected activities: " << count << endl;;
    return 0;
}
