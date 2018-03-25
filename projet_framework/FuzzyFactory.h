#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "./interpret/ExpressionFactory.h"
#include "fuzzy\Agg.h"
#include "fuzzy\And.h"
#include "fuzzy\MamdaniDefuzz.h"
#include "fuzzy\Not.h"
#include "fuzzy\Or.h"
#include "fuzzy\Then.h"
#include "fuzzy\Is.h"


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
		virtual Expression<T>* newIs(fuzzy::Is, Expression<T>*) const;
		virtual Expression<T>* changeAnd(fuzzy::And) const;
		virtual Expression<T>* changeOr(fuzzy::Or) const;
		virtual Expression<T>* changeThen(fuzzy::Then) const;
		virtual Expression<T>* changeAgg(fuzzy::Agg) const;
		virtual Expression<T>* changeDeffuz(fuzzy::MamdaniDefuzz) const;
		virtual Expression<T>* changeNot(fuzzy::Not) const;
		virtual Expression<T>* changeIs(fuzzy::Is) const;


	private:
		fuzzy::And<T>* and ;
		fuzzy::Or<T>* or ;
		fuzzy::Agg<T>* agg;
		fuzzy::MamdaniDefuzz<T> mamdanidefuzz;
		fuzzy::Not<T>* not;
		fuzzy::Then<T>* then;
		fuzzy::Is<T>*is;
	};
	
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) const
	{
		return newBinary(and,l,r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) const
	{
		return newBinary(or, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) const
	{
		return newBinary(then, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) const
	{
		return newBinary(agg, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDeffuz(Expression<T>* l, Expression<T>* r) const
	{
		return newBinary(mamdanidefuzz, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* e) const
	{
		return newUnary(not, e);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Is is, Expression<T>* e) const
	{
		return newUnary(is,e);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::changeAnd(And o) const
	{
		and.setTarget(o);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::changeOr(Or o) const
	{
		or.setTarget(o);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::changeThen(Then o) const
	{
		then.setTarget(o);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::changeAgg(Agg o) const
	{
		agg.setTarget(o);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::changeDeffuz(MamdaniDefuzz o) const
	{
		mamdanidefuzz.setTarget(o);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::changeNot(Not o) const
	{
		not.setTarget(o);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::changeIs(Is o) const
	{
		is.setTarget(o);
	}
}
#endif