// Implementare testul de primalitate Miller-Rabin
#include <bits/stdc++.h>
using namespace std;

vector<int> filter_non_prime2(vector<int> sequence, int k);
long long power2(long long a, unsigned int d, int n);
bool miillerTest(int d, int n);
bool isPrime2(int n, int k);

// functia intoarce un vector de numere prime
// pe baza unui vector initial dat
// k reprezinta numarul de iteratii in care
// aplicam testul de primalitate Miller-Rabin
vector<int> filter_non_prime2(vector<int> sequence, int k)
{
    vector<int> vect;
    int size = sequence.size();
    for (int i = 0; i < size; i++) {
    // daca numarul testat din secventa e prim il adaug
    // la vector
        if (isPrime2(sequence[i], k)) {
            vect.push_back(sequence[i]);
        }
    }
    return vect;
}

// Functie iterativa pentru a calcula (a^d)%n
long long power2(long long a, unsigned int d, int n)
{
	long long res = 1;
	a = a % n; // Update 'a' daca a >= n

	while (d > 0)
	{
		// Daca d este impar, a e inmultit cu rezultatul
		if (d & 1)
			res = (res * a) % n;

		// d e par
		d = d>>1; // d = d/2
		a = (a * a) % n;
	}
	return res;
}


// Functia este apelata pentru toate k iteratiile
// Intoarce fals daca n este compus si true, daca
// n este probabil prim
bool miillerTest(int d, int n)
{
	// Aleg un numar random din [2..n-2]
	// n-ul trebuie sa fie > 4
	long long a = 2 + rand() % (n - 4);

	// Calculeaza a^d % n
	long long x = power2(a, d, n);

	if (x == 1 || x == n-1)
	return true;

	// Continui inmultirea lui x
	// cat timp nu este una din conditii
	// indeplinite:
	// (i) d nu este mai mare ca n-1
	// (ii) (x^2) % n nu e 1
	// (iii) (x^2) % n nu e n-1
	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	// este compus
	return false;
}

// Functia intoarce fals daca numarul este compus
// Probabilitatea ca aceasta sa intoarca adevarat si
// numarul testat sa fie prim creste odata cu numarul
// k de iteratii, deci cresterea lui k va influenta si
// acuratetea
bool isPrime2(int n, int k)
{
	// Cazurile speciale
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// d trbuie sa fie impar
	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterez de k ori
	for (int i = 0; i < k; i++)
		if (!miillerTest(d, n))
			return false;

	return true;
}
