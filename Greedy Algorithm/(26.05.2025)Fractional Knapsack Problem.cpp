// Sir provided the question in the Google Classroom.
#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    string name;
    double weight, unitPrice, value;
};

bool comp(item i1, item i2)
{
    return (i1.unitPrice > i2.unitPrice); // to get minimum just change (i1.unitPrice < i2.unitPrice)
}

int main()
{
    int n;
    double capacity;
    cout << "Enter the number of boxes: ";
    cin >> n;

    item arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].value >> arr[i].weight;
        arr[i].unitPrice = arr[i].value / arr[i].weight;
    }
    sort(arr, arr+n, comp);

    cout << "Enter the capacity: ";
    cin >> capacity;

    double total_value = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].weight <= capacity)
        {
            total_value += arr[i].value;
            capacity -= arr[i].weight;
        }

        else
        {
            total_value += arr[i].unitPrice * capacity;
            break;
        }
    }

    cout << "Profit: " << total_value << endl;
    cout << "Box\tValue\tWeight\tPer unit price\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i].name << "\t" 
             << arr[i].value << "\t" 
             << arr[i].weight << "\t" 
             << arr[i].unitPrice << endl;
    }
}
