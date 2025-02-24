#ifndef _KATH_IMAGE_HPP
#define _KATH_IMAGE_HPP


/* INCLUDES */

#include "Types.hpp"
#include "Texture.hpp"


/* CLASS */

class Image
{

private:
	ID3D11ShaderResourceView	* textureView;
	uint						width;
	uint						height;

public:
	Image(const char*);
	~Image();

	uint GetWidth() const;
	uint GetHeight() const;
	ID3D11ShaderResourceView* GetView() const;

};


/* INLINE FUNCTIONS */

inline uint Image::GetWidth() const
{ return width; }

inline uint Image::GetHeight() const
{ return height; }

inline ID3D11ShaderResourceView* Image::GetView() const
{ return textureView; }

#endif // !_KATH_IMAGE_HPP