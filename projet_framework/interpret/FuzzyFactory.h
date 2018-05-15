#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H


#include "ExpressionFactory.h"
#include "BinaryShadowExpression.h"
#include "UnaryShadowExpression.h"

#include "../fuzzy/Agg.h"
#include "../fuzzy/And.h"
#include "../fuzzy/MamdaniDefuzz.h"
#include "../fuzzy/Not.h"
#include "../fuzzy/Or.h"
#include "../fuzzy/Then.h"
#include "../fuzzy/Is.h"

namespace interpret {
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {
	public:
		FuzzyFactory<T>() {};
		FuzzyFactory<T>(fuzzy::And<T>*, fuzzy::Or<T>*, fuzzy::Agg<T>*, fuzzy::MamdaniDefuzz<T>*, fuzzy::Not<T>*, fuzzy::Then<T>*, fuzzy::Is<T>*);
		virtual ~FuzzyFactory();

		virtual Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newOr(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newThen(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T& , const T& , const T& );
		virtual Expression<T>* newNot(Expression<T>*);
		virtual Expression<T>* newIs(fuzzy::Is<T>*, Expression<T>*);

		virtual void changeAnd(fuzzy::And<T>*);
		virtual void changeOr(fuzzy::Or<T>*);
		virtual void changeThen(fuzzy::Then<T>*);
		virtual void changeAgg(fuzzy::Agg<T>*);
		virtual void changeDeffuz(fuzzy::MamdaniDefuzz<T>*);
		virtual void changeNot(fuzzy::Not<T>*);
		virtual void changeIs(fuzzy::Is<T>*);


	private:
		BinaryShadowExpression<T>* opAnd;
		BinaryShadowExpression<T>* opOr;
		BinaryShadowExpression<T>* agg;
		BinaryShadowExpression<T>* mamdanidefuzz;
		BinaryShadowExpression<T>* then;
		UnaryShadowExpression<T>* opNot;
		UnaryShadowExpression<T>* is;
	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory<T>(fuzzy::And<T>* _and, fuzzy::Or<T>* _or, fuzzy::Agg<T>* _agg, fuzzy::MamdaniDefuzz<T>* _mamdani, fuzzy::Not<T>* _not, fuzzy::Then<T>* _then, fuzzy::Is<T>* _is)
	{
		opAnd = new BinaryShadowExpression<T>(_and);
		opOr = new BinaryShadowExpression<T>(_or);
		agg = new BinaryShadowExpression<T>(_agg);
		mamdanidefuzz = new BinaryShadowExpression<T>(_mamdani);
		then = new BinaryShadowExpression<T>(_then);
		opNot = new UnaryShadowExpression<T>(_not);
		is = new UnaryShadowExpression<T>(_is);
	}

	template<class T>
	FuzzyFactory<T>::~FuzzyFactory()
	{
		delete opAnd;
		delete opOr;
		delete agg;
		delete mamdanidefuzz;
		delete opNot;
		delete then;
		delete is;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(opAnd, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(opOr , l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(then, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(agg, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step)
	{
		fuzzy::MamdaniDefuzz<T>* m = (fuzzy::MamdaniDefuzz<T>*) (mamdanidefuzz->getTarget());
		m->setMin(min);
		m->setMax(max);
		m->setStep(step);

		return ExpressionFactory<T>::newBinary(mamdanidefuzz, l, r);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* e)
	{
		return ExpressionFactory<T>::newUnary(opNot, e);
	}
	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(fuzzy::Is<T>* is, Expression<T>* e)
	{
		return ExpressionFactory<T>::newUnary(is, e);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* o)
	{
		opAnd->setTarget(o);
	}
	template<class T>
	void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* o)
	{
		opOr->setTarget(o);
	}
	template<class T>
	void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* o)
	{
		then->setTarget(o);
	}
	template<class T>
	void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* o)
	{
		agg->setTarget(o);
	}
	template<class T>
	void FuzzyFactory<T>::changeDeffuz(fuzzy::MamdaniDefuzz<T>* o)
	{
		mamdanidefuzz->setTarget(o);
	}
	template<class T>
	void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* o)
	{
		opNot->setTarget(o);
	}
	template<class T>
	void FuzzyFactory<T>::changeIs(fuzzy::Is<T>* o)
	{
		is->setTarget(o);
	}
}
#endif
