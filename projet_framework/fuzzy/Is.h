#ifndef IS_H
#define IS_H

namespace fuzzy {
	template <class T>
	class Is : public interpret::UnaryExpression<T> {
	public: 
		virtual ~Is() {};
	};
}
#endif // !IS_H
