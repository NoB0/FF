#ifndef NARY_EXPRESSION_MODEL_H
#define NARY_EXPRESSION_MODEL_H

namespace interpret {
	template <class T>
	class NaryExpressionModel : public Expression<T>, public NaryExpression<T> {
	public:
		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression<T>*, std::vector<const Expression<T>*>*);
		virtual ~NaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(std::vector<const Expression<T>*>*) const;

	private:
		NaryExpression<T>* ope;
		std::vector<const Expression<T>*>* operands;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* ope, std::vector<const Expression<T>*>* operands):
		ope(ope), operands(operands) 
	{
	}
	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operands->empty()) {
			throw new NullException("null operands");
		}

		return evaluate(operands);
	}
	template<class T>
	T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*>* operands) const
	{
		if (ope == NULL) {
			throw new NullException("null operator");
		}

		return ope->evaluate(operands);
	}
}

#endif // !NARYEXPRESSIONMODEL_H

