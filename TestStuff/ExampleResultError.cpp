#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include "MersennePrime.h"

static std::vector<int> Primes;
static void AddPrime(int prime);

int main()
{
    try
    {
	int Mersenne(2);
	std::string MersenneResult("3");
	int PrimeProbability(1);
	std::string PrimeProbabilityText("Possibly a Mersenne prime");
	std::string Duration("1H 100S");

	pqxx::params Params(Mersenne);
	Params.append(MersenneResult);
	Params.append(PrimeProbabilityText);
	Params.append(Duration);

    pqxx::connection c("host=beelink port=5432 dbname=commands user=postgres password=Giraffes09");
    pqxx::work w(c);

<<<<<<< HEAD
	pqxx::result PGResult = 
	w.exec("select editmersenne($1,$2,$3,$4)",Params);

        int RetVal = PGResult[0][0].as<int>();
=======
	pqxx::result PGResult = w.exec("select editmersenne($1,$2,$3,$4)",Params);
    int RetVal = PGResult[0][0].as<int>();
>>>>>>> a9eb77f3be0f0d51cbdb9807717e538655eb21e4
	std:: cout << "Result is " << RetVal << "\n";


    w.exec("select getprimes()").for_each([] (int prime) { AddPrime(prime); });
    std::cout << Primes.size() << " primes returned from database\n";
	w.commit();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

static void AddPrime(int prime)
{
   std::cout << prime << "\n";
   Primes.push_back(prime);
}
