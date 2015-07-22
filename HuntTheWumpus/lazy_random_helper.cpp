#include "lazy_random_helper.h"
#include <cstdlib>
#include <ctime>

namespace lazy{
	namespace random{
		using namespace std;
		int randint(int _max)
		{			
			return rand()%_max;
		}

		void setsrand()
		{
			time_t t = time((time_t*)0);
			srand(t);
		}
	}
}