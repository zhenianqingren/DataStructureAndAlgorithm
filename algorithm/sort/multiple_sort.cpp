#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &source, vector<int> &temp, int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j = midIndex + 1, k = startIndex;
    while (i <= midIndex && j <= endIndex)
    {
        if (source[i] > source[j])
            temp[k++] = source[j++];
        else
            temp[k++] = source[i++];
    }
    while (i <= midIndex)
        temp[k++] = source[i++];
    while (j <= endIndex)
        temp[k++] = source[j++];
    for (int m = 0; m < k; m++)
        source[m] = temp[m];
}

void Mergesort(vector<int> &source, vector<int> &temp, int startIndex, int endIndex)
{
    int midIndex;
    if (startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        Mergesort(source, temp, startIndex, midIndex);
        Mergesort(source, temp, midIndex + 1, endIndex);
        Merge(source, temp, startIndex, midIndex, endIndex);
    }
}

int main()
{
    vector<int> source;
    srand(6);
    for (int i = 0; i < 15; i++)
        source.push_back(rand() % 60);
    for (int i = 0; i < 15; i++)
        cout << source[i] << " ";
    cout<<endl;
    vector<int> temp;
    temp.resize(15);
    Mergesort(source, temp, 0, 14);
    for (int i = 0; i < 15; i++)
        cout << source[i] << " ";
    system("pause");
    return 0;
}