#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"


namespace interpret {
	template <class T>
	class ValueModel: public Expression<T>{
	public:
		ValueModel(const T);

		virtual T evaluate() const;
		virtual void setValue(const T);
		virtual T getValue() const;
		virtual ~ValueModel() {};

	private: 
		T value;
	};


	template<class T>
	ValueModel<T>::ValueModel(const T v):
		value(v)
	{
	}

	template<class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}
	template<class T>
	void ValueModel<T>::setValue(const T v)
	{
		value = v;
	}
	template<class T>
	T ValueModel<T>::getValue() const
	{
		return value;
	}
}

#endif
