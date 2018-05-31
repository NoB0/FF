#ifndef NOTMINUS1_H
#define NOTMINUS1_H

#include "../interpret/Expression.h"
#include "Not.h"

namespace fuzzy {
	template <class T>
	class NotMinus1 : public Not<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*) const;
		virtual ~NotMinus1() {};

	};

	template<class T>
	T NotMinus1<T>::evaluate(interpret::Expression<T>* e) const
	{
		T v = e->evaluate();
		return 1 - v;
	}
}
#endif // !NOTMINUS1_H

