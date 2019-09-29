#include "Core/TypeDefine.h"
#include "PtrDefine.h"


class Component
{
public:
	Component()
	{
	}

	virtual ~Component()
	{
	}

	virtual bool Create()
	{
		return true;
	}

	virtual void Destroy()
	{
	}

	virtual void Update(const ClockRep delta)
	{
	}
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

	virtual void Destroy()
	{
		for(const auto& component : _components)
		{
			component->Destroy();
		}
	}

	virtual void Update(const ClockRep delta) override
	{
		for(const auto& component : _components)
		{
			component->Update(delta);
		}
	}

	void Add(const ComponentPtr& component)
	{
		_components.emplace_back(component);
	}

	void Remove(const ComponentPtr& component)
	{
		_components.remove(component);
	}
};
