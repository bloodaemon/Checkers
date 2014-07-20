#include <cstddef>
#include "ActionQueue.h"

namespace CheckersSzeto
{
	using DataStructureSzeto::LinkedQueue;

	using DataStructureSzeto::Node;
	
	ActionStack::ActionStack()
	{
		top = NULL;

		length = 0;
	}

	ActionStack::ActionStack(const ActionStack& stackObject)
	{

	}
}