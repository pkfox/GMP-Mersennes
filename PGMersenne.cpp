#include "PGMersenne.h"

PGMersenne::PGMersenne(int primepower, std::string mersenneprime)
{
    this->Primepower = primepower;
    this->Mersenneprime = mersenneprime;
    this->ConnectionString.append("host=nuc port=5432 dbname=commands user=postgres password=Giraffes09");
}

std::size_t PGMersenne::EditMersenne()
{
    pqxx::connection Connection = pqxx::connection(this->ConnectionString);
    
    if (!Connection.is_open())
    {
        std::cout << "Connection is closed\n";
        return -1;
    }
    
    Connection.prepare("editmersenne", "select editmersenne($1,$2)");
    pqxx::transaction txn(Connection);
 //   pqxx::result r(txn.exec_prepared("editmersenne", this->Primepower,txn.esc(this->Mersenneprime)));
    //r.affected_rows();
    return 0;
}
