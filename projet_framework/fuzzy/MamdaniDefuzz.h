#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "Evaluator.h"
#include "..\interpret\BinaryExpressionModel.h"

namespace fuzzy {
	template <class T>
	class MamdaniDefuzz : public interpret::BinaryExpression<T> {
	public:
		MamdaniDefuzz(T, T, T);
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual Shape buildShape(interpret::Expression<T>*, interpret::Expression<T>*);
		virtual T defuzz(Shape) const = 0;
		~MamdaniDefuzz() {};

	private:
		T min, max, step;
	};

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
	Shape MamdaniDefuzz<T>::buildShape(interpret::Expression<T>* s, interpret::Expression<T>* isA)
	{
		Evaluator<T>::Shape shape = Evaluator<T>::buildShape(min, max, step, s, isA);
		return shape;
	}

}

#endif