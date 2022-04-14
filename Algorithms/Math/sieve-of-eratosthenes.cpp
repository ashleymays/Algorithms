/*
	Sieve of Eratosthenes

	Purpose: to get all the prime numbers within a given range

	Time Complexity: O(n log(log(n))
	Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int>& primes)
{
	for (int i = 0; i < primes.size(); ++i)
	{
		cout << primes[i] << ' ';
	}
	cout << endl;
}

void sieveOfEratosthenes(int limit)
{
	// Create a vector of booleans [0,...,limit - 1] 
	// and assign each value to true. We will determine if
	// the indices of the vector are prime or not.
	// For example if prime[5] is true, then 5 is prime.
	vector<bool> primes(limit, true);


	// Start at index 2 because 2 is the first prime number
	for (int i = 2; i * i < limit; ++i)
	{

		// If primes[i] is true, then 'i' is a prime number
		if (primes[i] == true)
		{
			// Assign all multiples of 'i' as false since they are not prime.
			// We can start at i * i because the composite numbers between
			// 'i' and 'i * i' were already assigned false in an earlier pass.
			for (int j = i * i; j < limit; j += i)
			{
				primes[j] = false;
			}
		}
	}

	// Put the prime numbers themselves into an array
	vector<int> primeNums;

	for (int i = 2; i < limit; ++i)
	{
		// if primes[i] is true, then 'i' is a prime number
		if (primes[i] == true)
		{
			primeNums.push_back(i);
		}
	}

	display(primeNums);
}

int main()
{
	int limit = 10;
	sieveOfEratosthenes(limit);


	return 0;
}
