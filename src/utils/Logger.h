#ifndef UTILS_LOGGER_H_
#define UTILS_LOGGER_H_

#include <cstdarg>
#include <string>

namespace aker {

	class Logger {
	public:
		enum class Level {
			kInfo = 3,
			kWarning = 2,
			kError = 1,
			kNone = 0
		};

		static void SetLevel(Level level);

		Logger();
		Logger(const std::string& prefix);

		void SetPrefix(const std::string& prefix);
		void Info(const char* format, ...);
		void Warning(const char* format, ...);
		void Error(const char* format, ...);

	private:
		static Level level_;
		std::string prefix_;
		void Log_(Level level, const char* format, va_list args);
	};

}
#endif