#include "TextureManager.h"
#include "Engine.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

bool TextureManager::Init() {
	return true;
}

bool TextureManager::Destroy() {
	return true;
}

bool TextureManager::Update() {
	return true;
}

void TextureManager::Render() {

}
TextureManager* TextureManager::getInstance() {
	static TextureManager* instance;
	if( instance) 
		return instance;
	instance = new TextureManager();
	return instance;
}


