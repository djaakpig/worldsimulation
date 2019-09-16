#include "TypeDefine.hxx"


class Controller
{
private:
	InputComponentPtr _input;
	ActorPtr _actor;

protected:
	Controller()
	{
	}

public:
	virtual ~Controller()
	{
	}

	void Possess(ActorPtr actor)
	{
		_actor = actor;

		OnPossess();
	}

	void SetInput(InputComponentPtr input)
	{
		_input = input;
	}

	ActorPtr Unpossess()
	{
		const auto actor = _actor;

		OnUnpossessed();

		_actor = nullptr;
		return actor;
	}

	void ResetInput()
	{
		_input = nullptr;
	}

	virtual void Update(const ClockRep delta)
	{
		_input->Update(delta);
		_actor->Update(delta);
	}

protected:
	virtual void OnPossess()
	{
	}

	virtual void OnUnpossessed()
	{
	}
};
