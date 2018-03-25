// projet_framework.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "interpret\Expression.h"
#include "interpret\ValueModel.h"
#include "interpret\BinaryExpression.h"
#include "interpret\BinaryExpressionModel.h"
#include "interpret\UnaryExpression.h"
#include "interpret\UnaryExpressionModel.h"
#include "fuzzy\AndMin.h"
#include "fuzzy\AndMult.h"
#include "fuzzy\ThenMin.h"
#include "fuzzy\ThenMult.h"
#include "fuzzy\OrMax.h"
#include "fuzzy\OrPlus.h"
#include "fuzzy\AggMax.h"
#include "fuzzy\AggPlus.h"
#include "fuzzy\NotMinus1.h"
#include "fuzzy\CogDefuzz.h"
#include "fuzzy\IsTriangle.h"
#include<iostream>
#include <assert.h>

void testBinaryExpression() {

	interpret::ValueModel<int> l(1);
	interpret::ValueModel<int> r(3);

	fuzzy::AndMin<int> andMin;
	interpret::ValueModel<int> valueAndMin = andMin.evaluate(&l, &r);
	assert(valueAndMin.evaluate() == 1);

	fuzzy::AndMult<int> andMult;
	interpret::ValueModel<int> valueAndMult = andMult.evaluate(&l, &r);
	assert(valueAndMult.evaluate() == 3);

	fuzzy::ThenMin<int> thenMin;
	interpret::ValueModel<int> valueThenMin = thenMin.evaluate(&l, &r);
	assert(valueThenMin.evaluate() == 1);

	fuzzy::ThenMult<int> thenMult;
	interpret::ValueModel<int> valueThenMult = thenMult.evaluate(&l, &r);
	assert(valueThenMult.evaluate() == 3);

	fuzzy::OrMax<int> orMax;
	interpret::ValueModel<int> valueOrMax = orMax.evaluate(&l, &r);
	assert(valueOrMax.evaluate() == 3);

	fuzzy::OrPlus<int> orPlus;
	interpret::ValueModel<int> valueOrPlus = orPlus.evaluate(&l, &r);
	assert(valueOrPlus.evaluate() == 4);

	fuzzy::AggMax<int> aggMax;
	interpret::ValueModel<int> valueAggMax = aggMax.evaluate(&l, &r);
	assert(valueAggMax.evaluate() == 3);

	fuzzy::AggPlus<int> aggPlus;
	interpret::ValueModel<int> valueAggPlus = aggPlus.evaluate(&l, &r);
	assert(valueAggPlus.evaluate() == 4);

	interpret::BinaryExpressionModel<int> binExp(&l, &r, &andMin);
	interpret::ValueModel<int> valueBinExp = binExp.evaluate();
	assert(valueBinExp.evaluate() == 1);

}

void testUnaryExpression() {
	interpret::ValueModel<int> exp(2);

	fuzzy::NotMinus1<int> notMinus1;
	interpret::ValueModel<int> valueNotMinus1 = notMinus1.evaluate(&exp);
	assert(valueNotMinus1.evaluate() == -1);
}
void testFactory() {
	fuzzy::NotMinus1<int> opNot;
	fuzzy::AndMin<int> opAnd;
	fuzzy::OrMax<int> opOr;
	fuzzy::ThenMin<int> opThen;
	fuzzy::CogDefuzz<int> opDefuzz;
	//fuzzy expession factory
	FuzzyExpressionFactory<int> f(&opNot, &opAnd, &opOr, &opThen, &opOr, &opDefuzz);
	//membership function
	fuzzy::IsTriangle<int> poor(-5, 0, 5);
	fuzzy::IsTriangle<int> good(0, 5, 10);
	fuzzy::IsTriangle<int> excellent(5, 10, 15);
	fuzzy::IsTriangle<int> cheap(0, 5, 10);
	fuzzy::IsTriangle<int> average(10, 15, 20);
	fuzzy::IsTriangle<int> generous(20, 25, 30);
	//values
	Value service(, 0);
	Value food(0);
	Value tips(0);
	Expression *r =
		f.NewAgg(
			f.NewAgg(
				f.NewThen(
					f.NewIs(&service, &poor),
					f.NewIs(&tips, &cheap)
				),
				f.NewThen(
					f.NewIs(&service, &good),
					f.NewIs(&tips, &average)
				)
			),
			f.NewThen(
				f.NewIs(&service, &excellent),
				f.NewIs(&tips, &generous)
			)
		);
	//defuzzification
	Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);
	//apply input
	float s;
	while (true)
	{
		std::cout << "service : "; cin >> s;
		service.SetValue(s);
		cout << "tips -> " << system->Evaluate() << endl;
	}
}

int main()
{
	testBinaryExpression();
	testUnaryExpression();

	return 0;
}

