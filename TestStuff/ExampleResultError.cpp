#include <iostream>
#include <pqxx/pqxx>
#include <vector>

static std::vector<int> Primes;
static void AddPrime(int prime);

int main()
{
    try
    {
        pqxx::connection c("host=nuc port=5432 dbname=commands user=postgres password=Giraffes09");
        pqxx::work w(c);
        w.exec("select getprimes()").for_each([] (int prime) { AddPrime(prime); });
        std::cout << Primes.size() << " primes returned from database\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

static void AddPrime(int prime)
{
   Primes.push_back(prime);
}
