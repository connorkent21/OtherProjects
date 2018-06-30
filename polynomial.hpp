#include <cstdlib>

using namespace std;


class Polynomial
{
	vector<int> coeff;
	int size;

public:
	Polynomial(int A[], int size1);
	Polynomial();
	Polynomial(string fileName);
	
	void add(const Polynomial& second);
	void sub(const Polynomial& second);
	void mul(const Polynomial& second);
	void printPoly();
	void getSize();
};
