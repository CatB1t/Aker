#ifndef UTILS_LOGGER_H_
#define UTILS_LOGGER_H_

#include <cstdarg>
#include <string>

namespace aker {

	class Logger {
	public:
		Logger();
		Logger(const std::string& prefix);

		void SetPrefix(const std::string& prefix);
		void Info(const char* format, ...);
		void Warning(const char* format, ...);
		void Error(const char* format, ...);

	private:
		enum class Level {
			kInfo,
			kWarning,
			kError
		};

		std::string prefix_;
		void Log_(Level level, const char* format, va_list args);
	};

}
#endif