#include "Component.h"
#include "Timestamp.h"


class RemoteSessionComponent final : public Component
{
private:
	RemoteTimestamp _remote;

public:
	RemoteSessionComponent()
	{
	}

	virtual ~RemoteSessionComponent()
	{
	}

	void AddRtt(const ClockRep rtt)
	{
		_remote.AddRtt(rtt);
	}

	auto CalcNow() const->ClockRep
	{
		return _remote.CalcNow();
	}

	void Send()
	{
	}

	void OnEstablished(const ClockRep remote, const ClockRep rtt)
	{
		_remote.Start(remote, rtt);
	}

	void OnReceived()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};
