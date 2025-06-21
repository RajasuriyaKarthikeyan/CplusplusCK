#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item{
    double profit;
    double weight;
    double profitperweight;

    Item(double p, double w){
        profit = p;
        weight = w;
        profitperweight = profit/weight;
        // cout << profitperweight << endl;
    }
};

bool compare(Item& a, Item& b){
    return a.profitperweight > b.profitperweight;
}

void knapsackMax(double capacity, vector<Item> items){
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    double remainCapacity = capacity;

    for(int i=0;i<items.size();i++){
        cout << "RemainCapacity and TotalValue : " << remainCapacity << "   "<< totalValue << endl;
        if(remainCapacity == 0){
            break;
        }

        if(items[i].weight <= remainCapacity){
            totalValue += items[i].profit;
            remainCapacity-=items[i].weight;
        } else {
            double balance = items[i].profitperweight*remainCapacity;
            cout << "Balance : " << balance << endl;
            totalValue += balance;
            remainCapacity=0;
        }
    }
    cout << "Maximum Profit out of Knapsack Capacity: " << totalValue << endl;
}

int main(){
    int n;
    cout << "Enter the number of Items : ";
    cin >> n;
    vector<Item> items;
    cout << "Enter the profit and weight of each time:\n ";
    for(int i=0;i<n;i++){
        int profit,weight;
        cin >> profit >> weight;
        items.push_back(Item(profit, weight));
    }
    double capacity;
    cout << "Enter the knapsack Capacity : ";
    cin >> capacity;
    knapsackMax(capacity, items);
    return 0;
}