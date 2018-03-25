#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H
#include "..\\fuzzy\Is.h"

namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*) const;
		virtual ~IsTriangle() {};
	private:
		T min, mid, max;
	};

	template<class T>
	T IsTriangle<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval <= mid && expEval>=min)
			return (expEval-min)/(mid-min);
		if (expEval > mid && expEval<=max)
			return (max-expEval)/(max-mid);
		
	}
}
#endif // !ISTRIANGLE_H

