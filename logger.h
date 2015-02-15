
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>
#include <ctime>
#include <sstream>
#include <mutex>
#include <array>
#include <fstream>
#include <memory>

enum class severity_level
{
	fatalerror = 0,
	warning = 1,		
	information = 2,
	debug = 3,
	num_severtiylevels = 4
};

template<typename logger_impl>
class Logger
{
public:	
	Logger(const std::string & name)
		: _loggerImpl(),
		  _loggerStream(""),
		  _logMutex(),
		  _severityToString()
	{
		std::cout << "Constructing Logger Instance: " << std::endl;
		_loggerImpl.open_stream(name);
		_severityToString[(size_t)severity_level::warning]	   = "<warning>    : ";
		_severityToString[(size_t)severity_level::debug]       = "<debug>      : ";
		_severityToString[(size_t)severity_level::information] = "<information>: ";
		_severityToString[(size_t)severity_level::fatalerror]  = "<fatalerror >: ";
	}

	~Logger()
	{
		_loggerImpl.close_stream();
	}
	
	std::string getTime()
	{
		std::string time_str;
		std::time_t now;
		time(&now);
		time_str = ctime(&now);
		return time_str.substr(0, time_str.size()-1);
	}

	template<severity_level severity, typename T1>
	void print(const T1 & param1)
	{	
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];

			_loggerStream << param1;		
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}		
	}

	template<severity_level severity, typename T1, typename T2>
	void print(const T1 & param1, const T2 & param2)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime()  << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2;
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3>
	void print(const T1 & param1, const T2 & param2, const T3 & param3)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4, typename T5>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4, const T5 & param5)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4 << param5;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4, const T5 & param5, const T6 & param6)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4 << param5 << param6;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4, const T5 & param5, const T6 & param6, const T7 & param7)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4 << param5 << param6 << param7;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4, const T5 & param5, const T6 & param6, const T7 & param7, const T8 & param8)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4 << param5 << param6 << param7 << param8;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4, const T5 & param5, const T6 & param6, const T7 & param7, const T8 & param8, const T9 & param9)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4 << param5 << param6 << param7 << param8 << param9;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	template<severity_level severity, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	void print(const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4, const T5 & param5, const T6 & param6, const T7 & param7, const T8 & param8, const T9 & param9, const T10 & param10)
	{
		if (severity <= _activeSeverityLevel)
		{
			_loggerStream << getTime() << " ";
			_loggerStream << _severityToString[(size_t)severity];
			_loggerStream << param1 << param2 << param3 << param4 << param5 << param6 << param7 << param8 << param9 << param10;	
			_loggerStream << std::endl;

			printMessage(_loggerStream.str(), severity);
			_loggerStream.str("");
		}
	}

	void setSeverityLevel(severity_level activeLevel)
	{
		_activeSeverityLevel = activeLevel;
	}
	
private:
	void printMessage(const std::string & message, const severity_level & level )
	{
		_logMutex.lock();
		_loggerImpl.write(message, level);
		_logMutex.unlock();
	}
	logger_impl _loggerImpl;
	std::stringstream _loggerStream;
	std::mutex _logMutex;
	std::array<std::string, (size_t)severity_level::num_severtiylevels> _severityToString;
	severity_level _activeSeverityLevel;
};

class log_stream
{
public:

	virtual void open_stream(const std::string & name)	= 0;

	virtual void write(const std::string & name,
		const severity_level & level) = 0;
	
	virtual void close_stream() = 0;
};

class console_log_stream : public log_stream
{
public:
	void open_stream(const std::string & name)	
	{
		std::cout.flush();
		std::cout << name << std::endl;
	}

	void write(const std::string & message, const severity_level & level)
	{
		std::cout << message;
	}

	void close_stream()
	{
		std::cout.flush();
	}
};

class file_log_stream : public log_stream
{
public:
	file_log_stream()
		: _ofstream(new std::ofstream())
	{
	}

	~file_log_stream()
	{
	}

	void open_stream(const std::string & name)	
	{
		_ofstream->open(name, std::ios_base::binary|std::ios_base::out);		
	}

	void write(const std::string & message, const severity_level & level)
	{
		(*_ofstream) << message;
	}

	void close_stream()
	{		
		_ofstream->flush();
		_ofstream->close();
	}
private:	 
	std::unique_ptr<std::ofstream> _ofstream;
};

typedef Logger<console_log_stream> ConsoleLoggerType;
typedef Logger<file_log_stream> FileLoggerType;
static FileLoggerType logInstance("execution.log");

#define LOGGING_ON
#ifdef LOGGING_ON
	#define LOG_MAX_SEVERITY logInstance.setSeverityLevel
	#define LOG_DEBUG logInstance.print<severity_level::debug>
	#define LOG_WARNING logInstance.print<severity_level::warning>
	#define LOG_INFO logInstance.print<severity_level::information>
	#define LOG_ERROR logInstance.print<severity_level::fatalerror>
#else
	#define LOG_DEBUG 
	#define LOG_WARNING 
	#define LOG_INFO 
	#define LOG_ERROR 
#endif

#endif /*__LOGGER_H__*/