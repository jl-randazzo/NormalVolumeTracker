#pragma once
#include <time.h>
#include <boost/shared_ptr.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/trivial.hpp>

#define DEBUG_MODE
#define WRITE_DEBUG_MESSAGES

#ifdef DEBUG_MODE
#define LOGGER_ASSERT(condition, reporter, errMessage, successMessage) \
if(!(condition)){\
	ProjectLogger::GetLogger()->Log(reporter, errMessage, boost::log::trivial::severity_level::fatal);\
std::abort();\
} else { \
	ProjectLogger::GetLogger()->Log(reporter, successMessage, boost::log::trivial::severity_level::debug);\
}
#else
#define LOGGER_ASSERT(condition, reporter, errMessage, successMessage
//
#endif

#ifdef DEBUG_MODE
#define LOGGER_ASSERT_MAIN(condition, errMessage, successMessage) \
if(!(condition)){\
	ProjectLogger::GetLogger()->Log(errMessage, boost::log::trivial::severity_level::fatal);\
std::abort();\
} else { \
	ProjectLogger::GetLogger()->Log(successMessage, boost::log::trivial::severity_level::debug);\
}
#else
#define LOGGER_ASSERT_MAIN(condition, errMessage, successMessage)
//
#endif

class LogReporter {
	friend class ProjectLogger;
private:
	virtual const char* Report() const = 0;
};

class ProjectLogger {
public:
	static ProjectLogger const* GetLogger();
	void Log(const LogReporter *reporter, const char *message, boost::log::trivial::severity_level level) const;
	void Log(const char *message, boost::log::trivial::severity_level level) const;
private:
	ProjectLogger();
	errno_t GetTime(char *time_s) const;
	static ProjectLogger* _instance;
	const boost::shared_ptr<boost::log::sinks::synchronous_sink<boost::log::sinks::text_file_backend>> fileDescriptor;
};

