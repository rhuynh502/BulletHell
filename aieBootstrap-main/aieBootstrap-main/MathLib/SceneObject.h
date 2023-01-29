#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include "Mat3.h"

class SceneObject
{
public:
	SceneObject();
	~SceneObject();

	SceneObject* Parent;

	std::vector<SceneObject*>* Children;
	Mat3* Transform;

	bool IsAlive;

	Mat3* GetGlobalTransform();

	void Update(float _deltaTime);
	virtual void OnUpdate(float _deltaTime);

	void Draw();
	virtual void OnDraw();

	void AddChild(SceneObject* _child);
	void RemoveChild(SceneObject* _child);

	void SetParent(SceneObject* _parent, SceneObject* _child);
	void RemoveParent();

	SceneObject* GetParent();

private:
	std::vector<std::function<void()>> Actions;
};

