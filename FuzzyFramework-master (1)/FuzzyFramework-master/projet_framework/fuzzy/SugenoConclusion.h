#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../interpret/Expression.h"
#include "../interpret/BinaryExpressionModel.h"
#include "../interpret/NaryExpression.h"
#include <vector>

namespace fuzzy
{
	template <class T>
	class SugenoConclusion : public interpret::NaryExpression<T>
	{
	public:
		SugenoConclusion(std::vector<T>*);
		virtual ~SugenoConclusion() {};

		virtual T evaluate(std::vector<interpret::Expression<T>*>* operands) const;

	private:
		const std::vector<T> *coeff;
	};

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(std::vector<T>* coefs) :
		coeff(coefs)
	{
	}

	template <class T>
	T SugenoConclusion<T>::evaluate(std::vector<interpret::Expression<T>*>* operands) const
	{
		std::vector<T>::const_iterator itcoef = coeff->begin();
		std::vector<interpret::Expression<T>*>::const_iterator itexpr = operands->begin();
		T z = 0;

		// calcul de la somme des Zi
		for (; itexpr != operands->end() && itcoef != coeff->end(); itexpr++, itcoef++)
		{
			// evaluation de la règle courante
			T eval = (*itexpr)->evaluate();

			// multiplication par le coefficient associé à cette règle
			z += (*itcoef) * eval;
		}

		return z;
	}

}

#endif
