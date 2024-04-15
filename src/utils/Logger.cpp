#include "Logger.h"

#include <format>

namespace aker {

	void Logger::SetLevel(Level level) { level_ = level; };
	Logger::Level Logger::level_ = Logger::Level::kInfo;

	Logger::Logger() : prefix_("Unnamed_Logger")
	{}

	Logger::Logger(const std::string& prefix)
		: prefix_(prefix) 
	{}

	void Logger::SetPrefix(const std::string& prefix)
	{
		prefix_ = prefix;
	}

	void Logger::Info(const char* format, ...)
	{
		if (level_ < Level::kInfo)
			return;

		va_list args;
		va_start(args, format);
		Log_(Level::kInfo, format, args);
		va_end(args);
	}

	void Logger::Warning(const char* format, ...)
	{
		if (level_ < Level::kWarning)
			return;

		va_list args;
		va_start(args, format);
		Log_(Level::kWarning, format, args);
		va_end(args);
	}

	void Logger::Error(const char* format, ...)
	{
		if (level_ < Level::kError)
			return;

		va_list args;
		va_start(args, format);
		Log_(Level::kError, format, args);
		va_end(args);
	}

	void Logger::Log_(Level level, const char* format, va_list args) 
	{
		std::string level_str;
		FILE* stream;
		switch (level)
		{
		case Level::kInfo:
			level_str = "INFO";
			stream = stdout;
			break;
		case Level::kWarning:
			level_str = "WARNING";
			stream = stdout;
			break;
		case Level::kError:
			level_str = "ERROR";
			stream = stderr;
			break;
		default:
			fprintf(stderr, "LOGGER::ERROR: Unknown level");
			return;
		}

		std::string new_format = std::format("{}::{}: {}\n", prefix_.c_str(), level_str.c_str(), format);
		vfprintf(stream, new_format.c_str(), args);
	}
}