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

	程序退出后，会在运行目录下生成ml.txt文件。
	或者在运行期间调用gNewTracer.dump，即可生成此文件。
*/

#endif