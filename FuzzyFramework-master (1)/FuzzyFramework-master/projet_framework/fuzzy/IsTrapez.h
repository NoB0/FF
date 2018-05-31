#ifndef ISTRAPEZ_H
#define ISTRAPEZ_H

#include "../interpret/Expression.h"
#include "../fuzzy/Is.h"

namespace fuzzy{
	template <class T>
	class IsTrapez : public Is<T> {
	public:
		IsTrapez<T>() ;
		IsTrapez<T>(T, T, T,T);
		virtual ~IsTrapez() {};

		virtual T evaluate(interpret::Expression<T>*) const;
	private:
		T min, mid1,mid2, max;
	};

	template<class T>
	IsTrapez<T>::IsTrapez() :
		min(0), mid1(1), mid2(2), max(3)
	{
	}
	template<class T>
	IsTrapez<T>::IsTrapez(T _min, T _mid1,T _mid2, T _max) :
		min(_min), mid1(_mid1), mid2(_mid2), max(_max)
	{
	}

	template<class T>
	T IsTrapez<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval < mid1 && expEval >= min)
			return (expEval - min) / (mid1 - min);
		if (expEval > mid2 && expEval <= max)
			return (max - expEval) / (max - mid2);
		if (expEval>=mid1 && expEval <= mid2) return 1;
	}

}
#endif
