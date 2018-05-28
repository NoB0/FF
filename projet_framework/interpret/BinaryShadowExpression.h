#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H

#include "Expression.h"
#include "BinaryExpression.h"
#include "NullException.h"

namespace interpret {
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression() {};
		BinaryShadowExpression(BinaryExpression<T>*);
		~BinaryShadowExpression();

		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual void setTarget(BinaryExpression<T>*);
		virtual BinaryExpression<T>* getTarget();
	private:
		BinaryExpression<T>* target;
	};

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* t):
		target(t)
	{
	}
	template<class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression()
	{
		delete target;
	}
	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target == NULL)
			throw new NullException("null target");

		return target->evaluate(l, r);
	}
	template<class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* o)
	{
		target = o;
	}
	template<class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget()
	{
		return target;
	}
}

#endif // !BINARY_SHADOW_EXPRESSION_H

