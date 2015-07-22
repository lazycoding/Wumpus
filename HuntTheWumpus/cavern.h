#ifndef _CAVERN_H__
#define	_CAVERN_H__
#include <string>
#include <vector>
#include "danger.h"
#include "ptr.h"

class Cavern
{
public:
	Cavern();
	~Cavern();
	bool LinkTo(Cavern*);
	Cavern* operator[](int n);
	const Cavern* operator[](int n) const;
	int LinkedSize() const;
	int getSerial() const;
	void setSerial(int);
	std::string Display() const;
	bool IsLinked(int n) const;
private:
	bool IsLinked(Cavern*) const;
	std::vector<Cavern*> linked_caverns;
	int serial;
};  
#endif // !_CAVERN_H__
