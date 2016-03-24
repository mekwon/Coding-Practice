// ALL ARE SORTING IN LEAST --> GREATEST ORDER
#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort
void bubble_sort(vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) 
    {
        for (int j = 0; j < vec.size() - i - 1; ++j) 
        {
            if (vec[j + 1] < vec[j])
            {
                // Switching without using temporary variable
                vec[j + 1] += vec[j];
                vec[j] = vec[j + 1] - vec[j];
                vec[j + 1] -= vec[j];
            }
        }
    }
}

// Selection Sort
void selection_sort(vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) 
    {
        bool was_found = false;
        int min = vec[i];
        int index = 0;
        for (size_t j = i + 1; j < vec.size(); ++j) 
        {
            if (vec[j] < min) 
            {
                min = vec[j];
                index = j;
                
                // a smaller value has been found, must switch
                was_found = true;
            }
        }
        
        if (was_found)
        {
            vec[index] += vec[i];
            vec[i] = vec[index] - vec[i];
            vec[index] -= vec[i];  
        }
    }
}

// Insertion Sort
void insertion_sort(vector<int>& vec) {
    int j;
    for (size_t i = 0; i < vec.size(); ++i) 
    {
        j = i;
        while (j && (vec[j] < vec[j - 1]))
        {
            // switch values
            vec[j] += vec[j - 1];
            vec[j - 1] = vec[j] - vec[j - 1];
            vec[j] -= vec[j - 1];
            --j;
        }
    }
}

// Quick test
int main() {
    vector<int> vec = {5, 3, 8, 2, 1, 9};
    //bubble_sort(vec);
    //selection_sort(vec);
    //insertion_sort(vec);
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}