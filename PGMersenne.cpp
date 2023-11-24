#include "PGMersenne.h"

PGMersenne::PGMersenne(MersennePrime mp)
{
    this->Mersenneprime = mp;
    this->Mersenneprime.PrimeProbabilityText = PrimeStatus::GetStatus(mp.PrimeProbability);
}

std::size_t PGMersenne::EditMersenne()
{
    try
    {
        if (!this->PGConnection.is_open())
        {
            std::cout << "Connection is closed\n";
            return -1;
        }

        this->PGConnection.prepare("editmersenne", "select editmersenne($1)");
        pqxx::transaction txn(this->PGConnection);

        pqxx::result r(txn.exec_prepared("editmersenne",this->Mersenneprime));
        txn.commit();
        return r.affected_rows();
    }
    catch (std::exception const &ex)
    {
        std::cout << ex.what();
    }

 /*  pqxx::result r(txn.exec_prepared("editmersenne",this->Mersenneprime));
   txn.commit();
   return r.affected_rows();*/
   return 0;
}