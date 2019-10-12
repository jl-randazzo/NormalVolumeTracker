#include "ProjectLogger.h"

using namespace boost;

#define CTIME_S_L 26
#define CTIME_ENDL_INDEX 24

ProjectLogger* ProjectLogger::_instance; 

ProjectLogger::ProjectLogger(): fileDescriptor(log::add_file_log("runtimeDebug.log")) {
	log::core::get()->set_filter
	(
		log::trivial::severity >= log::trivial::info
	);
}

// static
ProjectLogger const* ProjectLogger::GetLogger() {
	if (!_instance) {
		_instance = new ProjectLogger();
	}

	return _instance;
}

inline errno_t ProjectLogger::GetTime(char *time_s) const {
	time_t cur_time = time(0);
	errno_t err = ctime_s(time_s, CTIME_S_L, &cur_time);
	time_s[CTIME_ENDL_INDEX] = 0; // removing endline
	return err;
}

void ProjectLogger::Log(const LogReporter *reporter, const char *message, log::trivial::severity_level level) const {
	std::ostringstream str_bldr;
	char time[CTIME_S_L];
	assert(!GetTime(time));
	str_bldr << "TIME: " << time << ", REPORTER: " << reporter->Report() << message;
	BOOST_LOG_WITH_PARAMS(log::trivial::logger::get(), (boost::log::keywords::severity = level)) << str_bldr.str();
}

void ProjectLogger::Log(const char *message, log::trivial::severity_level level) const {
	std::ostringstream str_bldr;
	char time[CTIME_S_L];
	assert(!GetTime(time));
	str_bldr << "TIME: " << time << ", REPORTER: {Main Method} :: " << message;
	BOOST_LOG_WITH_PARAMS(log::trivial::logger::get(), (boost::log::keywords::severity = level)) << str_bldr.str();
}