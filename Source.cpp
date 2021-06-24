#include "Header.h"

int main()
{
	GasCylinder_Target* a = new GasCylinder_Adapter(new GasCylinder_Adaptee(1, 2, 3));
	cout << a->GetData() << endl;
	cout << a->CalculateDp(1000, 100) << endl;
	a->ModifMass(100);
	cout << a->GetData() << endl;
	return 0;
}