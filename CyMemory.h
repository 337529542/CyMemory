#ifndef __CyMemory_H__
#define __CyMemory_H__

#include "CyMemoryAllocator.h"

#define CY_NEW(type) new(__FILE__, __LINE__) type
#define CY_DELETE(obj) delete obj
#define CY_ARRAY_NEW(type) new(__FILE__, __LINE__) type
#define CY_ARRAY_DELETE(obj) delete[] obj

/*usage
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

	};

	A *a = CY_ARRAY_NEW(A)[2];
	CY_ARRAY_DELETE(a);

	A *a = CY_NEW(A)(...);
	CY_DELETE(a);

	�����˳��󣬻�������Ŀ¼������ml.txt�ļ���
	�����������ڼ����gNewTracer.dump���������ɴ��ļ���
*/

#endif