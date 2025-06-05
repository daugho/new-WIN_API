#pragma once

//Interface
class Scene
{
public:
	//Scene() {}
	Scene() = default;	
	~Scene() = default;
		
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;	
};