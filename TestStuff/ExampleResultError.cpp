#include <iostream>
#include <pqxx/pqxx>
#include <vector>

int main()
{
    std::vector<int> Primes;
    try
    {
        // Connect to the database.  In practice we may have to pass some
        // arguments to say where the database server is, and so on.
        // The constructor parses options exactly like libpq's
        // PQconnectdb/PQconnect, see:
        // https://www.postgresql.org/docs/10/static/libpq-connect.html
        pqxx::connection c("host=nuc port=5432 dbname=commands user=postgres password=Giraffes09");

        // Start a transaction.  In libpqxx, you always work in one.
        pqxx::work w(c);

        // work::exec1() executes a query returning a single row of data.
        // We'll just ask the database to return the number 1 to us.
        pqxx::result r = w.exec("select getprimes()");
        r.for_each([&Primes](int prime) { Primes.push_back(prime); });
        std::cout << Primes.size() << " primes returned from database\n";
        //	
        // Commit your transaction.  If an exception occurred before this
        // point, execution will have left the block, and the transaction will
        // have been destroyed along the way.  In that case, the failed
        // transaction would implicitly abort instead of getting to this point.
      //  w.commit();

        // Look at the first and only field in the row, parse it as an integer,
        // and print it.
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

