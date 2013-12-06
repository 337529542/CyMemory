#ifndef __CyMemoryAllocator_H__
#define __CyMemoryAllocator_H__

#include "CyTracer.h"

extern CyTracer gNewTracer;

class CyMemoryAllocator
{
public:

	static void* operator new (size_t size, const char* file, int line)
	{
		void* p = malloc(size);
		if (CyTracer::Ready)
			gNewTracer.Add(p, file, line);
		return p;
	}

	static void operator delete(void* p, const char* file, int line)
	{
		if (CyTracer::Ready)
			gNewTracer.Remove(p);
		free(p);
	}

	static void* operator new (size_t size)
	{
		void* p = malloc(size);
		if (CyTracer::Ready)
			gNewTracer.Add(p, "?", 0);
		return p;
	}

	static void operator delete(void* p)
	{
		if (CyTracer::Ready)
			gNewTracer.Remove(p);
		free(p);
	}

	static void* operator new [](size_t size, const char* file, int line)
	{
		void* p = malloc(size);
		if (CyTracer::Ready)
			gNewTracer.Add(p, file, line);
		return p;
	}

	static void operator delete[](void* p, const char* file, int line)
	{
		if (CyTracer::Ready)
			gNewTracer.Remove(p);
		//cout <<"delete[](void* p, const char* file, int line)" <<endl;
		free(p);
	}

	static void* operator new[] (size_t size)
	{
		void* p = malloc(size);
		if (CyTracer::Ready)
			gNewTracer.Add(p, "?", 0);
		return p;
	}

	static void operator delete[](void* p)
	{
		if (CyTracer::Ready)
			gNewTracer.Remove(p);
		//cout << "delete[](void* p)"<<endl;
		free(p);
	}
};

#endif