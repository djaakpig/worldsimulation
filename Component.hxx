#include "TypeDefine.hxx"
#include <list>


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
using ComponentPtr = std::shared_ptr<Component>;
using ComponentList = std::list<ComponentPtr>;


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
