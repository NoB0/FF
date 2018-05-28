#ifndef ORMAX_H
#define ORMAX_H

#include "../interpret/Expression.h"
#include "Or.h"

namespace fuzzy {
	template <class T>
	class OrMax : public Or<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~OrMax() {};
	};

	template<class T>
	T OrMax<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		if (lEval <= rEval)
			return rEval;
		else
			return lEval;
	}
}

#endif // !ORMAX_H

