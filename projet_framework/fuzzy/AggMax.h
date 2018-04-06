#ifndef AGGMAX_H
#define AGGMAX_H

#include "Agg.h"
#include "../interpret/Expression.h"

namespace fuzzy {
	template <class T>
	class AggMax : public Agg<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~AggMax() {};
	};
	template<class T>
	T AggMax<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		if (lEval <= rEval)
			return rEval;
		else
			return lEval;
	}
}
#endif // !AGGMAX_H

