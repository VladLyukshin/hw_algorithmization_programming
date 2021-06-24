#include "Header.h"

int main()
{
	ExchangeRates subject;
	CurrentExchangeRatesDisplay_dollar_euro dol_eu;
	CurrentExchangeRatesDisplay_frank_hryvnia fr_hr;
	setlocale(LC_ALL, "rus");
	dol_eu.subscribe(subject);
	fr_hr.subscribe(subject);
	subject.setExchangeRates(10, 20, 30, 40);
	dol_eu.unsubscribe(subject);
	subject.setExchangeRates(80, 100, 2.5, 90);
	fr_hr.unsubscribe(subject);
	system("pause");
	return 0;
}


