#include <vector>
#include <unordered_map>
#include <math.h>
    
std::vector<int> getPrimes(int N) {
    std::vector<bool> isPrime(N+1, true);
    std::vector<int> primes;
    
    for (int i=2; i<=N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<=N; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}


int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    if (N == 1) return 1;
    long long int n = static_cast<long long int>(N);
    std::vector<int> primes = getPrimes(sqrt(n));

    
    std::unordered_map<int, int> primeFactorCount;
    for (int prime:primes) {
        if (prime > n) break;
        if (n % prime == 0) {
            primeFactorCount[prime] = 1;
            n /= prime;
            while (n > 1 && n % prime == 0) {
                primeFactorCount[prime] += 1;
                n /= prime;
            }
        }
    }
    
    if(n > 1)
        primeFactorCount[n] = 1;
    
    int ans = 1;
    for (auto pair:primeFactorCount) {
        //std::cout << pair.first << ":" << pair.second << std::endl;
        ans *= (pair.second+1);
    }

    return ans;
}
