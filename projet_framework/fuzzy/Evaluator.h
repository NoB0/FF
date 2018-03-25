#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
using namespace std;

namespace fuzzy {
	template <class T>
	class Evaluator {
	public:
		typedef pair<vector<T>, vector<T> > Shape;
		static Shape buildShape(const T& min, const T& max, const T& step, const interpret::Expression&, const interpret::Expression&);
		static ostream& printShape(ostream&, const Shape& s);
	};

	template<class T>
	Shape Evaluator<T>::buildShape(const T & min, const T & max, const T & step, const interpret::Expression& exp, const interpret::Expression& func)
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			y.push_back(func->evaluate(exp);
			x.push_back(i);
		}
		return Shape(x, y);
	}

	template<class T>
	ostream & Evaluator<T>::printShape(ostream& os, const Shape &s)
	{
		os << '[';
		typename vector<T>::const_iterator it = s.first.begin();
		for (; it != s.first.end(); ++it)
			os << *it << ' ';
		os << ']';
		os << endl;
		os << '[';
		it = s.second.begin();
		for (; it != s.second.end(); ++it)
			os << *it << ' ';
		os << ']';
		return os;
	}

}

#endif // !EVALUATOR_H

