#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H
#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include <set>

namespace interpret {
	template <class T>
	class ExpressionFactory {
	public:
		~ExpressionFactory<T>();
		virtual Expression<T>* hold(Expression<T>*);
		virtual Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*) const;
		virtual Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*) const;
	private:
		std::set<Expression<T>*> memory;
	};

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		for (std::set<Expression<T>*>::iterator it = memory.begin(); it != memory.end(); it++) {
			delete *it;
		}
	}

	template<class T>
	Expression<T> ExpressionFactory<T>::hold(Expression<T>* exp)
	{
		memory.insert(exp);
		return exp;
	}
	template<class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* l) const
	{
		return hold(new UnaryExpressionModel(ope, l);
	}
	template<class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) const
	{
		return hold(new UnaryExpressionModel(ope, l, r);
	}

}

#endif 