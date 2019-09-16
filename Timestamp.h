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

	operator ClockRep() const
	{
		return _timestamp;
	}

	static ClockRep Now()
	{
		return Clock::now().time_since_epoch().count();
	}

	void Set(const Rep timestamp)
	{
		_timestamp = timestamp;
	}

	void MakeNow()
	{
		_timestamp = Now();
	}
};


class RemoteTimestamp final
{
public:
	using Clock = Timestamp::Clock;
	using Duration = Clock::duration;
	using Rep = Duration::rep;

private:
	Rep _remote = 0;
	Timestamp _local;
	Rep _error = 0;
	Rep _sumOfRtts = 0;
	Rep _countOfRtts = 0;

public:
	RemoteTimestamp() :
		_local(0)
	{
	}

	void Start(const Rep remote, const Rep rtt)
	{
		_remote = remote;
		_error = rtt;
		_sumOfRtts = rtt;
		_countOfRtts = 1;

		_local.MakeNow();
	}

	void Restart(const Rep remote)
	{
		_remote = remote;

		_local.MakeNow();
	}

	void AddRtt(const Rep rtt)
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

	Rep CalcNow() const
	{
		const Timestamp localNow;
		const auto localDiff = localNow - _local;
		return _remote + localDiff + _error;
	}
	
	Rep CalcElapsed(const Rep remote) const
	{
		const auto remoteNow = CalcNow();
		const auto remoteDiff = remoteNow - remote;
		return remoteDiff;
	}

	Rep CalcFuture(const Rep desired) const
	{
		const auto remoteNow = CalcNow();
		return remoteNow + desired;
	}
};
