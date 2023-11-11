#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <gmpxx.h>


void PrintMessage(std::string msg)
{
    std::cout << msg << "\n";
}

int main(int argc, char** argv)
{
    mpz_t exp;
    mpz_init_set_ui(exp, 2);
    int Limit = 17;
    mpz_t n;
    mpz_init(n);
    mpz_t result;
    mpz_init(result);
    mpz_t one;
    mpz_init_set_ui(one, 1);
    int probability = 30;
    long i = 0;
    int LoopCtr = 0;
    int start = 1;
    std::vector<int> Primes;
    std::vector<int> MersennePrimes;

    for(int j = 1 ; j <= Limit ; j++)
    {
        i = ((1 << start) - 1);
        //i++;
        mpz_init_set_ui(n, i);
       
        bool Prime = mpz_probab_prime_p(n, probability) == 2;

        if (Prime)
        {
            Primes.push_back(i);
            mpz_pow_ui(result, exp, i);
            mpz_sub(result, result, one);

            Prime = mpz_probab_prime_p(result, probability) == 2;

            if (Prime)
            {
                MersennePrimes.push_back(i);
                std::stringstream ss;
                ss << "On iteration " << j << ", 2 to the power of " << n << " -1 is " << result << " is a mersenne";
                PrintMessage(ss.str());
            }
        }
        start++;
    } 

    std::stringstream ss;
    ss << MersennePrimes.size() << " mersenne primes up to the limit " << Limit << " generated\n";
    
    PrintMessage(ss.str());

    std::copy(MersennePrimes.begin(), MersennePrimes.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::string s;
    std::getline(std::cin, s);
    return 0;
}
