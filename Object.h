#pragma once
#include <memory>
#include <string>
#include "Component.h"
using namespace std;

class Object final
{
private:
	string _name;
	shared_ptr<Components> _components;
public:
	Object(
		const string& name,
		const shared_ptr<Components>& components):
		_name(name),
		_components(components)
	{
	}
	~Object()
	{
	}
	const string& name() const
	{
		return _name;
	}
	void Tick(const int64_t delta) const
	{
		if (_components)
		{
			_components->Tick(delta);
		}
	}
};
