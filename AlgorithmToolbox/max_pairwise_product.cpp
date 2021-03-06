#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>

//O(n^2)
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;

    for (int first = 0; first < numbers.size(); ++first) {
        for (int second = first + 1; second < numbers.size(); ++second) {
            max_product = std::max((long long)max_product, (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

//O(2*N)
long long MaxPairwiseProductFast(const std::vector<int>& numbers)
{
   int nLargestIndex = -1;
   int n2ndLargestIndex = -1;
   int maxX = 0;
   for (int i = 0; i < numbers.size(); ++i)
   {
       if(maxX < numbers[i])
       {
           maxX = numbers[i];
           nLargestIndex = i;
       }    
   }
   maxX = 0;
   for (int i = 0; i < numbers.size(); ++i)
   {
       if (i != nLargestIndex && maxX < numbers[i])
       {
           maxX = numbers[i];
           n2ndLargestIndex = i;
       }

   }
   return (long long)numbers[nLargestIndex] * numbers[n2ndLargestIndex];


}
//O(1.5n)
long long MaxPairwiseProductFaster(const std::vector<int>& numbers)
{
    int maxValIndex = 0;
    int max2ndValIndex = 1;
    size_t temparraySize = int(ceil(numbers.size() / 2.0));
    std::vector<int> tempArray(temparraySize);
    for (int i = 0; i < numbers.size(); i+=2)
    {
      
        if (numbers[i] > numbers[(i+1) % numbers.size()])
        {
            tempArray[i / 2] = i;
        }
        else
        {
            tempArray[i / 2] = (i+1) % numbers.size();
        }
        if (numbers[maxValIndex] < numbers[tempArray[i / 2]])
        {
            maxValIndex = tempArray[i / 2];
            max2ndValIndex = numbers[i] < numbers[(i + 1) % numbers.size()] ? i : (i + 1) % numbers.size();
        }
        
    }
    for (int i = 0; i < tempArray.size(); ++i)
    {
        if (tempArray[i]!= maxValIndex && numbers[max2ndValIndex] < numbers[tempArray[i]])
            max2ndValIndex = tempArray[i];
    }
    return long long(numbers[max2ndValIndex] * numbers[maxValIndex]);
}


int main() {
    int n = 3;
    srand(unsigned int(time(NULL)));
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) 
    {
        numbers[i] = 500 * rand()/RAND_MAX;
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    std::cout << MaxPairwiseProductFaster(numbers) << "\n";
    return 0;
}
