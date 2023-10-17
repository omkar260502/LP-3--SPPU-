#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (Item item : items)
    {
        if (currentWeight + item.weight <= capacity)
        {
            currentWeight += item.weight;
            totalValue += item.value;
        }
        else
        {
            int remainingWeight = capacity - currentWeight;
            totalValue += item.ratio * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);

    for (int i = 0; i < numItems; i++)
    {
        cout << "Enter weight and value for Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value obtained = " << maxValue << endl;

    return 0;
}
/*
Time Complexity: O(N * logN)
Auxiliary Space: O(N)
*/