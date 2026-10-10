#include <iostream>
using namespace std;

bool isfreqsame(int subfreq[26], int windowFreq[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (subfreq[i] != windowFreq[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int subfreq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        subfreq[s1[i] - 'a']++;
    }

    int windowsize = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        int winInd = 0;
        int idx = i;

        int windowFreq[26] = {0};

        while (winInd < windowsize && idx < s2.length())
        {
            windowFreq[s2[idx] - 'a']++;
            winInd++;
            idx++;
        }
        if (isfreqsame(subfreq, windowFreq))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s = "ab";
    string s2 = "qwerbauio";
    cout << checkInclusion(s, s2);
    return 0;
}