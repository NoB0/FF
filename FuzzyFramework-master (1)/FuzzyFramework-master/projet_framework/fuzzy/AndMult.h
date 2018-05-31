#ifndef ANDMULT_H
#define ANDMULT_H

#include "../interpret/Expression.h"
#include "And.h"

namespace fuzzy {
	template <class T>
	class AndMult : public And<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~AndMult() {};
	};

	template<class T>
	T AndMult<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		return lEval * rEval;
	}

}
#endif // !ANDMULT_H
