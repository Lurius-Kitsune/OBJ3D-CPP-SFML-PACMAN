#pragma once

#define PACMAN_SHEET "Assets/Textures/PacmanSheet.png"

#define TILE_SIZE 9
#define CATEGORIE_TILE_SIZE_X 200
#define CATEGORIE_TILE_SIZE_Y 186

static Vector2i SelectTileTexture(const Vector2u& _categorieSelected, const Vector2u& _selectedTile)
{
	return Vector2i(CATEGORIE_TILE_SIZE_X * _categorieSelected.x + (TILE_SIZE * _selectedTile.x) + 1, CATEGORIE_TILE_SIZE_Y * _categorieSelected.y + (TILE_SIZE * _selectedTile.y)+1);
}
