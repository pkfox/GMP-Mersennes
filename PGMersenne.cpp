#include "PGMersenne.h"

PGMersenne::PGMersenne(int Mersenne, std::string MersenneResult, int Probability)
{
	this->Mersenne = Mersenne;
	this->MersenneResult = MersenneResult;
	this->Probability = Probability;
	this->PrimeProbabilityText = PrimeStatus::GetStatus(Probability);
}

size_t PGMersenne::EditMersenne()
{
	size_t RetVal = -1;
	try
	{
		if (!this->PGConnection.is_open())
		{
			std::cout << "Connection is closed\n";
			return -1;
		}

		this->PGConnection.prepare("editmersenne", "select editmersenne($1,$2,$3)");
		pqxx::transaction txn(this->PGConnection);

		pqxx::result r(txn.exec_prepared("editmersenne",this->Mersenne,this->MersenneResult,this->PrimeProbabilityText));
		txn.commit();
		RetVal = r[0][0].as<size_t>();
		return RetVal;
	}
	catch (std::exception const& ex)
	{
		std::cout << ex.what();
	}
	return 0;
}
