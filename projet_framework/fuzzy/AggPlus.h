#ifndef AGGPLUS_H
#define AGGPLUS_H
#include "Agg.h"

namespace fuzzy {
	template <class T>
	class AggPlus : public Agg<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~AggPlus() {};
	};
	template<class T>
	T AggPlus<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		return lEval + rEval;
	}
}
#endif // !AGGPLUS_H

