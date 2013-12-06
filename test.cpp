#include <stdio.h>

#include "CyMemory.h"

#include <Windows.h>

class A : public CyMemoryAllocator
{
public:
	A()
	{
		printf("A construct \n");
	}

	~A()
	{
		printf("A destruct \n");
	}

	void foo()
	{
		
	}
};



int main()
{
	printf("start \n");

	//A a;
	//a.foo();
	A *a = CY_ARRAY_NEW(A)[2];
	a->foo();
	CY_ARRAY_DELETE(a);

	//delete a;

	printf("end \n");

	system("pause");
	return 0;
}