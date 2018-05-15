#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H

#include "Expression.h"
#include "BinaryExpression.h"
#include "NullException.h"

namespace interpret {
	template <class T>
	class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
	public :
		BinaryExpressionModel(Expression<T>*, Expression<T>*, BinaryExpression<T>*);

		virtual BinaryExpression<T>* getOp() const;
		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual ~BinaryExpressionModel() {};
	private:
		Expression<T>* left;
		Expression<T>* right;
		BinaryExpression<T>* op;
	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T>* ope):
		left(l),right(r),op(ope)
	{
	}

	template<class T>
	BinaryExpression<T>* BinaryExpressionModel<T>::getOp() const
	{
		return op;
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const  
	{
		if (left == NULL || right == NULL)
			throw new NullException("null operand");
			
		return evaluate(left, right);
	}
	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (op == NULL)
			throw new NullException("null operator");

		return op->evaluate(l, r);
	}
}

#endif // !BINARY_EXPRESSION_MODEL_H
