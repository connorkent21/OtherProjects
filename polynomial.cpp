//Connor Kent


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "polynomial.hpp"


Polynomial::Polynomial(int A[], int size1)
{
	size = size1;
	coeff.resize(size);
	for(int i = 0; i < size; i++)
	{
		coeff[i] = A[i];
	}
}

Polynomial::Polynomial()
{

	size = (rand() % 10) + 1;
	coeff.resize(size);
	for(int i = 0; i < size; i++)
	{
		coeff[i] = (rand() % 100);
	}
}

Polynomial::Polynomial(string fileName)
{
	ifstream fin(fileName.c_str());
	if(!fin)
	{
		size = 1;
		coeff[0] = -1;
	}
	else
	{
		
		fin >> size;
		coeff.resize(size);
		for(int i = 0; i < size; i++)
		{
			fin >> coeff[i];
		}
	}
}


void Polynomial::add(const Polynomial& second)
{
	if(size < second.size)
	{
		size = second.size;
		coeff.resize(size);
	}
	for(int i = 0; i < second.size; i++)
	{
		coeff[i] += second.coeff[i];
	}
}

void Polynomial::sub(const Polynomial& second)
{
	if(size < second.size)
	{
		size = second.size;
		coeff.resize(second.size);
		
	}

	for(int i = 0; i < second.size; i++)
	{
		coeff[i] -= second.coeff[i];
	}
}


void Polynomial::printPoly()
{
	for(int i = 0; i < size; i++)
	{
		cout << coeff[i] << endl;
	}
}


void Polynomial::getSize()
{
	cout << size << endl;
}

void Polynomial::mul(const Polynomial& second)
{
	
	vector<int> holderArr;
	holderArr.resize(((coeff.size()) + second.coeff.size() - 1));
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < second.size; j++)
		{
			holderArr[i+j] += coeff[i]*second.coeff[j];	
		}
		

	}
	size = holderArr.size();
	coeff.resize(size);
	for(int i = 0; i < size; i++)
	{
		coeff[i] = holderArr[i];
	}


}


int main()
{
	//initialize the random generator
	srand(time(0));
	
	////////////////////////////////////
	//Add function test Case 1 (data constructor added with a randomly
	//generated polynomial)
	cout << "Add Function: case1" << endl << endl;
	int arr[3] = {1,2,3};

	Polynomial test1(arr, 3);
	Polynomial test2;
	cout << "first Poly: " << endl;
	test1.printPoly();
	cout << endl << "second Poly: " << endl;
	test2.printPoly();
	test1.add(test2);
	cout << endl << "Added: " << endl;
	test1.printPoly();
	
	
	//Add fucntion test case 2 (add a larger degree poly to a smaller poly)
	cout << endl << endl << "Add Function: case2" << endl << endl;
	int arr1[3] = {3,4,5};
	int arr2[6] = {2,5,3,6,2,4};
	Polynomial test3(arr1, 3);
	Polynomial test4(arr2, 6);
	cout << "first Poly: " << endl;
	test3.printPoly();
	cout << endl << "second Poly: " << endl;
	test4.printPoly();
	cout << endl << "Added: " << endl;
	test3.add(test4);
	test3.printPoly();
	
	
	//Add function test case 3 (add two randomly generated polynomials)
	cout << endl << endl << "Add Function: case3" << endl << endl;
	Polynomial test5;
	Polynomial test6;
	cout << "first Poly: " << endl;
	test5.printPoly();
	cout << endl << "second Poly: " << endl;
	test6.printPoly();
	cout << endl << "Added: " << endl;
	test5.add(test6);
	test5.printPoly();
	
	
	////////////////////////////////////
	//Sub function test case 1 (data constructor poly subtracted from randomly 
	//randomly generated poly)
	cout << endl << endl << "Sub Function: case1" << endl << endl;
	int subArr[4] = {3,6,2,1};
	Polynomial test7(subArr, 4);
	Polynomial test8;
	cout << "first Poly: " << endl;
	test7.printPoly();
	cout << endl << "second Poly: " << endl;
	test8.printPoly();
	cout << endl << "subtracted: " << endl;
	test7.sub(test8);
	test7.printPoly();
	
	
	//Sub function test case 2 (subtract a higher degree poly from a lower one)
	cout << endl << endl << "Sub Function: case2" << endl << endl;
	int subArr1[3] = {4,6,1};
	int subArr2[6] = {1,7,4,2,7,9};
	Polynomial test9(subArr1, 3);
	Polynomial test10(subArr2, 6);
	cout << "first Poly: " << endl;
	test9.printPoly();
	cout << endl << "second Poly: " << endl;
	test10.printPoly();
	cout << endl << "subtracted: " << endl;
	test9.sub(test10);
	test9.printPoly();
	
	
	//Sub function test case 3 (subtract two randomly generated polys from 
	//each other)
	cout << endl << endl << "Sub function: case3" << endl << endl;
	Polynomial test11;
	Polynomial test12;
	cout << "first Poly: " << endl;
	test11.printPoly();
	cout << endl << "second Poly: " << endl;
	test12.printPoly();
	cout << endl << "subtracted: " << endl;
	test11.sub(test12);
	test11.printPoly();
	
	
	
	////////////////////////////////////
	//Mul function test case 1 (data constructor multiplied with a randomly
	//generated poly)
	cout << endl << endl << "Mul function: case1" << endl << endl;
	int mulArr[3] = {3,7,2};
	Polynomial test13(mulArr, 3);
	Polynomial test14;
	cout << "first Poly: " << endl;
	test13.printPoly();
	cout << endl << "second Poly: " << endl;
	test14.printPoly();
	cout << endl << "Multiplied: " << endl;
	test13.mul(test14);
	test13.printPoly();
	
	//Mul function test case 2 (Poly generated from file multiplied with a 
	//random poly)
	cout << endl << endl << "Mul function: case2" << endl << endl;
	string polyIn = "polyInput.txt";
	Polynomial test15(polyIn);
	Polynomial test16;
	cout << "first Poly: " << endl;
	test15.printPoly();
	cout << endl << "second Poly: " << endl;
	test16.printPoly();
	cout << endl << "Multiplied: " << endl;
	test15.mul(test16);
	test15.printPoly();
	
	
	//Mul function test case 3 (two randoms polys multiplied together)
	cout << endl << endl << "Mul function: case3" << endl << endl;
	Polynomial test17;
	Polynomial test18;
	cout << "first Poly: " << endl;
	test17.printPoly();
	cout << endl << "second Poly: " << endl;
	test18.printPoly();
	cout << endl << "Multiplied: " << endl;
	test17.mul(test18);
	test17.printPoly();
		
}


/*

OUTPUTS:

Add Function: case1

first Poly:
1
2
3

second Poly:
13
74
47
44
78
80
22
81
44
76

Added:
14
76
50
44
78
80
22
81
44
76


Add Function: case2

first Poly:
3
4
5

second Poly:
2
5
3
6
2
4

Added:
5
9
8
6
2
4


Add Function: case3

first Poly:
89
14
74
78
84

second Poly:
84
50
8
80
8
52

Added:
173
64
82
158
92
52


Sub Function: case1

first Poly:
3
6
2
1

second Poly:
77
90
9
70
15
72
74
36
37
91

subtracted:
-74
-84
-7
-69
-15
-72
-74
-36
-37
-91


Sub Function: case2

first Poly:
4
6
1

second Poly:
1
7
4
2
7
9

subtracted:
3
-1
-3
-2
-7
-9


Sub function: case3

first Poly:
94
72
14
9
32
49
21
24

second Poly:
81
71
73
49
99
26
97

subtracted:
13
1
-59
-40
-67
23
-76
24


Mul function: case1

first Poly:
3
7
2

second Poly:
73
83
46

Multiplied:
219
760
865
488
92


Mul function: case2

first Poly:
1
2
3
4

second Poly:
86
69
54
86
64
47
49
65
10
26

Multiplied:
86
241
450
745
674
649
679
560
475
437
342
118
104


Mul function: case3

first Poly:
85

second Poly:
59
52
94
61
73
43
94

Multiplied:
5015
4420
7990
5185
6205
3655
7990

--------------------------------
Process exited after 0.2186 seconds with return value 0
Press any key to continue . . .


*/



