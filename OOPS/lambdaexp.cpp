#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nums = {5, 2, 9, 1};

    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a < b; // ascending order
    });

    for (int n : nums) cout << n << " ";

    cout << "\n";
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    cout << add(3, 4) << endl;;  // Output: 7
    int x = 10;
    auto f = [x]() mutable {
        x += 5;
        cout << x << endl; // prints 15
    };
    f();
    cout << x << endl; // prints 10 (original x is unchanged)

}
