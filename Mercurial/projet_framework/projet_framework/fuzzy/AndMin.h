#ifndef ANDMIN_H
#define ANDMIN_H
#include "And.h"

namespace fuzzy {
	template <class T>
	class AndMin : public And<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
	};
	template<class T>
	T AndMin<T>::evaluate(interpret::Expression<T>*l, interpret::Expression<T>*r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		if (lEval >= rEval)
			return rEval;
		else
			return lEval;
	}
}
#endif // !ANDMIN_H

