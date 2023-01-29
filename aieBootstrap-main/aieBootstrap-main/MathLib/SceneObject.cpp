#include "SceneObject.h"

SceneObject::SceneObject()
{
	Parent = nullptr;
	Children = new std::vector<SceneObject*>;

	Transform = new Mat3();

	IsAlive = true;
}

SceneObject::~SceneObject()
{
	delete Children;
	delete Transform;
}

Mat3* SceneObject::GetGlobalTransform()
{
	return Parent == nullptr ? Transform : Transform->Multiply(Parent->Transform);
}

void SceneObject::Update(float _deltaTime)
{
	OnUpdate(_deltaTime);
	
	if (!IsAlive)
	{
		RemoveParent();
		return;
	}

	for (auto& action : Actions)
	{
		action();
	}
	Actions.clear();

	for (auto child = Children->begin(); child != Children->end(); child++)
	{
		(*child)->Update(_deltaTime);
	}
}

void SceneObject::OnUpdate(float _deltaTime)
{
}

void SceneObject::Draw()
{
	OnDraw();
	for (auto child = Children->begin(); child != Children->end(); child++)
	{
		(*child)->Draw();
	}
}

void SceneObject::OnDraw()
{
}

void SceneObject::AddChild(SceneObject* _child)
{
	Actions.push_back([&]
	{
		if (_child->Parent != nullptr)
		{
			_child->Parent->RemoveChild(_child);
		}
		_child->Parent = this;
		Children->push_back(_child);
		return;
	});
}

void SceneObject::RemoveChild(SceneObject* _child)
{
	Actions.push_back([&]
	{
		if (_child->Parent == this)
		{
			_child->Parent = nullptr;
			std::remove(Children->begin(), Children->end(), _child);
		}
		return;
	});
}

void SceneObject::SetParent(SceneObject* _parent, SceneObject* _child)
{
	_parent->AddChild(_child);
}

SceneObject* SceneObject::GetParent()
{
	return Parent;
}

void SceneObject::RemoveParent()
{
	Parent = nullptr;
}
