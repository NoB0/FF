#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H

#include "UnaryExpression.h"

namespace interpret {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {
	public:
		UnaryShadowExpression(Expression<T>*);
		virtual T evaluate(Expression<T>*) const;
		virtual void setTarget(Expression<T>*);
	private:
		UnaryExpression<T>* target;
	};

	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(Expression<T>* t) :
		target(t)
	{
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const
	{
		if (target != null)
			return target.evaluate(o);
	}
	template<class T>
	void UnaryShadowExpression<T>::setTarget(Expression<T>* o)
	{
		target = o;
	}
}

#endif // !UNARY_SHADOW_EXPRESSION_H
