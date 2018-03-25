#ifndef ORPLUS_H
#define ORPLUS_H

namespace fuzzy {
	template <class T>
	class OrPlus : public Or<T> {
	public:
		virtual T evaluate(interpret::Expression<T>*, interpret::Expression<T>*) const;
		virtual ~OrPlus() {};
	};

	template<class T>
	T OrPlus<T>::evaluate(interpret::Expression<T>* l, interpret::Expression<T>* r) const
	{
		T lEval = l->evaluate();
		T rEval = r->evaluate();

		return lEval + rEval;
	}
}
#endif // !ORPLUS_H

