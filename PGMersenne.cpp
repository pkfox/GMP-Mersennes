#include "PGMersenne.h"

namespace pjk
{
	PGMersenne::PGMersenne(PGMersenne& mp)
	{
		this->Mersenne = mp.Mersenne;
		this->MersenneResult = mp.MersenneResult;
		this->Probability = mp.Probability;
		this->PrimeProbabilityText = mp.PrimeProbabilityText;
	}

	PGMersenne::PGMersenne() :PrimeProbabilityText(""), MersenneResult(""), Mersenne(0), Probability(0)
	{
	}

	PGMersenne::PGMersenne(int Mersenne, std::string MersenneResult, int Probability,std::string Duration) :PGMersenne()
	{
		this->Mersenne = Mersenne;
		this->MersenneResult = MersenneResult;
		this->Probability = Probability;
		this->PrimeProbabilityText = PrimeStatus::GetStatus(Probability);
		this->Duration = Duration;
		this->MP.Mersenne = Mersenne;
		this->MP.MersenneResult = MersenneResult;
		this->MP.PrimeProbability = Probability;
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
 
                        
			this->PGResult = this->PGTransaction.exec_params("select editmersenne($1,$2,$3,$4::interval)",
            this->Mersenne,
            this->MersenneResult,
            this->PrimeProbabilityText,
            this->Duration);

			std::string json = this->MP.GetJSON();
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

		this->PGTransaction.exec("select resetprimalitytables()");
		this->PGTransaction.exec_params("select getprimes()")
		.for_each([&Primes](int prime) { Primes.push_back(prime); });
		this->PGTransaction.commit();
	}
}
