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
		/*vector<T> product;
		vector<T>::const_iterator itX = shape.first.begin();
		vector<T>::const_iterator itY = shape.second.begin();

		for (; itY != shape.second.end(); ++itY, ++itX) {
			T x = (*itX);
			T y = (*itY);

			product.push_back(x * y);
		}

		T sumProduct = 0;
		T sumY = 0;

		// (somme des xi*yi) / (somme des yi) (center of gravity)
		return accumulate(product.begin(), product.end(), sumProduct)
			/ accumulate(shape.second.begin(), shape.second.end(), sumY);
		*/
		T numerator = std::inner_product(shape.first.begin(), shape.first.end(), shape.second.begin(), 0);
		T denominator = std::accumulate(shape.second.begin(), shape.second.end(), 0);

		return numerator / denominator;
		
	}
}

#endif

