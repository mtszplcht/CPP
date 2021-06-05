#include <iostream>
#include <string>
using namespace std;

class SortExample{
    public:

    static void quick_sort(int* tab, int left, int right);
    static int binary_search(int* tab, int left, int right, int lookUpValue);
    static string print(int* tab, int length);
};