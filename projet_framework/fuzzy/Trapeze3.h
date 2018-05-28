#ifndef ISTRAPEZE3_H
#define ISTRAPEZE3_H
#include "..//projet_framework/fuzzy/Is.h"

namespace fuzzy {
	template <class T>
	class IsTrapeze3 : public Is<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*) const;
		virtual ~IsTrapeze3() {};
	private:
		T min, mid, max;
	};

	template<class T>
	T IsTrapeze3<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval <= mid && expEval >= min)
			return 1;
		if (expEval > mid && expEval <= max)
			return return (max - expEval) / (max - mid);

	}
}
#endif