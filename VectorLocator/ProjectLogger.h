#pragma once
#include <time.h>
#include <boost/shared_ptr.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/trivial.hpp>


class LogReporter {
	friend class ProjectLogger;
private:
	virtual char* Report() const = 0;
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