#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

/******************************************************************************
    Same as basics.cpp, but using reference types instead of pointers
    - Note strange syntax for references to arrays : ..., T (&var)[3], ....
    - Note that size must be explicit for reference types
*******************************************************************************/

/**********************
 * Reference Functions
 **********************/

 // Returns the sum of array elements
template<class T>
T ArraySum(T (&pArr)[3], int size) {
   T sum = (T)0;
   for (int i = 0; i < size; i++) {
       sum += pArr[i];
   }
   return sum;
}


// Return the largest element in the array
template<class T>
T Max(T (&pArr)[3], int size) {
    T max = pArr[0];
    for (int i = 1; i < size; i++) {
        max = pArr[i] > max ? pArr[i] : max;
    }
    return max;
}


// Return the smallest and largest element in a pair
template<class T>
std::pair<T,T> MinMax(T (&pArr)[3], int size) {
    T max = pArr[0];
    T min = pArr[0];
    for (int i = 1; i < size; i++) {
        max = pArr[i] > max ? pArr[i] : max;
        min = pArr[i] < min ? pArr[i] : min;
    }
    return std::pair<T,T>(min, max);
}

/**********************************
 * Specializations for const char*
 **********************************/
template<>
const char* ArraySum(const char* (&pArr)[3], int size) {
    char* concat = new char[0];
    for (int i = 0; i < size; i++) {
        char* updatedConcat = new char[strlen(concat) + strlen(pArr[i])];
        strcpy(updatedConcat, concat);
        strcat(updatedConcat, pArr[i]);
        concat = updatedConcat;
    }
    return concat;
}

template<>
const char* Max(const char* (&pArr)[3], int size) {
    const char* max = pArr[0];
    for (int i = 1; i < size; i++) {
        max = strcmp(pArr[i], max) >= 0 ? pArr[i] : max;
    }
    return max;
}

template<>
std::pair<const char*,const char*> MinMax(const char * (&pArr)[3], int size) {
    const char* max = pArr[0];
    const char* min = pArr[0];
    for (int i = 1; i < size; i++) {
        max = strcmp(pArr[i], max) >= 0 ? pArr[i] : max;
        min = strcmp(pArr[i], min) <= 0 ? pArr[i] : min;
    }
    return std::pair<const char*,const char*>(min, max);
}

/**********************************
 * Specializations for std::string
 **********************************/
template<>
std::string ArraySum(std::string (&pArr)[3], int size) {
    std::string concat = "";
    for (int i = 0; i < size; i++) {
        concat = concat + pArr[i];
    }
    return concat;
}

template<>
std::string Max(std::string (&pArr)[3], int size) {
    std::string max = pArr[0];
    for (int i = 1; i < size; i++) {
        max = max.compare(pArr[i]) >= 0 ? max : pArr[i];
    }
    return max;
}

template<>
std::pair<std::string,std::string> MinMax(std::string (&pArr)[3], int size) {
    std::string max = pArr[0];
    std::string min = pArr[0];
    for (int i = 1; i < size; i++) {
        max = max.compare(pArr[i]) >= 0 ? max : pArr[i];
        min = min.compare(pArr[i]) <= 0 ? min : pArr[i];
    }
    return std::pair<std::string,std::string>(min, max);
}


int main() {
    int arr1[] {5,6,7};
    float arr2[] {5.1,6.4,7.2};
    
    std::cout << ArraySum(arr1, 3) << std::endl;
    std::cout << ArraySum(arr2, 3) << std::endl;


    std::cout << Max(arr1, 3) << std::endl;
    std::cout << Max(arr2, 3) << std::endl;

    std::cout << "(" << MinMax(arr1, 3).first << ", " << MinMax(arr1, 3).second << ")" << std::endl;
    std::cout << "(" << MinMax(arr2, 3).first << ", " << MinMax(arr2, 3).second << ")" << std::endl;

    // Specializations for const char*
    const char* arr_cc[] {"aa", "bb", "cc"};
    std::cout << ArraySum(arr_cc, 3) << std::endl;
    std::cout << Max(arr_cc, 3) << std::endl;
    std::cout << "(" << MinMax(arr_cc, 3).first << ", " << MinMax(arr_cc, 3).second << ")" << std::endl;

    // Specializations for std::string
    std::string arr_str[] {"aa", "bb", "cc"};
    std::cout << ArraySum(arr_str, 3) << std::endl;
    std::cout << Max(arr_str, 3) << std::endl;
    std::cout << "(" << MinMax(arr_str, 3).first << ", " << MinMax(arr_str, 3).second << ")" << std::endl;

    return 0;
}