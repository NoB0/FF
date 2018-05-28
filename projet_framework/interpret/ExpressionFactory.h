#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"
#include <set>

namespace interpret {
	template <class T>
	class ExpressionFactory {
	public:
		~ExpressionFactory<T>();
		virtual Expression<T>* hold(Expression<T>*);
		virtual Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		virtual Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		virtual Expression<T>* newNary(NaryExpression<T>*, std::vector<Expression<T>*>*);
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
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* exp)
	{
		memory.insert(exp);
		return exp;
	}
	template<class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* l)
	{
		return hold(new UnaryExpressionModel<T>(l,ope));
	}
	template<class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
	{
		return hold(new BinaryExpressionModel<T>(l, r, ope));
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>*>* operands)
	{
		return hold(new NaryExpressionModel<T>(ope, operands));
	}

}

#endif 