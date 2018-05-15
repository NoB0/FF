#ifndef SUGENO_THEN_H
#define SUGENO_THEN_H

namespace fuzzy {
	template <class T>
	class SugenoThen : public Then<T>, interpret::BinaryExpression<T> {
	public:
		SugenoThen();
		~SugenoThen() {};

		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual T getPremiseValue() const;
	private:
		T premiseValue;
	};

	template<class T>
	SugenoThen<T>::SugenoThen():
		premiseValue(0)
	{
	}

	template<class T>
	T SugenoThen<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		premiseValue = l->evaluate();
		T rEval = r->evaluate();
		return premiseValue * rEval;
	}
	template<class T>
	T SugenoThen<T>::getPremiseValue() const
	{
		return premiseValue;
	}
}

#endif // !SUGENO_THEN_H

