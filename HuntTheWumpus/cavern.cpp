#include "cavern.h"
#include <algorithm>
#include <sstream>
using namespace std;

Cavern::Cavern(){
}

Cavern::~Cavern(){
}

bool Cavern::LinkTo(Cavern* _link_to)
{
	if(_link_to  == this || _link_to == nullptr)
		return false;
	if(IsLinked(_link_to))
		return false;
	linked_caverns.push_back(_link_to);
	_link_to->linked_caverns.push_back(this);
	return true;
}

int Cavern::LinkedSize() const
{
	return linked_caverns.size();
}

Cavern* Cavern::operator[](int n)
{
	return linked_caverns.at(n);
}

const Cavern* Cavern::operator[](int n) const
{
	return linked_caverns.at(n);
}


bool Cavern::IsLinked(Cavern* _link_to) const
{
	auto it_find = find(linked_caverns.begin(), linked_caverns.end(), _link_to);
	if(it_find == linked_caverns.end())
		return false;
	return true;
}

bool Cavern::IsLinked(int n) const
{
	for (vector<Cavern*>::size_type i = 0; i < linked_caverns.size(); i++)
	{
		if(linked_caverns[i]->serial == n)
			return true;
	}
	return false;
}

int Cavern::getSerial() const
{
	return serial;
}

void Cavern::setSerial(int n)
{
	serial = n;
}

string Cavern::Display() const
{
	string display;
	stringstream stream;
	stream << "The cavern is linked with cavern#";
	for (vector<Cavern*>::size_type i = 0; i < linked_caverns.size(); i++)
	{
		stream << linked_caverns[i]->serial << " ";
	}
	display = stream.str();
	return display;
}
