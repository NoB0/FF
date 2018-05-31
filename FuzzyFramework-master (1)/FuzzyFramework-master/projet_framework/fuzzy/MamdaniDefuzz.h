#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "Evaluator.h"
#include "../interpret/Expression.h"
#include "../interpret/BinaryExpressionModel.h"

namespace fuzzy {
	template <class T>
	class MamdaniDefuzz : public interpret::BinaryExpression<T> {
	public:
		MamdaniDefuzz();
		MamdaniDefuzz(T, T, T);
		~MamdaniDefuzz() {};

		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual typename Evaluator<T>::Shape buildShape(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual T defuzz(typename Evaluator<T>::Shape) const = 0;

		virtual void setMax(const T);
		virtual void setMin(const T);
		virtual void setStep(const T);

	private:
		T min, max, step;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz() :
		min(0),max(0),step(0)
	{
	}

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(T minimum, T maximum, T step):
		min(minimum), max(maximum), step(step)
	{
	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(interpret::Expression<T>* e, interpret::Expression<T>* s) const
	{
		return defuzz(buildShape(e, s));
	}
	template<class T>
	typename Evaluator<T>::Shape MamdaniDefuzz<T>::buildShape(interpret::Expression<T>* s, interpret::Expression<T>* isA) const
	{
		Evaluator<T>::Shape shape = Evaluator<T>::buildShape(min, max, step, static_cast<interpret::ValueModel<T>*>(s), isA);
		return shape;
	}

	template<class T>
	void MamdaniDefuzz<T>::setMax(const T m)
	{
		max = m;
	}

	template<class T>
	void MamdaniDefuzz<T>::setMin(const T m)
	{
		min = m;
	}

	template<class T>
	void MamdaniDefuzz<T>::setStep(const T s)
	{
		step = s;
	}

}

#endif