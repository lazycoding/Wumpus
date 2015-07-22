#ifndef _NONCOPY_H__
#define _NONCOPY_H__

class Noncopy
{
public:
	Noncopy(){}
	virtual ~Noncopy(){}
private:
	Noncopy(const Noncopy&);
	Noncopy& operator=(const Noncopy&);
};


#endif // !_NONCOPY_H__
