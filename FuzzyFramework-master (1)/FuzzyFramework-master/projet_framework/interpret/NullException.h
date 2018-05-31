#ifndef NULL_EXCEPTION
#define NULL_EXCEPTION

#include <exception>
#include <string>

namespace interpret {
	class NullException: public std::exception {
	public:
		NullException(std::string m) : message(m) {};
		virtual ~NullException() {};

	private:
		std::string message;
	};
}

#endif // !NULL_EXCEPTION

