#include "TypeDefine.h"
#include "PointerDefine.h"


class Component
{
public:
	Component()
	{
	}

	virtual ~Component()
	{
	}

	virtual void Update(const ClockRep delta) = 0;
};


class Components final : public Component
{
public:
	ComponentList _components;

public:
	Components()
	{
	}

	virtual ~Components()
	{
	}

	void Add(const ComponentPtr& component)
	{
		_components.emplace_back(component);
	}

	void Remove(const ComponentPtr& component)
	{
		_components.remove(component);
	}

	virtual void Update(const ClockRep delta) override
	{
		for(const auto& component : _components)
		{
			component->Update(delta);
		}
	}
};
