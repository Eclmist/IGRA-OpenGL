#pragma once
class Drawable
{
public:
	Drawable();
	~Drawable();

	virtual void draw() = 0;
};

