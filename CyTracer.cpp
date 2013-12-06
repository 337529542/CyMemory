#include "CyTracer.h"

using namespace std;

bool CyTracer::Ready = false;

CyTracer::CyTracer():_lockCount(0)
{
	Ready = true;
}

CyTracer::~CyTracer()
{
	Ready = false;
	Dump();
}

void CyTracer::Dump()
{
	FILE *fp;
	fp = fopen("ml.txt", "w");
	if (_map.size() != 0)
	{
		char buf[1000];
		sprintf(buf, "%d memory leaks detected\n", _map.size());
		fputs(buf, fp);
		//cout << _map.size() << " memory leaks detected" << endl;
		for (iterator itor = _map.begin(); itor != _map.end(); ++itor)
		{
			char const* file = itor->second.File();
			int line = itor->second.Line();
			//cout << file << ", " << line << endl;
			sprintf(buf, "%s, %d\n", file, line);
			fputs(buf, fp);
		}
	}
	fclose(fp);
}

void CyTracer::Add(void *p, const char *file, int line)
{
	if (_lockCount > 0)
		return;
	CyTracer::Lock lock(*this);
	_map[p] = Entry(file, line);
}

void CyTracer::Remove(void *p)
{
	if (_lockCount > 0)
		return;

	CyTracer::Lock lock(*this);

	iterator itor = _map.find(p);
	if (itor != _map.end())
		_map.erase(itor);
}

CyTracer gNewTracer;