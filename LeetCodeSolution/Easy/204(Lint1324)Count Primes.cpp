#include<iostream>
#include<vector>
#include<map>

using namespace std;


/* 
Count the number of prime numbers less than a non-negative number, n.
*/

bool isPrime(int n, vector<int>& primes) {

	//use ~method, check whether this number can be divided by prime numbers smaller than sqrt(n)
	for (auto& prime : primes) {
		if (prime > sqrt(n)) return true;
		if (n % prime == 0) return false;
	}
	return true;
}

int countPrimes(int n) {
	if (n < 3)
	{
		return 0;
	}
	//use this vector to store prime numbers
	vector<int> primes = { 2 };

	// for each number less than n, check whether it`s a prime number
	for (int i = 3; i != n; ++i) {
		
		if (!isPrime(i, primes)) continue;

		//store it in vector if it`s a prime number
		primes.push_back(i);
	}
	//return the size of vector
	return primes.size();
}
