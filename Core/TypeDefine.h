#include <memory>
#include <chrono>


//	Clock
using Clock = std::chrono::steady_clock;
using ClockDuration = Clock::duration;
using ClockRep = ClockDuration::rep;
