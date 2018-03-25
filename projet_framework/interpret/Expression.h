#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace interpret {
	template <class T>
	class Expression {
	public:
		virtual T evaluate() const = 0;
		virtual ~Expression() {};

	};
}
#endif
