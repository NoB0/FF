#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "..\\projet_framework\interpret\ExpressionFactory.h"

namespace interpret {
	template <class T>
	class FuzzyFactory: public ExpressionFactory<T> {
	public:
		virtual Expression<T>* newAnd(Expression<T>*, Expression<T>*) const;
		virtual Expression<T>* newOr(Expression<T>*, Expression<T>*) const;
		virtual Expression<T>* newThen(Expression<T>*, Expression<T>*) const;
		virtual Expression<T>* newAgg(Expression<T>*, Expression<T>*) const;
		virtual Expression<T>* newDeffuz(Expression<T>*, Expression<T>*) const;
		virtual Expression<T>* newNot(Expression<T>*) const;
		virtual Expression<T>* newIs(Is, Expression<T>*) const;
	};
	
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) const
	{
		return newBinary(and,l,r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>*, Expression<T>*) const
	{
		return NULL;
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>*, Expression<T>*) const
	{
		return NULL;
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>*, Expression<T>*) const
	{
		return NULL;
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDeffuz(Expression<T>*, Expression<T>*) const
	{
		return NULL;
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>*) const
	{
		return NULL;
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Is, Expression<T>*) const
	{
		return NULL;
	}
}
#endif