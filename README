Nume si grupa: Dragne Lavinia-Stefana, 324CAa

					  Analiza Algoritmilor
					Tema 1 - Etapa a II - a

Continut:

- Acest fisier README.md

- algo1.h
	Un header cu un set minimal de functii care implementeaza filter_non_prime()
	pentru algoritmul de identificare Fermat
- algo2.h
	Un header cu un set minimal de functii care implementeaza filter_non_prime()
	pentru algoritmul de identificare Miller-Rabin
- algo1.cpp
	Implementarea algoritmului Fermat
- algo2.cpp
	Implementarea algoritmului Miller-Rabin


Makefile
	Acesta contine regulile:
	- build:
		compileaza toate executabilele
	- run_tests
		ruleaza checker-ul pe toate testele de input, generand fisierele
		de output
	- algo1.o
		compileaza executabilul care va testa solutia pentru algoritmul
		Fermat
	- algo2.o:
		compileaza executabilul care va testa solutia pentru algoritmul
		Miller-Rabin
	- checker.o:
		compileaza checker-ul, care va genera fisierele de output

	- clean
	
Pentru a rula scrieti in terminal make ./run_tests.

Folder 'in' cu testele de intrare (25 teste)

	- Fiecare test este numit "testID.in", unde ID reprezintă numărul
	testului (e.g. test0.in)
	- Fiecare test este structurat în felul următor:
		Pe prima linie:
		* N (int - numărul de elemente din secvență)
      		* N numere întregi (reprezentabile pe 32 biți)
	- Testele de la 1-5: contin un singur numar ce trebuie testat si se afla in
	intervalul [1, 1000000].
	- Testele de la 6-10: numarul de numere testate este maxim 20, dintre care cel
	mult 9 sunt generate random si restul sunt sigur prime, fiind obtinute din
	Ciurul lui Eratostene. Numerele sunt din intervalul [1, 100000].
	- Testele de la 11-15: sunt testate maxim 25000 numere, din intervalul 
	[10000, 1000000], dintre care cel mult 5000 generate random.
	- Testele de la 16-18: numarul de numere testate ajunge la 600000, maxim 10000
	generate random, fiind din intervalul [100000, 10000000].
	- Testele de la 19-25: sunt testate, pe rand, numerele de tip Carmichael, mai mici
	ca 10000, acestea reprezentand un caz special pentru algoritmul Fermat.

Folder 'out' cu testele de ieșire

	- Fiecare test este numit "testID.out", unde ID reprezintă numărul
	testului (e.g. test0.out).
	- Fiecare test conține M - numărul de elemente prime urmat de 
    	secvența propriu-zisă de numerele prime extrase din secvența originală.
	- In directorul 'out' se regasesc alte 2 directoare 'out1' si 'out2'. Acestea
    	contin testele de iesire pentru algoritmul Fermat, respectiv Miller-Rabin.

Folder 'ref' cu testele de referinta

	- Fiecare test este numit "testID.ref", unde ID reprezintă numărul
	testului (e.g. test0.out).
	- Fiecare test conține M - numărul de elemente prime urmat de 
    	secvența propriu-zisă de numerele prime extrase din secvența originală.
	- Fiecare test.ref este folosit de checker pentru a verifica corectitudinea
	rezultatelor fiecarui algoritm.

generator.cpp:

	Codul sursă al generatorului de teste folosit
	Acesta genereaza toate numerele prime, pana la un n dat ca si parametru,
	folosind implementarea Ciurului lui Eratostene. De asemenea, sunt generate
	m numere random din intervalul [p, n]. Functia generate_tests intoarce un vector
	de numere pentru testele de input. Aceasta combina numere random si numere prime,
	densitatea acestora in vector fiind primita prin intermediul parametrului m.
	Pozitiile pe care sunt introduse numerele prime sunt generate random, prin intermediul
	variabilei fact. Numerele prime sunt adaugate atat de la inceputul Ciurului lui
	Eratostene, cat si de la mijloc si final, variind astfel dimensiunea lor.
	Prin intermediul functiei generate_refs si folosind un algoritm clasic de identificare
	al numerelor prime, sunt generate testele de referinta, cu raspunsul corect pentru
	fiecare rulare. 
	In final, sunt adaugate, in fisierele de input, si toate numerele Carmichael, mai mici
	decat 10000 cunoscute.

checker.cpp:
	
	Codul sursa pentru checker-ul folosit.
	Compar rezultatele din fisierele de out, ale fiecarui algoritm, cu cele din ref si
	in cazul in care acestea sunt identice, afisez mesajul "PASSED", in caz contrar, afisez
	"FAILED". Numarul de iteratii, k, pentru fiecare algoritm in parte, defineste acuratetea
	rezultatelor si influenteaza timpii de rulare. Cu cat este ales un k mai mare, cu atat
	rezultatele sunt mai sigure. Pentru acest set de test am ales numarul de iteratii ca fiind
	10, acesta oferindu-mi un timp de rulare de 14,328s, pentru toate testele si rezultatele
	corecte, comparate cu cele din ref.


Referinte:
	Secvente de cod preluate de la:
		https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/
		https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/


	











