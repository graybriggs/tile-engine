
#ifndef SPRITE_H
#define SPRITE_H

#ifdef WINDOWS
  #include "SDL.h"
#else
  #include "SDL2/SDL.h"
#endif

#include <exception>
#include <memory>
#include <string>


SDL_Texture* loadTextureFromSurface(SDL_Renderer* renderer, std::string n) {

	SDL_Surface* texImg = SDL_LoadBMP(n.c_str());
	if (texImg == NULL) {
		std::string errMsg(n + "failed to load");
		throw std::exception();
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, texImg);
	SDL_FreeSurface(texImg);
	return tex;
}

// load sprite sheet separate SpriteSheetLoader class
// pass pointer to sheet into Sprite class
// clip from there.


// Create SpriteSheet object and pass it the renderer
// Load the sheet name
// pass the sheet into the desired sprite.
struct SpriteSheet {

	SpriteSheet(SDL_Renderer* rend) {
		renderer = rend;
	}

	~SpriteSheet() {
		SDL_DestroyTexture(spriteSheetTexture);	
	}

	SpriteSheet(const SpriteSheet& rhs) {
		spriteSheetTexture = loadTextureFromSurface(rhs.renderer, rhs.spriteSheetName);
		spriteSheetName = rhs.spriteSheetName;
		renderer = rhs.renderer;
	}

	void loadSpriteSheet(std::string name) {
		spriteSheetTexture = loadTextureFromSurface(renderer, name);
	}

	SDL_Renderer* renderer;
	std::string spriteSheetName;
	SDL_Texture* spriteSheetTexture;
};

//////////////////////////////////////////////

class Sprite {
public:
	Sprite(SDL_Renderer* rend, SpriteSheet* ss, int x, int y, int w, int h) {
		renderer = rend;

		spriteSheet = ss;

		boundingBox.x = x;
		boundingBox.y = y;
		boundingBox.w = w;
		boundingBox.h = h;

		clipBox.x = 0;
		clipBox.y = 0;
		clipBox.w = 32;
		clipBox.h = 32;
	}

	Sprite(const Sprite& rhs) {
		renderer = rhs.renderer;
		spriteSheet = rhs.spriteSheet;
		boundingBox = rhs.boundingBox;
		clipBox = rhs.clipBox;
	}

	Sprite operator=(const Sprite& rhs) {
		renderer = rhs.renderer;
		spriteSheet = rhs.spriteSheet;
		boundingBox = rhs.boundingBox;
		clipBox = rhs.clipBox;
	}

	void setSpriteId(std::string id) {
		spriteID = id;
	}

	void setClipBox(SDL_Rect box) {
		clipBox = box;
	}

	void setClipBox(int x, int y, int w, int h) {
		clipBox.x = x;
		clipBox.y = y;
		clipBox.w = w;
		clipBox.h = h;
	}

	void setClips(int x, int y) {
		clipBox.x = x;
		clipBox.y = y;
	}

	void setBoundingBox(SDL_Rect bBox) {
		boundingBox = bBox;
	}

	void setBoundingBox(int x, int y, int w, int h) {
		boundingBox.x = x;
		boundingBox.y = y;
		boundingBox.w = w;
		boundingBox.h = h;
	}

	SDL_Rect getBoundingBox() {
		return boundingBox;
	}

	void renderSprite() {
		SDL_RenderCopy(renderer, spriteSheet->spriteSheetTexture, &clipBox, &boundingBox);
	}

private:
	std::string spriteID;
	SDL_Renderer* renderer;
	SDL_Rect boundingBox;
	SDL_Rect clipBox;
	SpriteSheet* spriteSheet;
};

/////////////


#endif

