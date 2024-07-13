#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the minimum number of stacks needed for a given container schedule
int minimum_stacks(const string &container_schedule) {
    vector<string> stacks;

    for (char container : container_schedule) {
        bool placed = false;
        for (auto &stack : stacks) {
            if (stack.back() >= container) {
                stack.push_back(container);
                placed = true;
                break;
            }
        }
        if (!placed) {
            stacks.emplace_back(1, container);
        }
    }

    return stacks.size();
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore the newline after the number

    vector<int> results;

    for (int i = 0; i < N; ++i) {
        string container_schedule;
        getline(cin, container_schedule);
        results.push_back(minimum_stacks(container_schedule));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
