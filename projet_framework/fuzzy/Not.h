#ifndef NOT_H
#define NOT_H

namespace fuzzy {
	template <class T>
	class Not : public interpret::UnaryExpression<T> {
	public: 
		virtual ~Not() {};
	};
}
#endif // !NOT_H

