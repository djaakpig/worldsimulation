#include "TypeDefine.h"


class Timestamp final
{
private:
	ClockRep _timestamp = 0;

public:
	Timestamp()
	{
		MakeNow();
	}

	explicit Timestamp(const ClockRep timestamp) :
		_timestamp(timestamp)
	{
	}

	#pragma region Operators
	operator ClockRep() const
	{
		return _timestamp;
	}
	#pragma endregion

	#pragma region Setters
	void Set(const ClockRep timestamp)
	{
		_timestamp = timestamp;
	}
	#pragma endregion

	static ClockRep Now()
	{
		return Clock::now().time_since_epoch().count();
	}

	void MakeNow()
	{
		_timestamp = Now();
	}
};


class RemoteTimestamp final
{
private:
	ClockRep _remote = 0;
	Timestamp _local;
	ClockRep _error = 0;
	ClockRep _sumOfRtts = 0;
	ClockRep _countOfRtts = 0;

public:
	RemoteTimestamp() :
		_local(0)
	{
	}

	void Start(const ClockRep remote, const ClockRep rtt)
	{
		_remote = remote;
		_error = rtt;
		_sumOfRtts = rtt;
		_countOfRtts = 1;

		_local.MakeNow();
	}

	void Restart(const ClockRep remote)
	{
		_remote = remote;

		_local.MakeNow();
	}

	void AddRtt(const ClockRep rtt)
	{
		++_countOfRtts;
		_sumOfRtts += rtt;
		_error = 0 < _sumOfRtts ? _sumOfRtts / _countOfRtts / 2 : 0;
	}

	void ResetStatistics()
	{
		_countOfRtts = 0;
		_sumOfRtts = 0;
	}

	ClockRep CalcNow() const
	{
		const Timestamp localNow;
		const auto localDiff = localNow - _local;
		return _remote + localDiff + _error;
	}

	ClockRep CalcElapsed(const ClockRep remote) const
	{
		const auto remoteNow = CalcNow();
		const auto remoteDiff = remoteNow - remote;
		return remoteDiff;
	}

	ClockRep CalcFuture(const ClockRep desired) const
	{
		const auto remoteNow = CalcNow();
		return remoteNow + desired;
	}
};
