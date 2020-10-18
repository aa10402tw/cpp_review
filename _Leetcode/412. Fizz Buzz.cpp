/* [Question Description]
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* Soulution: simple I/O  
*/ 
vector<string> fizzBuzz(int n) {
    std::vector<std::string> result(n, "");
    for (int i=1; i<=n; i++) {
        int idx = i -1;
        if ((i%3) == 0 && (i%5) ==0) result[idx] = "FizzBuzz";
        else if ((i%3) == 0) result[idx] = "Fizz";
        else if ((i%5) == 0) result[idx] = "Buzz";
        else result[idx] = std::to_string(i);
    }
    return result;
}
