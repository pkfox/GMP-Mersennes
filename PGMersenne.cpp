#include "PGMersenne.h"

PGMersenne::PGMersenne(int primepower, std::string mersenneprime,int PrimeProbability):PrimeProbability(0), Primepower(0)
{
    this->Primepower = primepower;
    this->Mersenneprime = mersenneprime;
    this->PrimeProbability = PrimeProbability;
}

std::size_t PGMersenne::EditMersenne()
{
   if (!this->PGConnection.is_open())
   {
       std::cout << "Connection is closed\n";
       return -1;
   }

   this->PGConnection.prepare("editmersenne", "select editmersenne($1,$2,$3)");
   pqxx::transaction txn(this->PGConnection);
   pqxx::result r(txn.exec_prepared("editmersenne",this->Primepower,txn.esc(this->Mersenneprime),txn.esc(PrimeStatus::GetStatus(this->PrimeProbability))));
   txn.commit();
   return r.affected_rows();
}

