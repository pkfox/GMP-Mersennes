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
	
		typedef MersennePrime x;
		x xx = this->Mersenneprime;

		std::cout << typeid(this->Mersenneprime).name() << "\n";

		pqxx::result r(txn.exec_prepared("editmersenne",xx));
		txn.commit();
		return r.affected_rows();
	}
	catch (std::exception const& ex)
	{
		std::cout << ex.what();
	}
	return 0;
}
