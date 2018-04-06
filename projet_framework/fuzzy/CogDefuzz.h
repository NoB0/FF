#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "../interpret/Expression.h"
#include "MamdaniDefuzz.h"
#include "Evaluator.h"
#include <numeric>

namespace fuzzy {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		CogDefuzz<T>() {};
		~CogDefuzz() {};

		virtual T defuzz(typename Evaluator<T>::Shape) const;
	};

	template<class T>
	T CogDefuzz<T>::defuzz(typename Evaluator<T>::Shape shape) const
	{
		T numerator = std::inner_product(shape.first.begin(), shape.first.end(), shape.second.begin(), 0);
		T denominator = std::accumulate(shape.second.begin(), shape.second.end(), 0);

		return numerator / denominator;
		
	}
}

#endif

		
	


