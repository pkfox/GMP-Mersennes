#include "MersennePrimes.h"
#include <sstream>
#include <chrono>
#include <vector>
#include <map>

#ifdef _WIN32
#include <windows.h>
#endif

MersennePrimes::MersennePrimes() : CheckPrimality(true), StartRange(0), EndRange(0), LoopIndex(0) {
    mpz_init_set_ui(this->One, 1);
    mpz_init_set_ui(this->Pow2Value, 0);
    mpz_init_set_ui(this->Pow2MinusOneValue, 0);
}

// ctor accepting a start and end range
// and a boolean indicating whether to apply a primality check.
MersennePrimes::MersennePrimes(int StartRange, int EndRange, bool CheckPrimality) : MersennePrimes() {
    this->StartRange = StartRange;
    this->EndRange = EndRange;
    this->CheckPrimality = CheckPrimality;
}

// Populates a vector of integers containing mersenne primes.
void MersennePrimes::GenerateListOfMersennes() {
    mpz_init_set_ui(this->CurrentPrime, this->StartRange);
    this->GetNextPrime();
    this->AnnounceRunDetails();
    this->isMersennePrime = false;

    std::stringstream ss;
    ss << "Starting with prime " << this->LoopIndex;
    Utils::PrintMessage(ss.str());

    while (this->LoopIndex <= this->EndRange) {
        this->StartOfCalculation = std::chrono::steady_clock::now();

        // Raise 2 ^ this->LoopIndex
        mpz_ui_pow_ui(this->Pow2Value, this->Two, this->LoopIndex);

        // Subtract 1
        mpz_sub(this->Pow2MinusOneValue, this->Pow2Value, this->One);

        ss.str("");
        ss << (CheckPrimality ? "Executing" : "Skipping") << " primality check";
        Utils::PrintMessage(ss.str());
        ss.str("");

        this->PrimeProbability = this->CheckPrimality ? mpz_probab_prime_p(this->Pow2MinusOneValue, this->Probability) : 2;
        this->isMersennePrime = this->PrimeProbability > 0;

        if (this->isMersennePrime) {
            this->MPrimes.push_back(this->LoopIndex);
            this->PowerValue = mpz_get_str(NULL, 10, this->Pow2MinusOneValue);

            ss << this->BuildMersenneMessage();
            Utils::PrintMessage(ss.str());
            ss.clear();
            ss.str("");

            this->EndOfCalculation = std::chrono::steady_clock::now();
            this->CalculateDuration();

            PGMersenne pgm(this->LoopIndex, this->PowerValue, this->PrimeProbability, this->Duration);
            this->RetVal = pgm.EditMersenne();

            ss << "Row id " << this->RetVal << " updated";
            Utils::PrintMessage(ss.str());
        }

        this->GetNextPrime();
    }
}

void MersennePrimes::GetNextPrime() {
    mpz_nextprime(this->CurrentPrime, this->CurrentPrime);
    this->LoopIndex = static_cast<unsigned long int>(mpz_get_ui(this->CurrentPrime));
}

std::vector<int> MersennePrimes::GetMPrimes() {
    return this->MPrimes;
}

void MersennePrimes::SetStartRange(unsigned long int StartRange) {
    this->StartRange = StartRange;
}

void MersennePrimes::SetEndRange(unsigned long int EndRange) {
    this->EndRange = EndRange;
}

void MersennePrimes::SetPrimalityCheck(bool CheckPrimality) {
    this->CheckPrimality = CheckPrimality;
}

void MersennePrimes::AnnounceRunDetails() {
    std::stringstream ss;
    ss << "Searching for Mersenne primes for range " << this->StartRange << " -> " << this->EndRange;
    Utils::PrintMessage(ss.str());
}

void MersennePrimes::CalculateDuration() {
    std::stringstream ss;
    std::chrono::seconds Seconds = std::chrono::duration_cast<std::chrono::seconds>(this->EndOfCalculation - this->StartOfCalculation);
    this->Duration = std::chrono::hh_mm_ss(Seconds);
    std::string DurationString = pqxx::string_traits<std::chrono::hh_mm_ss<std::chrono::seconds>>::to_string(this->Duration);
    ss << "Primality Calculation for " << this->CurrentPrime << " took " << DurationString;
    Utils::PrintMessage(ss.str());
}

// Cross-platform helper to format exponent
static std::string formatExponent(int exponent) {
#ifdef _WIN32
    return "^" + std::to_string(exponent);
#else
    const std::map<char, std::string> super = {
        {'0', "⁰"}, {'1', "¹"}, {'2', "²"}, {'3', "³"}, {'4', "⁴"},
        {'5', "⁵"}, {'6', "⁶"}, {'7', "⁷"}, {'8', "⁸"}, {'9', "⁹"},
        {'-', "⁻"}
    };
    std::string expStr = std::to_string(exponent);
    std::string result;
    for (char c : expStr) {
        auto it = super.find(c);
        if (it != super.end()) result += it->second;
        else result += c;
    }
    return result;
#endif
}

// Build a user-friendly Mersenne message
std::string MersennePrimes::BuildMersenneMessage() const {
    std::ostringstream ss;
    std::string expStr = "2" + formatExponent(this->LoopIndex);

    ss << "((" << expStr << ") - 1) has " << this->PowerValue.length() << " digit";
    if (this->PowerValue.length() > 1) 
        ss << "s";
    
    ss << " and is " << PrimeStatus::GetStatusMessage(PrimeProbability);

    return ss.str();
}
