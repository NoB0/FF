#ifndef OR_H
#define OR_H

namespace fuzzy {
	template <class T>
	class Or : public interpret::BinaryExpression<T> {
	public:
		virtual ~Or() {};

	};
}

#endif // !OR_H

