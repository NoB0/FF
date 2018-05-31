#ifndef THENMIN_H
#define THENMIN_H

#include "../interpret/Expression.h"
#include "Then.h"

namespace fuzzy {
	template <class T>
	class ThenMin : public Then<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~ThenMin() {};

	};

	template<class T>
	T ThenMin<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		if (lEval >= rEval)
			return rEval;
		else
			return lEval;
	}
}

#endif // !THENMIN_H

