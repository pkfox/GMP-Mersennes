#include <iostream>
#include "PGMersenne.h"


PGMersenne::PGMersenne() :PrimeProbabilityText(""), MersenneResult(""), Mersenne(0), Probability(0)
{
}

PGMersenne::PGMersenne(int Mersenne, std::string MersenneResult, int Probability, std::string Duration) :PGMersenne()
{
	this->Mersenne = Mersenne;
	this->MersenneResult = MersenneResult;
	this->Probability = Probability;
	this->PrimeProbabilityText = PrimeStatus::GetStatus(Probability);
	this->Duration = Duration;
}

size_t PGMersenne::EditMersenne()
{
	size_t RetVal(-1);

	try
	{
		if (!this->PGConnection.is_open())
		{
			Utils::PrintMessage("Connection is closed");
			return -1;
		}
		
		this->Params.append(this->Mersenne);
		this->Params.append(this->MersenneResult);
		this->Params.append(this->PrimeProbabilityText);
		this->Params.append(this->Duration);

		this->PGResult = this->PGTransaction.exec("select editmersenne($1, $2, $3, $4)",this->Params);
		
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

void PGMersenne::GetData(std::vector<int>& Primes)
{
	if (!this->PGConnection.is_open())
	{
		Utils::PrintMessage("Connection is closed");
		return;
	}

	Utils::PrintMessage("Resetting mersenne data");
	this->PGTransaction.exec("select resetmersennedata()");

	Utils::PrintMessage("Retrieving Primes");
	this->PGTransaction.exec("select getprimes()")
		.for_each([&Primes](int prime) { Primes.push_back(prime); });
	this->PGTransaction.commit();
}