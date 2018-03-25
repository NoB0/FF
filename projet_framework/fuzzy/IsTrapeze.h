#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H
#include "..//projet_framework/fuzzy/Is.h"

namespace fuzzy {
	template <class T>
	class IsTrapeze : public Is<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*) const;
		virtual ~IsTrapeze() {};
	private:
		T min, mid, max;
	};

	template<class T>
	T IsTrapeze<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval <= mid && expEval >= min)
			return (expEval - min) / (mid - min);
		if (expEval > mid && expEval <= max)
			return 1;

	}
}
#endif // 
