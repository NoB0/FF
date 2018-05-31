#ifndef ISTRAPEZ1_H
#define ISTRAPEZ1_H

#include "../interpret/Expression.h"
#include "../fuzzy/Is.h"

namespace fuzzy {
	template <class T>
	class IsTrapez1 : public Is<T> {
	public:
		IsTrapez1<T>();
		IsTrapez1<T>(T, T, T);
		virtual ~IsTrapez1() {};

		virtual T evaluate(interpret::Expression<T>*) const;
	private:
		T min, mid, max;
	};

	template<class T>
	IsTrapez1<T>::IsTrapez1<T>::IsTrapez1():
		min(0),mid(1),max(2)
	{
	}

	template<class T>
	IsTrapez1<T>::IsTrapez1(T _min, T _mid, T _max) :
		min(_min), mid(_mid), max(_max)
	{
	}

	template<class T>
	T IsTrapez1<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval <= mid && expEval >= min)
			return 1;
		if (expEval > mid && expEval <= max)
			return (max - expEval) / (max - mid);
	}

}
#endif