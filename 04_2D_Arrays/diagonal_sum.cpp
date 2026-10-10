#include <iostream>
using namespace std;

int diag_sum(int arr[][4], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += arr[i][i];
        if(i!=cols-i-1){
            sum += arr[i][cols-i-1];
        }
    }
    return sum;
}

int main()
{
    int arr[4][4] = {
        {1, 2, 3, 4},
        {6, 7, 8, 9},
        {1, 1, 1, 1},
        {2, 2, 2, 2}};
    cout << diag_sum(arr, 4, 4);
    return 0;
}