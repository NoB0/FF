#ifndef AGG_H
#define AGG_H

namespace fuzzy {
	
	template <class T>
	class Agg : public interpret::BinaryExpression<T> {
		
		public:
			virtual ~Agg() {};
	};
}

#endif // !AGG_H

