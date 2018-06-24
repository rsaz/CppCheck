////////////////////////////////////////////////////////////////////////////////
//
// CppCheck.h  --  Three different simple implementations of measuring
//				   execution time/performance of your code in C++.
//
// Copyright (C) 2018 by Richard Zampieri <br.developer@gmail.com>
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <chrono>
#include <string>
#include <Windows.h>

namespace cck
{
	
	// Class using <chrono> library available since c++11
	// high_resolution_clock class for highest precision clock
	class CppCheck
	{
	private:
		std::chrono::steady_clock::time_point s; // variable "s" to record starting time
		std::chrono::steady_clock::time_point e; // variable "e" to record end time
	public:
		~CppCheck() {}; // Destructor

		// function to set "s" with current time
		void Start() { s = std::chrono::high_resolution_clock::now(); } 
		
		// function to set "e" with current time
		void Stop() { e = std::chrono::high_resolution_clock::now(); }

		// function to calculate and return the elapsed time between start and end time
		std::string Elapsed()
		{
			std::chrono::duration<float> elapsed = e - s;
			return ("Execution: " + std::to_string(elapsed.count()) + " ms");
		}
	};


	// Class using <chrono> library available since c++11 with
	// static member function and variables
	// high_resolution_clock class for highest precision clock
	class CppCheck1
	{
	public:

		// function that returns the current time
		static std::chrono::high_resolution_clock::time_point Start()
		{
			return std::chrono::high_resolution_clock::now();
		}

		// function that returns the elapsed time calculating the end time during it execution
		static float Elapsed(std::chrono::high_resolution_clock::time_point const& s)
		{
			return std::chrono::duration_cast<std::chrono::duration<float>>(Start() - s).count();
		}
	};


	// Class using Windows native-code library "Windows.h"
	// For high-performance timers
	class CppCheck2
	{
	private:
		long long start;
		long long stop;

		inline long long Counter() noexcept
		{
			LARGE_INTEGER li;
			::QueryPerformanceCounter(&li);
			return li.QuadPart;
		}

		inline long long Frequency() noexcept
		{
			LARGE_INTEGER li;
			::QueryPerformanceFrequency(&li);
			return li.QuadPart;
		}

	public:
		void Start() { start = Counter(); };
		void Stop() { stop = Counter(); };
		inline double ElapsedMilliseconds() noexcept
		{
			return ((stop - start) * 10.0) / Frequency();
		}
	};
}


