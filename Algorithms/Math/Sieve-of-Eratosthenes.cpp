/*
	Sieve of Eratosthenes

	Purpose: used to get all the prime numbers under a certain number

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

void sieveOfEratosthenes(int& limit)
{

	vector<bool> primes(limit, true);								// Create a vector of booleans [0,...,limit - 1] and assign each value to true
																	// the indices are the numbers to consider

	for (int i = 2; i * i < limit; ++i)								// start at index 2 because 2 is the first prime number
	{

		if (primes[i] == true)										// if primes[i] is true, then 'i' is a prime number
		{

			for (int j = i * i; j < limit; j += i)					// assign all multiples of i as false since they are not prime
			{														// can start at i * i because the composite numbers between
				primes[j] = false;									// i and i^2 were already assigned false in an earlier pass
			}
		}
	}

	vector<int> primeNums;											// Put the prime numbers themselves into an array
	for (int i = 2; i < limit; ++i)									// Start at index 2 since 2 is the first prime number
	{
		if (primes[i] == true)										// if primes[i] is true, then 'i' is a prime number
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