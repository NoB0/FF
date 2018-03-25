#ifndef ISTRAPEZE2_H
#define ISTRAPEZE2_H
#include "..//projet_framework/fuzzy/Is.h"

namespace fuzzy {
	template <class T>
	class IsTrapeze2 : public Is<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*) const;
		virtual ~IsTrapeze2() {};
	private:
		T min, mid1, mid2, max;
	};

	template<class T>
	T IsTrapeze2<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval <= mid1 && expEval >= min)
			return (expEval - min) / (mid1 - min);
		if (expEval > mid2 && expEval <= max)
			return  (max - expEval) / (max - mid2);
		if (expEval > mid1 && expEval < mid2)
			return  1;
	}
}
#endif 