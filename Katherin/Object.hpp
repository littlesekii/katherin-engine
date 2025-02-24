#ifndef _KATH_OBJECT_HPP
#define _KATH_OBJECT_HPP


/* INCLUDES */

#include "Types.hpp"

/* CLASS */

class Object
{

protected:
	float x;
	float y;
	float z;
	float speed;

public:
	Object();
	virtual ~Object();

	void Translate(float, float, float = 0.f);
	void MoveTo(float, float, float = 0.f);


	virtual void Update(float) = 0;
	virtual void Render() = 0;
};


/* INLINE FUNCTIONS */

inline void Object::Translate(float dX, float dY, float dZ)
{
	x += dX;
	y += dY;
	z += dZ;
}

inline void Object::MoveTo(float x, float y, float z)
{
	this->x += x;
	this->y += y;
	this->z += z;
}

#endif // !_KATH_OBJECT_HPP