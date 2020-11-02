#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    
    int index1 = -1;
    long long maxval1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > maxval1)
        {
            index1 = i;
            maxval1 = (long long)numbers[i];
    
        }
    }

    int index2 = -1;
    long long maxval2 = 0;
    for(int i = 0; i < n; i++)
    {
        if (i != index1 && numbers[i] > maxval2)
        {
            index2 = i;
            maxval2 = (long long)numbers[i];
        }
    }
    
    max_product = maxval1 * maxval2;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
