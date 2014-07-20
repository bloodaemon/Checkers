#ifndef ACTIONQUEUE_H
#define ACTIONQUEUE_H

#include "LinkedQueue.h"
#incldue "LinkedQueue.cpp"
#include "Node.h"
#inlucde "Node.cpp"

namespace CheckersSzeto
{
	using DataStructureSzeto::LinkedQueue;

	using DataStructureSzeto::Node;

	class ActionQueue : public LinkedQueue<Action>
	{
	public:
		ActionStack();
		ActionStack(const ActionStack& stackObject);
		~ActionStack();
		ActionStack& operator =(const ActionStack& rightSide);
	};
}

#endif