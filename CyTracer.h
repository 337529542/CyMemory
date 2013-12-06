#ifndef __Tracer_H__
#define __Tracer_H__
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>

class CyTracer
{
private:
	class Entry
	{
	public:
		Entry (char const * file, int line)
			: _file (file), _line (line)
		{}
		Entry ()
			: _file (0), _line (0)
		{}
		char const * File () const { return _file; }
		int Line () const { return _line; }
	private:
		char const * _file;
		int _line;
	};

	class Lock
	{
	public:
		Lock (CyTracer & tracer)
			: _tracer (tracer)
		{
			_tracer.lock ();
		}
		~Lock ()
		{
			_tracer.unlock ();
		}
	private:
		CyTracer & _tracer;
	};



public:
	CyTracer ();
	~CyTracer ();
	void Add (void * p, char const * file, int line);
	void Remove (void * p);
	void Dump ();

	static bool Ready;

private:
	void lock () { _lockCount++; }
	void unlock () { _lockCount--; }

private:
	typedef std::map<void *, Entry>::iterator iterator;
	std::map<void *, Entry> _map;
	int _lockCount;
};

#endif

