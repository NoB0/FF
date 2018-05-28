#ifndef SUGENO_DEFUZZ_H
#define SUGENO_DEFUZZ_H

#include "../interpret/Expression.h"
#include "../interpret/BinaryExpressionModel.h"
#include "../interpret/NaryExpression.h"
#include "SugenoThen.h"

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public interpret::NaryExpression<T> {
	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};

		virtual T evaluate(std::vector<interpret::Expression<T>*>*) const;
	};
	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<interpret::Expression<T>*>* operands) const
	{
		std::vector<interpret::Expression<T>*>::const_iterator it;

		T num = 0;
		T denum = 0;

		for (it = operands->begin(); it != operands->end(); it++)
		{
			interpret::BinaryExpressionModel<T>*  bem = (interpret::BinaryExpressionModel<T>*)  (*it);
			interpret::BinaryShadowExpression<T>* bse = (interpret::BinaryShadowExpression<T>*) bem->getOp();
			SugenoThen<T>* sth = (SugenoThen<T>*) bse->getTarget();
			num += (*it)->evaluate()*sth->getPremiseValue();
			denum += sth->getPremiseValue();
		}

		if (denum != 0)
			return num / denum;
		else
			return 0;
	}
}
#endif // !SUGENO_DEFUZZ_H

