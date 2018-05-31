#ifndef NARY_SHADOW_EXPRESSION_H
#define NARY_SHADOW_EXPRESSION_H

#include "NaryExpression.h"
#include <vector>

namespace interpret {
	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {
	public:
		NaryShadowExpression() {};
		NaryShadowExpression(NaryExpression<T>*);
		~NaryShadowExpression();

		virtual void setTarget(NaryExpression<T>*);
		virtual NaryExpression<T>* getTarget();
		T evaluate(std::vector<Expression<T>*>*) const;

	private:
		NaryExpression<T>* target;
	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* t):
		target(t)
	{
	}
	template<class T>
	NaryShadowExpression<T>::~NaryShadowExpression()
	{
		delete target;
	}
	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* t)
	{
		target = t;
	}
	template<class T>
	NaryExpression<T>* NaryShadowExpression<T>::getTarget()
	{
		return target;
	}
	template<class T>
	T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*>* operands) const
	{
		if (target == NULL) {
			throw new NullException("null target");
		}

		return target->evaluate(operands);
	}
}
#endif // !NARY_SHADOW_EXPRESSION_H

