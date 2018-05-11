#pragma once
#include <vector>
#include "Texture.h"

class TextureManager
{
private:
	std::vector<Texture*> m_stackTexture;
public:
	TextureManager();
	~TextureManager();
	bool Init();
	bool Update();
	void Render();
	bool Destroy();
	static TextureManager* getInstance();
};

