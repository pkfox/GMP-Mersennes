#include "PGMersenne.h"


PGMersenne::PGMersenne():PrimeProbabilityText(""),MersenneResult(""),Mersenne(0),Probability(0)
{
}

PGMersenne::PGMersenne(mpir_ui Mersenne, std::string Result, int Probability)
{
	this->Mersenne = Mersenne;
	this->MersenneResult = Result;
	this->Probability = Probability;
	this->PrimeProbabilityText = PrimeStatus::GetStatus(Probability);

	this->MP.Prime = Mersenne;
	this->MP.Result = Result;
	this->MP.PrimeProbabilityText = this->PrimeProbabilityText;
}

size_t PGMersenne::EditMersenne()
{
	size_t RetVal = -1;
	try
	{
		if (!this->PGConnection.is_open())
		{
			Utils::PrintMessage("Connection is closed");
			return -1;
		}

		this->PGResult = this->PGTransaction.exec_params("select editmersenne($1,$2,$3)",this->Mersenne, this->MersenneResult, this->PrimeProbabilityText);
		this->PGTransaction.commit();
		RetVal = this->PGResult[0][0].as<size_t>();
		return RetVal;
	}
	catch (std::exception const& ex)
	{
		std::cout << ex.what();
	}
	return 0;
}

void PGMersenne::GetData(std::vector<int> & Primes)
{
	if (!this->PGConnection.is_open())
	{
		Utils::PrintMessage("Connection is closed");
		return;
	}
	
	this->PGResult = this->PGTransaction.exec("select getprimes()");
	
	for (auto const& row : this->PGResult)
		for (auto const& field : row)
			Primes.push_back(field.as<int>());

	this->PGTransaction.commit();
}
