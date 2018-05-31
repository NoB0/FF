#ifndef OR_H
#define OR_H

#include "../interpret/Expression.h"

namespace fuzzy {
	template <class T>
	class Or : public interpret::BinaryExpression<T> {
	public:
		virtual ~Or() {};

	};
}

#endif // !OR_H

