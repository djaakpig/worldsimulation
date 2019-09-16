#include "Component.hxx"
#include "Actor.hxx"
#include "Controller.hxx"
#include <queue>


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

	ClockRep CalcNow() const
	{
		return _remote.CalcNow();
	}

	void Send()
	{
	}

	void OnEstablished(
		const ClockRep remote,
		const ClockRep rtt)
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
using RemoteSessionComponentPtr = std::shared_ptr<RemoteSessionComponent>;


class MovementComponent final : public Component
{
public:
	MovementComponent()
	{
	}

	virtual ~MovementComponent()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};


enum class EInputType : int32_t
{
	Move,
	UseSkill,
};
struct Input
{
	Timestamp::Rep timestamp;
	EInputType type;

	bool CanActive(const ClockRep now) const
	{
		return timestamp <= now;
	}
};
using InputPtr = std::shared_ptr<Input>;
using InputQueue = std::queue<InputPtr>;


class InputComponent : public Component
{
private:
	InputQueue _pendingInputs;
	InputQueue _inputs;

public:
	InputComponent()
	{
	}

	virtual ~InputComponent()
	{
	}

	void PushInput(InputPtr input)
	{
		_inputs.push(input);
	}

	InputPtr PopInput()
	{
		if(_inputs.empty())
		{
			return nullptr;
		}
		const auto input = _inputs.front();
		_inputs.pop();
		return input;
	}

	virtual void Update(const ClockRep delta) override
	{
		Timestamp now;
		while(!_pendingInputs.empty())
		{
			const auto input = _pendingInputs.front();
			if(!input->CanActive(now))
			{
				break;
			}
			_pendingInputs.pop();
		}
	}
};
using InputComponentPtr = std::shared_ptr<InputComponent>;


class AIComponent final : public InputComponent
{
public:
	AIComponent()
	{
	}

	virtual ~AIComponent()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};
using AIComponentPtr = std::shared_ptr<AIComponent>;


class UserInputComponent final : public InputComponent
{
public:
	UserInputComponent()
	{
	}

	virtual ~UserInputComponent()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};


class RemoteInputComponent final : public InputComponent
{
private:
	RemoteSessionComponentPtr _remoteSession;

public:
	RemoteInputComponent()
	{
	}

	virtual ~RemoteInputComponent()
	{
	}

	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};
using RemoteInputComponentPtr = std::shared_ptr<RemoteInputComponent>;


class ProxyController : public Controller
{
public:
	ProxyController()
	{
		SetInput(std::make_shared<RemoteInputComponent>());
	}

	virtual ~ProxyController()
	{
	}
};
using ProxyControllerPtr = std::shared_ptr<ProxyController>;


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

	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}

	virtual void Update(const ClockRep delta)
	{
	}
};
using ServerControllerPtr = std::shared_ptr<ServerController>;


class ClientController : public Controller
{
private:
	RemoteSessionComponentPtr _remoteSession;

public:
	ClientController()
	{
		SetInput(std::make_shared<UserInputComponent>());
	}

	virtual ~ClientController()
	{
	}

	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}

	virtual void Update(const ClockRep delta)
	{
	}
};
using ClientControllerPtr = std::shared_ptr<ClientController>;


class StandaloneController : public Controller
{
public:
	StandaloneController()
	{
	}

	virtual ~StandaloneController()
	{
	}

	virtual void Update(const ClockRep delta)
	{
	}
};
using StandaloneControllerPtr = std::shared_ptr<StandaloneController>;


////////////////////////////////////////
// MAIN
////////////////////////////////////////
int main(int argc, char **args)
{
	auto s1 = std::make_shared<RemoteSessionComponent>();
	auto s2 = std::make_shared<RemoteSessionComponent>();

	auto c1 = std::make_shared<ServerController>();
	auto c2 = std::make_shared<ServerController>();

	c1->SetRemoteSession(s1);
	c2->SetRemoteSession(s2);

	auto a1 = std::make_shared<Actor>();
	auto a2 = std::make_shared<Actor>();

	c1->Possess(a1);
	c2->Possess(a2);

	Timestamp prev;

	for(int32_t i = 0; 5 > i; ++i)
	{
		Timestamp now;
		const auto delta = now - prev;

		a1->Update(delta);
		a2->Update(delta);

		prev = now;
	}

	c1->Unpossess();
	c2->Unpossess();

	return 0;
}
