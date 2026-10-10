#include <iostream>
#include <vector>
using namespace std;

void array_product(int nums[], int size) {
    vector<int> ans(size, 1);

    int prefix = 1;
    for (int i = 0; i < size; i++) {
        ans[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = size - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    cout << "Product of array except itself: ";
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {7, 1, 2, 6, 4, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    array_product(nums, size);
    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// void array_product(int nums[], int size) {
//     vector<int> ans(size, 1);
//     vector<int> prefix(size, 1);
//     vector<int> suffix(size, 1);

//     // Build prefix product
//     for (int i = 1; i < size; i++) {
//         prefix[i] = prefix[i - 1] * nums[i - 1];
//     }

//     // Build suffix product
//     for (int i = size - 2; i >= 0; i--) {
//         suffix[i] = suffix[i + 1] * nums[i + 1];
//     }

//     // Multiply prefix and suffix
//     for (int i = 0; i < size; i++) {
//         ans[i] = prefix[i] * suffix[i];
//     }

//     // Print result
//     cout << "Product of array except itself: ";
//     for (int i = 0; i < size; i++) {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int nums[] = {7, 1, 2, 6, 4, 3};
//     int size = sizeof(nums) / sizeof(nums[0]);

//     array_product(nums, size);

//     return 0;
// }
