#include <iostream>
#include <vector>
#include <algorithm>

/*
The Strategy Pattern is a behavioral design pattern that lets you define a family of algorithms, encapsulate each one,
and make them interchangeable at runtime without changing the context (i.e., the main object using them).
*/
using namespace std;

// 1. Strategy interface
class SortStrategy {
public:
    virtual void sort(vector<int>& data) = 0;
    virtual ~SortStrategy() = default;
};

// 2. Concrete strategies
class BubbleSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "Using Bubble Sort\n";
        for (size_t i = 0; i < data.size(); ++i)
            for (size_t j = 0; j < data.size() - i - 1; ++j)
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
    }
};

class QuickSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "Using Quick Sort\n";
        std::sort(data.begin(), data.end());  // uses STL quicksort internally
    }
};

// 3. Context
class SortContext {
    SortStrategy* strategy;
public:
    void setStrategy(SortStrategy* s) {
        strategy = s;
    }

    void sortData(vector<int>& data) {
        if (strategy)
            strategy->sort(data);
    }
};

// 4. Client
int main() {
    vector<int> numbers = {5, 3, 8, 1, 2};

    SortContext context;

    BubbleSort bubble;
    QuickSort quick;

    // Use Bubble Sort
    context.setStrategy(&bubble);
    context.sortData(numbers);

    for (int n : numbers) cout << n << " ";
    cout << "\n";

    // Shuffle and use Quick Sort
    numbers = {9, 7, 6, 4, 3};

    context.setStrategy(&quick);
    context.sortData(numbers);

    for (int n : numbers) cout << n << " ";
    cout << "\n";

    return 0;
}
