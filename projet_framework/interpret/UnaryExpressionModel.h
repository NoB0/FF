#ifndef UNARY_EXPRESSION_MODEL_H
#define UNARY_EXPRESSION_MODEL_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "NullException.h"

namespace interpret {
	template <class T>
	class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T> {
	public:
		UnaryExpressionModel() {};
		UnaryExpressionModel(Expression<T>*, UnaryExpression<T>*);
		virtual ~UnaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*) const;

	private:
		Expression<T>* operand;
		UnaryExpression<T>* ope;
	};

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* ope):
		operand(operand),ope(ope)
	{
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (ope == NULL)
			throw new NullException("null operator");

		return evaluate(operand);
	}
	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
	{
		if (ope == NULL)
			throw new NullException("null operator");

		return ope->evaluate(o);
	}
}
#endif // ! UNARY_EXPRESSION_MODEL_H

