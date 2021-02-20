// C++ program pentru determinarea numerelor prime
// folosind testul Fermat de identificare
#include <bits/stdc++.h>
using namespace std;

vector<int> filter_non_prime1(vector<int> sequence, int k);
long long power1(long long a, unsigned int n, int p);
bool isPrime1(unsigned int n, int k);


// functia adauga si returneaza un vector de
// numere prime, pe baza unui vector dat ca si
// parametru
// k reprezinta numarul de iteratii pentru care
// se aplica algoritmul de identificare Fermat
// pentru fiecare numar testat
vector<int> filter_non_prime1(vector<int> sequence, int k)
{
    vector<int> vect;
    int size = sequence.size();
    for (int i = 0; i < size; i++) {
    // daca numarul testat din secventa e prim il adaug
    // la vector

        if (isPrime1(sequence[i], k)) {
            vect.push_back(sequence[i]);
        }
    }
    return vect;
}

// Functie iterativa pentru a calcula (a^n)%p
long long power1(long long a, unsigned int n, int p)
{
        long long res = 1;
        a = a % p; // Update 'a' daca a >= p

        while (n > 0)
        {
                // Daca n este impar, e inmultit cu rezultatul
                if (n & 1)
                        res = (res * a) % p;

                // n e par
                n = n>>1; // n = n/2
                a = (a * a) % p;
        }
        return res;
}

// Functia intoarce fals daca numarul este compus
// Probabilitatea ca aceasta sa intoarca adevarat si
// numarul testat sa fie prim creste odata cu numarul
// k de iteratii
bool isPrime1(unsigned int n, int k)
{
// Cazuri particulare
if (n <= 1 || n == 4) return false;
if (n <= 3) return true;

// k este numarul de iteratii
while (k > 0)
{
        // Extrag un numar random din intervalul [2..n-2]
        // Se asigura ca n > 4, pentru a exista intervalul
        long long a = 2 + rand()%(n - 4);

        // Mica Teorema a lui Fermat
        if (power1(a, n - 1, n) != 1)
                return false;

        k--;
        }

        return true;
}

