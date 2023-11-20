#include "PGMersenne.h"

PGMersenne::PGMersenne(int primepower, std::string mersenneprime)
{
    this->Primepower = primepower;
    this->Mersenneprime = mersenneprime;
    this->ConnectionString.append("host=nuc port=5432 dbname=commands user=postgres password=Giraffes09");
}

int PGMersenne::EditMersenne()
{
    // utils.editmersenne(p_mersenneprime bigint, p_primepower text)
    std::stringstream ss;
    ss << "select editmersenne(" << this->Primepower << "," << "'" << this->Mersenneprime << "'" << ")";
    std::string code = ss.str();
    pqxx::connection Connection = pqxx::connection(this->ConnectionString);
    pqxx::work W{Connection};
    pqxx::result r{W.exec(code)};
    W.commit();
    std::cout << r.affected_rows();
    return r.affected_rows();
}
