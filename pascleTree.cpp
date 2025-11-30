#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1, 1);
    for (int i = 2; i <= rowIndex; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            row[j] += row[j - 1];
        }
    }

    return row;
}

int main()
{

    vector<int> result = getRow(3);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}