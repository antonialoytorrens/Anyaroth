#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class AnyarothError : public logic_error
{
public:
	AnyarothError(const string& m) : logic_error("An 'Anayroth Error' of type " + m) {}
};
