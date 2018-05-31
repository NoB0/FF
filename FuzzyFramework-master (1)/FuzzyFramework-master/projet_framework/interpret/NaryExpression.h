#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include "Expression.h"
#include <vector>

namespace interpret {
	template <class T>
	class NaryExpression {
	public:
		NaryExpression() {};
		virtual ~NaryExpression() {};

		virtual T evaluate(std::vector<Expression<T>*>*) const = 0;

	};
}

#endif // NARYEXPRESSION_H
