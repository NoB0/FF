#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H

#include "BinaryExpression.h"

namespace interpret {
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression(Expression<T>*);
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual void setTarget(Expression<T>*);
	private:
		UnaryExpression<T>* target;
	};
	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(Expression<T>* t):
		target(t)
	{
	}
	template<class T>
	inline T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target != null)
			return target.evaluate(l, r);
	}
	template<class T>
	void BinaryShadowExpression<T>::setTarget(Expression<T>* o)
	{
		target = o;
	}
}

#endif // !BINARY_SHADOW_EXPRESSION_H

