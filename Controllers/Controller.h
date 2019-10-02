#include "Core/TypeDefine.h"
#include "Components/PtrDefine.h"
#include "Actors/PtrDefine.h"
#include "Components/InputComponent.h"
#include "Actors/Actor.h"


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

	#pragma region Setters
	void SetInput(InputComponentPtr input)
	{
		_input = input;
	}

	void ResetInput()
	{
		_input = nullptr;
	}
	#pragma endregion

	virtual bool Create()
	{
		return true;
	}

	virtual void Destroy()
	{
	}

	virtual void Update(const ClockRep delta)
	{
		_input->Update(delta);
		_actor->Update(delta);
	}

	void Possess(ActorPtr actor)
	{
		_actor = actor;

		OnPossess();
	}

	ActorPtr Unpossess()
	{
		const auto actor = _actor;

		OnUnpossessed();

		_actor = nullptr;
		return actor;
	}

protected:
	virtual void OnPossess()
	{
	}

	virtual void OnUnpossessed()
	{
	}
};
