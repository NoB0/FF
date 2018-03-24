#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H
#include "Is.h"

namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*) const;
	private:
		T min, mid, max;
	};

	template<class T>
	T IsTriangle<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval <= min || expEval >= max)
			return 0;
		/*if (expEval <= mid)
			return;
		if (expEval > mid)
			return;
		*/
	}
}
#endif // !ISTRIANGLE_H

