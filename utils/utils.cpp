/*
	Aseba - an event-based framework for distributed robot control
	Copyright (C) 2007--2009:
		Stephane Magnenat <stephane at magnenat dot net>
		(http://stephane.magnenat.net)
		and other contributors, see authors.txt for details
		Mobots group, Laboratory of Robotics Systems, EPFL, Lausanne
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any other version as decided by the two original authors
	Stephane Magnenat and Valentin Longchamp.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>
#include <cstring>
#ifndef WIN32
	#include <sys/time.h>
#else // WIN32
	#include <sys/types.h>
	#include <sys/timeb.h>
	#include <windows.h>
	#define atoll _atoi64
#endif // WIN32
#include <time.h>
#include <errno.h>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <cassert>
#include "utils.h"

namespace Aseba
{
	/** \addtogroup utils */
	/*@{*/
	
	UnifiedTime::UnifiedTime()
	{
		#ifndef WIN32
		struct timeval tv;
		gettimeofday(&tv, NULL);
		value = (Value(tv.tv_sec) * 1000) + Value(tv.tv_usec) / 1000;
		#else // WIN32
		struct __timeb64 tv;
		_ftime64_s(&tv);
		value = Value(tv.time) * 1000 + Value(tv.millitm);
		#endif // WIN32
	}
	
	UnifiedTime::UnifiedTime(Value ms) :
		value(ms)
	{
	}
	
	UnifiedTime::UnifiedTime(Value seconds, Value milliseconds) :
		value(seconds * 1000 + milliseconds)
	{
	}
	
	void UnifiedTime::sleep() const
	{
		#ifndef WIN32
		struct timespec ts;
		ts.tv_sec = (value / 1000);
		ts.tv_nsec = ((value % 1000) * 1000000);
		nanosleep(&ts, 0);
		#else // WIN32
		assert(value < (1 << 32));
		Sleep((DWORD)value);
		#endif // WIN32
	}
	
	std::string UnifiedTime::toHumanReadableStringFromEpoch() const
	{
		std::ostringstream oss;
		Value seconds(value / 1000);
		Value milliseconds(value % 1000);
		time_t t(seconds);
		char *timeString = ctime(&t);
		timeString[strlen(timeString) - 1] = 0;
		oss << "[";
		oss << timeString << " ";
		oss << std::setfill('0') << std::setw(3) << milliseconds;
		oss << "]";
		return oss.str();
	}
	
	std::string UnifiedTime::toRawTimeString() const
	{
		std::ostringstream oss;
		Value seconds(value / 1000);
		Value milliseconds(value % 1000);
		oss << std::dec << seconds << "." << std::setfill('0') << std::setw(3) << milliseconds;
		return oss.str();
	}
	
	UnifiedTime UnifiedTime::fromRawTimeString(const std::string& rawTimeString)
	{
		size_t dotPos(rawTimeString.find('.'));
		assert(dotPos != std::string::npos);
		return UnifiedTime(atoll(rawTimeString.substr(0, dotPos).c_str()), atoll(rawTimeString.substr(dotPos + 1, std::string::npos).c_str()));
	}
	
	
	void dumpTime(std::ostream &stream, bool raw)
	{
		if (raw)
			stream << UnifiedTime().toRawTimeString();
		else
			stream << UnifiedTime().toHumanReadableStringFromEpoch();
		stream << " ";
	}
	
	/*@}*/
}
