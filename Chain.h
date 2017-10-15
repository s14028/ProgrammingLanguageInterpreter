#include <initializer_list>
#include <vector>
#include <functional>

namespace pattern
{

template <typename Input>
class Chain
{
	std::vector<std::function<bool(T)>> vector;
public:
	Chain(std::initializer_list<T> list) : vector(list)
	{
	}

	Input operator()(Input input)
	{
		for(T& t : vector)
		{
			bool b = t(input);

			if(b)
				return input;
		}
		return input;
	}


};
}
