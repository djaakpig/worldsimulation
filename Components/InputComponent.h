#pragma once
#include "Component.h"
#include "Core/Timestamp.h"
#include <queue>


enum class EInputType : int32_t
{
	Move,
	UseSkill,
};
struct Input
{
	ClockRep timestamp;
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
};
