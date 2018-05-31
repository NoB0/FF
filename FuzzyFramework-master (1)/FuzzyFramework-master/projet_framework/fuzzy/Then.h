#ifndef THEN_H
#define THEN_H

#include "../interpret/Expression.h"

namespace fuzzy {
	template <class T>
	class Then : public interpret::BinaryExpression<T> {
	public:
		virtual ~Then() {};

	};
}

#endif // !THEN_H

