#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H

#include "Expression.h"
#include "UnaryExpression.h"

namespace interpret {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {
	public:
		UnaryShadowExpression() {};
		UnaryShadowExpression(UnaryExpression<T>*);
		~UnaryShadowExpression();

		virtual T evaluate(Expression<T>*) const;
		virtual void setTarget(UnaryExpression<T>*);
		virtual UnaryExpression<T>* getTarget() const;
	private:
		UnaryExpression<T>* target;
	};

	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* t):
		target(t)
	{
	}

	template<class T>
	UnaryShadowExpression<T>::~UnaryShadowExpression()
	{
		delete target;
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const
	{
		if (target == NULL)
			throw new NullException("null target");
		
		return target->evaluate(o);
	}
	template<class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* o)
	{
		target = o;
	}
	template<class T>
	UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const
	{
		return target;
	}
}

#endif // !UNARY_SHADOW_EXPRESSION_H
