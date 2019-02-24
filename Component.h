#pragma once
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

class Component
{
private:
	const string _name;
public:
	explicit Component(const string& name): _name(name)
	{
	}
	virtual ~Component() = default;
	const string& GetName() const
	{
		return _name;
	}
	virtual void Tick(const int64_t delta) = 0;
};
using ComponentPtr = shared_ptr<Component>;

class Components final: public Component
{
private:
	unordered_map<string, ComponentPtr> _components;
public:
	using Component::Component;
	void Add(ComponentPtr& component)
	{
		_components.emplace(
			make_pair(component->GetName(), component)
		);
	}
	void Remove(const string& name)
	{
		_components.erase(name);
	}
	ComponentPtr Find(const string& name) const
	{
		const auto iter = _components.find(name);
		return _components.end() != iter ? iter->second : nullptr;
	}
	void Tick(const int64_t delta) final
	{
		for (const auto& componentPair : _components)
		{
			componentPair.second->Tick(delta);
		}
	}
};
