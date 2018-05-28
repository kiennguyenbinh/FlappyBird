#pragma once
#include "Texture.h"
class Animation :
	public Texture
{
public:
	Animation();
	~Animation();
	bool Init(Position _src, int _src_width, int _src_height, Position _des, int _des_width, int _des_height);
	void Destroy();
	void Render();
	bool loadTextTure(std::string path);
};

