
#include "logger.h"

int main(int argc, char** argv)
{
	LOG_MAX_SEVERITY(severity_level::debug);
	LOG_INFO("This ", 345, " is  ", 89 , " a message");
	LOG_INFO("This is ", 345, " a ", "number");
	LOG_WARNING("oh not");
	LOG_DEBUG("oh no not debug");
	return 0;
}