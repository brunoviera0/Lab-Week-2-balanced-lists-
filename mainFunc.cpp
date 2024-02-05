#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "prefixSum.h"
#include "fisher_yates.h"

using namespace std;

int main() {
    srand(time(0)); //random number generation
    const int n = 5; 
    int totalRuns = 10000;
    int balancedCount = 0;

    for (int i = 0; i < totalRuns; i++) {
        vector<int> array(2 * n);
        
        for (int j = 0; j < n; j++) {
            array[j] = 1;
            array[j + n] = -1;
        }

        fisher_yates(array.data(), 2 * n);

        if (non_neg_prefix_sum(array) || non_pos_prefix_sum(array)) {
            balancedCount++;
        }
    }

    cout << "The ratio of well-balanced arrays is " << static_cast<double>(balancedCount) / totalRuns << endl;

    return 0;
}
