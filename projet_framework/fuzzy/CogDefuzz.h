#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"
#include <numeric>

namespace fuzzy {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
		CogDefuzz();
		virtual T defuzz(Evaluator<T>::Shape) const;
		~CogDefuzz() {};

	};

	template<class T>
	CogDefuzz<T>::CogDefuzz(){}

	template<class T>
	T CogDefuzz<T>::defuzz(Evaluator<T>::Shape shape) const
	{
		
		T numerator = std::inner_product(shape.x.begin(), shape.x.end(), shape.y.begin(), 0);
		T denominator = std::accumulate(shape.y.begin(), shape.y.end(), 0);
		return numerator / denumerator;
		
	}
}

#endif

		
	


