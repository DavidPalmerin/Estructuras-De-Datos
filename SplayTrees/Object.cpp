#include <iostream>
#include <string>

class Object
{

public:
	int elem;


	inline std::ostream & operator<<(std::ostream & Str, Object const &v)
	{
		cout << "Hola" << endl;
		return Str;
	}


}