#include "C_poly.h"

double Bank_account::balance()
{
	return amount;
}

double Bank_account::balance(double rate)
{
	this->rate = rate;
	return amount+((amount*rate*time)/100);
}
