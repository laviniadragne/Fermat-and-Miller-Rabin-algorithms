#include <bits/stdc++.h>
#include "algo1.h"
#include "algo2.h"


using namespace std;

#define NUM_TESTS 18
#define NAME_TESTS 30
#define SPECIAL_TESTS 7
#define NO_ITERATIONS 10

bool compare (vector<int> refs, vector<int> out)
{
    if (refs.size() != out.size())
    {
        cout<<refs.size()<<" "<<out.size()<<"\n";
        return false;
    }
    for (int i = 0; i < refs.size(); i++)
    {
        if (refs[i] != out[i])
        {
            cout<<refs[i] << " "<<out[i]<<"\n";
            return false;
        }
    }
    return true;
}

int main()
{

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

        ifstream fin;
        ofstream fout1;
        ofstream fout2;
        ifstream fref;
        // deschid fisierele
        fin.open(input);
        fout1.open(output1);
        fout2.open(output2);
        fref.open(refs);

        printf("\nRunning test %d.......\n", j);

        // deschide input-ul
        // retin input-ul intr-un vector
        // apelez algoritmii pentru vectorul citit
        // retin vectorul care rezulta
        // il scriu in fisierul de output
        // compar vectorul cu cel citit din ref uri
        // afisez mesajul

        vector<int> vect_input, vect_ref;
        int numbers;
        int a;
        fin>>numbers;
        for (int i = 0; i < numbers; i++)
        {
            fin>>a;
            vect_input.insert(vect_input.end(), a);

        }

        fref>>numbers;
        for (int i = 0; i < numbers; i++)
        {
            fref>>a;
            vect_ref.insert(vect_ref.end(), a);

        }

        auto t1 = std::chrono::high_resolution_clock::now();
        vector<int> vect_out1 = filter_non_prime1(vect_input, NO_ITERATIONS);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        cout<<"Time for Fermat test: "<<duration1<<" microseconds"<<"\n";


        auto t3 = std::chrono::high_resolution_clock::now();
        vector<int> vect_out2 = filter_non_prime2(vect_input, NO_ITERATIONS);
        auto t4 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
        cout<<"Time for Miller-Rabin test: "<<duration2<<" microseconds"<<"\n";

        fout1<<vect_out1.size()<<"\n";
        for(int i = 0; i < vect_out1.size(); i++)
        {
                fout1<<vect_out1[i]<<" ";
        }
        fout1<<"\n";

        bool ok = compare(vect_ref, vect_out1);
        if (ok)
        {
            cout<<"Test PASSED for Fermat!\n";
        }
        else
        {
            cout<<"Test FAILED for Fermat!\n";
        }

        fout2<<vect_out2.size()<<"\n";
        for(int i = 0; i < vect_out2.size(); i++)
        {
                fout2<<vect_out2[i]<<" ";
        }
        fout2<<"\n";

        ok = compare(vect_ref, vect_out2);
        if (ok)
        {
            cout<<"Test PASSED for Miller-Rabin!\n";
        }
        else
        {
            cout<<"Test FAILED for Miller-Rabin!\n";
        }

        cout<<"\n"<<"Time difference: "<<(duration1-duration2)<<" microseconds"<<"\n";

        // inchid fisierele
        fin.close();
        fout1.close();
        fout2.close();
        fref.close();

}
    return 0;
}
