#include "Object.hpp"
#include "Sprite.hpp"

class DavyJones : public Object
{

private: 
	Sprite* sprite;

public:
	DavyJones();
	~DavyJones();

	void Update(float);
	void Render();
};

