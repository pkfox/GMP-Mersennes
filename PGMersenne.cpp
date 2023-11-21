#include "PGMersenne.h"

PGMersenne::PGMersenne(int primepower, std::string mersenneprime)
{
    this->Primepower = primepower;
    this->Mersenneprime = mersenneprime;
    this->ConnectionString.append("host=nuc port=5432 dbname=commands user=postgres password=Giraffes09");
}

std::size_t PGMersenne::EditMersenne()
{
    // utils.editmersenne(p_mersenneprime bigint, p_primepower text)
  //  this->PGConnection = pqxx::connection(this->ConnectionString);
    std::stringstream ss;
    ss << "select editmersenne(" << this->Primepower << "," << "'" << this->Mersenneprime << "'" << ")";
    std::string code = ss.str();
    pqxx::connection Connection = pqxx::connection(this->ConnectionString);
   
    if (!Connection.is_open())
    {
        std::cout << "Connection is closed\n";
        return -1;
    }
   
    // this->PGConnection = Connection;
    pqxx::work W{Connection};
    pqxx::result r{W.exec(code)};
    W.commit();
    return r.affected_rows();
}
