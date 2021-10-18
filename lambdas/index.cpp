#include <iostream>
#include <iterator>
#include <vector>

// THIS DOESNT COMPILE... SHOULD REWORK

template<typename T, typename Iterator>
void execute_with_lambdas(T a, T b, Iterator begin, Iterator end) {
    T Max = [](T a, T b) {
        return a > b ? a : b;
    };

    bool Greater = [](T a, T b) {
        return a > b;
    };

    bool Less = [](T a, T b) {
        return a < b;
    };

    std::pair<T,T> MinMax = [](Iterator b, Iterator e) {
        auto min = *b;
        auto max = *b;
        for (const auto &it = b; it != e; ++it) {
            min = min < *it ? min : *it;
            max = max > *it ? max : *it;
        }
        return std::pair<T,T>(min, max);
    };

    std::cout << "Max(a,b): " << Max(a,b) << std::endl;
    std::cout << "Greater(a,b): " << Greater(a,b) << std::endl;
    std::cout << "Less(a,b): " << Less(a,b) << std::endl;
    std::cout << "MinMax(...): " << MinMax(begin, end) << std::endl;
}

int main() {
    std::vector<int> intVector { 2, 3, 5, 6 };
    int a = 2, b = 3;
    execute_with_lambdas(a, b, intVector.begin(), intVector.end());


    return 0;
}

// their function object equivalents