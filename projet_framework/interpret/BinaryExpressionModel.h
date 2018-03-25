#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace interpret {
	template <class T>
	class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
	public :
		BinaryExpressionModel(Expression<T>*, Expression<T>*, BinaryExpression<T>*);

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
	T BinaryExpressionModel<T>::evaluate() const  /////// ajouter throw exception null
	{
		if (left != nullptr && right != nullptr)  
			return evaluate(left, right);
	}
	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (op != nullptr)
			return op->evaluate(l, r);
	}
}

#endif // !BINARY_EXPRESSION_MODEL_H
