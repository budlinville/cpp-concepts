#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// Return the sum of two elements
template<class T>
T Add(T x, T y) {
    return x + y;
}


 // Returns the sum of array elements
template<class T>
T ArraySum(T *pArr, int size) {
   T sum = (T)0;
   for (int i = 0; i < size; i++) {
       sum += pArr[i];
   }
   return sum;
}


// Return the largest element in the array
template<class T>
T Max(T *pArr, int size) {
    T max = pArr[0];
    for (int i = 1; i < size; i++) {
        max = pArr[i] > max ? pArr[i] : max;
    }
    return max;
}


// Return the smallest and largest element in a pair
template<class T>
std::pair<T,T> MinMax(T *pArr, int size) {
    T max = pArr[0];
    T min = pArr[0];
    for (int i = 1; i < size; i++) {
        max = pArr[i] > max ? pArr[i] : max;
        min = pArr[i] < min ? pArr[i] : min;
    }
    return std::pair<T,T>(min, max);
}


int main() {
    std::cout << Add(8, 9) << std::endl;
    std::cout << Add(7.5, 4.2) << std::endl;

    int *arr1 = new int[3] {5,6,7};
    float *arr2 = new float[3] {5.1,6.4,7.2};
    std::cout << ArraySum(arr1, 3) << std::endl;
    std::cout << ArraySum(arr2, 3) << std::endl;


    std::cout << Max(arr1, 3) << std::endl;
    std::cout << Max(arr2, 3) << std::endl;

    std::cout << "(" << MinMax(arr1, 3).first << ", " << MinMax(arr1, 3).second << ")" << std::endl;
    std::cout << "(" << MinMax(arr2, 3).first << ", " << MinMax(arr2, 3).second << ")" << std::endl;

    return 0;
}