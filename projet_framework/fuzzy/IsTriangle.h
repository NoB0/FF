#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "../interpret/Expression.h"
#include "../fuzzy/Is.h"

namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T> {
	public:
		IsTriangle<T>() {};
		IsTriangle<T>(T, T, T);
		virtual ~IsTriangle() {};

		virtual T evaluate(interpret::Expression<T>*) const;
	private:
		T min, mid, max;
	};

	template<class T>
	IsTriangle<T>::IsTriangle(T _min, T _mid, T _max):
		min(_min), mid(_mid), max(_max)
	{
	}

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

