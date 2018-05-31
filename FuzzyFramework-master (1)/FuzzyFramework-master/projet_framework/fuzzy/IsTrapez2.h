#ifndef ISTRAPEZ2_H
#define ISTRAPEZ2_H

#include "../interpret/Expression.h"
#include "../fuzzy/Is.h"

namespace fuzzy {
	template <class T>
	class IsTrapez2 : public Is<T> {
	public:
		IsTrapez2<T>() ;
		IsTrapez2<T>(T, T, T);
		virtual ~IsTrapez2() {};

		virtual T evaluate(interpret::Expression<T>*) const;
	private:
		T min, mid, max;
	};

	template<class T>
	IsTrapez2<T>::IsTrapez2():
		min(0),mid(1),max(2)
	{
	}

	template<class T>
	IsTrapez2<T>::IsTrapez2(T _min, T _mid, T _max) :
		min(_min), mid(_mid), max(_max)
	{
	}

	template<class T>
	T IsTrapez2<T>::evaluate(interpret::Expression<T>* exp) const
	{
		T expEval = exp->evaluate();
		if (expEval < min || expEval > max)
			return 0;
		if (expEval < mid && expEval >= min)
			return (expEval - min) / (mid - min);
		if (expEval > mid && expEval <= max)
			return 1;
	}

}
#endif