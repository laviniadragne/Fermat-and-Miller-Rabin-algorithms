#include <bits/stdc++.h>
#include<time.h>

using namespace std;

#define NUM_TESTS 18
#define NAME_TESTS 30
#define SPECIAL_TESTS 7
#define CST1 1
#define CST2 2
#define CST3 3
#define CST4 5
#define CST5 6
#define CST6 10
#define CST7 11
#define CST8 25
#define CST9 100
#define CST10 500
#define CST11 10000
#define CST12 1000000
#define CST13 0
#define CST14 15
#define CST15 500000
#define CST16 800000
#define CST17 900000
#define CST18 100000
#define CST19 600000
#define CST20 10000000


// genereaza toate numerele prime pana
// la un n, dat ca si parametru
// folosind ciurul lui eratostene
std::vector<int> ciur(int n)
{
    vector<int> num(n + 1, 0);
    vector<int> prime;
    num[0] = num[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        // daca e prim il alaug in vector
        if (!num[i])
        {
            prime.push_back(i);
            for (int j = i + i; j <= n; j += i)
                num[j] = 1;
        }
    }
    return prime;
}

// genereaza m numere random in intervalul [p, n]
std::vector<int> random_num(int m, int p, int n)
{
    std::vector <int> ran_num;

    for(int i = 0; i < m; i++)
    {

        ran_num.push_back(p + rand() % (n - p));
    }

    return ran_num;

}

// amesteca numere prime generate cu ciurul lui Eratostene
// si numere random generate
// in "ran" sunt m numere random in intervalul [p, n], iar in "prime"
// sunt numere mai mici decat n, prime
// voi genera un vector de max_size numere
std::vector<int> generate_tests(int m, int p, int n, int max_size)
{
    std::vector<int> ran = random_num(m, p, n);
    std::vector<int> prime = ciur(n);

    std::vector<int> ret(max_size + 1, 0);

    // fact va reprezenta dupa cate numere generate
    // random voi introduce un numar prim, generat
    // cu sirul lui Eratostene
    int fact = rand() % max_size;
    while (fact)
    {
        ret[fact] = 1;
        ret[max_size - fact - 1] = 1;
        // vreau sa cresc frecventa numerelor prime
        fact = fact / 2;
    }

    int contor_ran = 0;
    int contor_prime = 0;
    int change = 0;
    int change_prime_mijl = 0;
    // numarul de numere prime si de numere generate random
    // trebuie sa fie mai mic decat numarul total de numere
    // de aceea voi alege mereu un m < max_size si
    // m < n - p + 1
    for (int i = 0; i < max_size; i++)
    {
        if (ret[i] == 0 && m != 0 && contor_ran < ran.size())
        {
            ret[i] = ran[contor_ran];
            contor_ran++;
        }
        else
        {
            // adaug numere prime de la inceputul Ciurului lui Eratostene
            if (change == 1)
            {
                if (change_prime_mijl == 0)
                {
                    ret[i] = prime[contor_prime];
                }
                // adaug numere din mijlocul Ciurului lui Eratostene
                else
                {
                    ret[i] = prime[(prime.size() - contor_prime - 1)/2];
                    change_prime_mijl = 0;
                }
                change = 0;
            }
            // adaug numere prime de la finalul Ciurului lui Eratostene
            else
            {
                ret[i] = prime[prime.size() - contor_prime - 1];
                change = 1;
            }
            contor_prime++;
        }

    }

    return ret;

}

// functia verifica daca un numar dat este prim sau nu
bool is_prime (int a)
{
    bool ok = true;
        for (int d = 2; d <= sqrt(a); d++)
        {
                if(a % d == 0)
                {
                    ok = false;
                }
        }
    return ok;
}

// algoritm clasic de testare daca elementele unui
// vector dat ca si parametru sunt prime;
// numerele prime sunt adaugate intr-un vector
// si returnate
std::vector<int> generate_refs(std::vector<int> vect)
{
    std::vector<int> ret;
    bool ok;
    for (int i = 0; i < vect.size(); i++)
    {
            ok = is_prime(vect[i]);
            // e prim il adaug in ref
            if (ok == true)
            {
                ret.insert(ret.end(), vect[i]);
            }
    }
    return ret;
}

int main() {


    int n, m, p, max_size;
    // max_size e numarul de numere verificate
    // numerele se afla in intervalul [p, n]
    // toate numerele prime sunt mai mici decat n
    // m reprezinta numarul de numere random din
    // testele generate
    m = 1;
    p = 1;
    n = 100;
    max_size = 1;
    // vector cu numere de tip Carmichael
    vector<int> v_carmichael{561,  1105,  1729,  2465,  2821,  6601,  8911};
    int last_carmichael = 0;

    for (int j = 1; j <= (NUM_TESTS + SPECIAL_TESTS); j++)
    {
        // input-urile pentru ambii algoritmi
        char input[NAME_TESTS];
        // output-urile pentru ambii algoritmi
        char output1[NAME_TESTS];
        char output2[NAME_TESTS];

        // ref-urile pentru algoritmi
        char refs[NAME_TESTS];

        // formez numele fisierelor
        sprintf(input, "./in/test%d.in", j);
        sprintf(output1, "./out/out1/test%d.out", j);
        sprintf(output2, "./out/out2/test%d.out", j);
        sprintf(refs, "./ref/test%d.ref", j);

        ofstream fin;
        ofstream fout1;
        ofstream fout2;
        ofstream fref;
        // deschid fisierele
        fin.open(input);
        fout1.open(output1);
        fout2.open(output2);
        fref.open(refs);

        if (j > NUM_TESTS)
        {
	    // testele de la 16-25 vor contine numere de tip Carmichael
            // scriu in fisierul de input vectorul de numere Carmichael
            // pe care vor rula algoritmii
            fin<<"1"<<"\n";
            fin<<v_carmichael[last_carmichael]<<" ";
            fin<<"\n";
            last_carmichael++;

	    // numerele Carmichael nu sunt prime
            fref<<"0"<<"\n";

        }

        else
        {
            vector<int> v_in;
            // cazurile de teste generate cu numere din Ciurul lui Eratostene
	    // si numere generate random
            v_in = generate_tests(m, p, n, max_size);

            // scriu in fisierul de input vectorul de numere
            // pe care vor rula algoritmii
            fin<<v_in.size() - 1<<"\n";
            for(int i = 0; i < v_in.size() - 1; i++)
            {
                fin<<v_in[i]<<" ";
            }
            fin<<"\n";

            // generez ref-urile
            vector<int> v_ref = generate_refs(v_in);
            fref<<v_ref.size() - 1<<"\n";
            for(int i = 0; i < v_ref.size() - 1; i++)
            {
                fref<<v_ref[i]<<" ";
            }
            fref<<"\n";

            if (j <= NUM_TESTS)
            {
                // pentru primele 5 teste aleg sa testez pe fiecare test
		// un singur numar, pornind de la numere de 1 cifra
		// pana la numere mai mici ca 1000000
                if (j < CST4 && j != CST1)
                {
                    if (j % 2 == 0)
                        m = CST13;
                    else
                        m = CST1;
                    if (j == CST2)
                    {
                        p = CST10;
                        n = CST11;
                    }
                    if (j > CST2)
                    {
                        p *= CST6;
                        n *= CST6;
                    }
                }
		// pentru testele de la 6-10 voi alege numere din intervalul
		// [1, 100000], dar numarul de numere va fi in [5, 20] si
		// vor fi maxim 9 numere generate random, restul fiind alese
		// din Ciurul lui Eratostene
                    if (j == CST4)
                    {
                        max_size = CST4;
                        m = CST3;
                        p = CST1;
                        n = CST9;
                    }
                    if (j < CST6 && j > CST5)
                    {
                        max_size += CST4;
                        m += CST2;
                        p *= CST6;
                        n *= CST6;
                    }
		    // pentru testele 11-15 voi alege numere din intervalul
		    // [10000, 1000000], maxim 5000 dintre acestea vor fi
		    // random, iar numarul de numere maxim va fi 25000
                    if (j == CST6)
                    {
                        max_size = CST8;
                        m = CST4;
                        p = CST11;
                        n = CST12;
                    }
                    if (j < CST14 && j > CST7)
                    {
                        max_size *= CST6;
                        m *= CST6;
                        p += CST11;
                        n -= CST11;
                    }
		    // pentru testele 16-18 numarul de numere testate 
		    // ajunge si la 600000, maxim 10000 generate random
		    // numerele fiind in intervalul [100000, 10000000]
                    if (j == CST14)
                    {
                        max_size = CST18;
                        m = CST11;
                        p = CST15;
                        n = CST20;
                    }
                    if (j == CST14 + 1)
                    {
                        max_size = CST15;
                        m = CST11;
                        p = CST18;
                        n = CST20;
                    }
                    if (j == CST14 + 2)
                    {
                        max_size = CST19;
                        m = CST11;
                        p = CST18;
                        n = CST20;
                    }
            }
      }

             // inchid fisierele
            fin.close();
            fout1.close();
            fout2.close();
            fref.close();

}


return 0;
}
