#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& v, int l, int m, int r) {
    vector<int> L, R;
    int s1 = m - l + 1;
    int s2 = r - m;

    // Create left and right sub vectors of v
    for (int i = 0; i < s1; ++i) L.push_back(v[l + i]);
    for (int j = 0; j < s2; ++j) R.push_back(v[m + 1 + j]);

    // i keeps track of left vector index, j of right vector index, and k of v index
    int i = 0, j = 0;
    int k = l;

    // Merge step
    while (i < s1 && j < s2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            ++i;
        }

        else
        {
            v[k] = R[j];
            ++j;
        } 
        ++k;
    }

    // Insert remaining elements if any from L/R vectors
    while (i < s1)
    {
        v[k] = L[i];
        ++i;
        ++k;
    }

    while (j < s2)
    {
        v[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Split vector into subarrays, eventually of size 1
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        merge(v, l, m, r);
    }
}

void quickSort(vector<int>& v, int l, int r) {
    int i = l, j = r;
    int m = (l + r) / 2;
    int pivot = v[m];

    // Swap elements to sort
    while (i <= j)
    {
        // Look for element greater than pivot on right side and less than pivot on left side
        while (v[i] < pivot) ++i;
        while (v[j] > pivot) --j;

        if (i <= j)
        {
            swap(v[i], v[j]);
            ++i;
            --j;
        }
    }

    // Recursively quicksort left and right side of v
    if (l < j) quickSort(v, l, j);
    if (i < r) quickSort(v, i, r);
}

void printVector(vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << endl;
}

int main() {
    // Test
    vector<int> v1 = {3, 9, 1, 2, 0, 10, 6};
    vector<int> v2 = v1;

    mergeSort(v1, 0, v1.size() - 1);
    quickSort(v2, 0, v1.size() - 1);

    printVector(v1);
    printVector(v2);
    return 0;
}