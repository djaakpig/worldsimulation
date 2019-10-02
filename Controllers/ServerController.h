#include "Controller.h"
#include "Components/RemoteInputComponent.h"


class ServerController : public Controller
{
private:
	RemoteSessionComponentPtr _remoteSession;

public:
	ServerController()
	{
		SetInput(std::make_shared<RemoteInputComponent>());
	}

	virtual ~ServerController()
	{
	}

	virtual void Update(const ClockRep delta)
	{
	}

	#pragma region Setters
	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}
	#pragma endregion
};
