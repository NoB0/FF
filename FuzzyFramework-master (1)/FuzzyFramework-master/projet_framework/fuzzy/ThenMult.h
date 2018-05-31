#ifndef THENMULT_H
#define THENMULT_H

#include "../interpret/Expression.h"
#include "Then.h"

namespace fuzzy {
	template <class T>
	class ThenMult : public Then<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~ThenMult() {};

	};

	template<class T>
	T ThenMult<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		return lEval * rEval;
	}
}
#endif // !THENMULT_H

