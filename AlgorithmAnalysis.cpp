#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/**
* Cubic maximum contiguous subsequence sum algorithm.
*/
int maxSubSum1(const vector<int> &a) {
    int maxSum = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {

            int thisSum = 0;

            for (int k = 0; k < j; k++) {
                thisSum += a[k];
            }

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}//end of maxSubSum1

/**
* Quadratic maximum contiguous subsequence sum algorithm.
*/
int maxSubSum2(const vector<int> &a) {
    int maxSum = 0;

    for (int i = 0; i < a.size(); i++) {
        int thisSum = 0;
        for (int j = 0; j < a.size(); j++) {
            thisSum += a[j];

            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}//end of maxSubSum2

/**
* Recursive maximum contiguous subsequence sum algorithm.
* Finds maximum sum in subarray spanning a[left...right].
* Does not attempt to maintain actual best sequence.
*/
int maxSubSumRec(const vector<int> &a, int left, int right) {
    if (left == right) // base case
        if (a[left] > 0)
            return a[left];
        else
            return 0;

    int center = (left + right) / 2;
    int maxLeftSum = maxSubSumRec(a, left, center);
    int maxRightSum = maxSubSumRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center + 1; j <= right; j++) {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    maxLeftSum = max(maxLeftSum, maxRightSum);
    return max(maxLeftSum, maxLeftBorderSum + maxRightBorderSum);
}//end of maxSubSumRec

/**
* Driver for divide-and-conquer maximum contigous
* subsequence sum algorithm.
*/
int maxSubSum3(const vector<int> &a) {
    return maxSubSumRec(a, 0, a.size() - 1);
}

/**
* Linear-time maximum contigous subsequence sum algorithm.
*/
int maxSubSum4(const vector<int> &a) {
    int maxSum = 0, thisSum = 0;

    for (int j = 0; j < a.size(); j++) {
        thisSum += a[j];

        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            maxSum = 0;
    }

    return maxSum;
}

vector<int> createRandomArray(int size) {
    vector<int> v;
    for (int i = 0; i < size; i++) {
        v.push_back(static_cast<int>((pow(-1, rand() % 2)) * (rand() % 10000)));
    }
    return v;
}

int main() {

    vector<int> vectorArray[13];

    vector<int> arr10 = createRandomArray(10);
    vectorArray[0] = arr10;

    vector<int> arr50 = createRandomArray(50);
    vectorArray[1] = arr50;

    vector<int> arr100 = createRandomArray(100);
    vectorArray[2] = arr100;

    vector<int> arr500 = createRandomArray(500);
    vectorArray[3] = arr500;

    vector<int> arr1000 = createRandomArray(1000);
    vectorArray[4] = arr1000;

    vector<int> arr2000 = createRandomArray(2000);
    vectorArray[5] = arr2000;

    vector<int> arr8000 = createRandomArray(8000);
    vectorArray[6] = arr8000;

    vector<int> arr40000 = createRandomArray(40000);
    vectorArray[7] = arr40000;

    vector<int> arr100000 = createRandomArray(100000);
    vectorArray[8] = arr100000;

    vector<int> arr500000 = createRandomArray(500000);
    vectorArray[9] = arr500000;

    vector<int> arr1000000 = createRandomArray(1000000);
    vectorArray[10] = arr1000000;

    vector<int> arr10000000 = createRandomArray(10000000);
    vectorArray[11] = arr10000000;

    vector<int> arr100000000 = createRandomArray(100000000);
    vectorArray[12] = arr100000000;

    double duration;
    clock_t startTime;

    for (int i = 0; i < 13; i++)
    {
        // Store the starting time
        duration = 0;
        startTime = clock();

        maxSubSum4(vectorArray[i]);

        //Compute the number of milliseconds that passed since the starting time
        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;
    }
}