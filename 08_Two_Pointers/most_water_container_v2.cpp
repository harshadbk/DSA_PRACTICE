#include <iostream>
#include <algorithm>  // for min and max
using namespace std;

void most_water(int heights[], int size) {
    int max_water = 0;
    int i = 0;
    int j = size - 1;

    while (i < j) {
        int w = j - i;
        int h = min(heights[i], heights[j]);
        int current_water = w * h;
        max_water = max(current_water, max_water);

        if (heights[i] < heights[j])
            i++;
        else
            j--;
    }

    cout << max_water << endl;
}

int main() {
    int heights[] = {7, 1, 2, 6, 4, 3};
    int size = 6;
    most_water(heights, size);
    return 0;
}