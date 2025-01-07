#include "CoreMinimal.h"
#include "Map.h"
int main()
{
    Map::GetInstance().InitMap("D:\\SFML\\PacMan\\Assets\\Maps\\SmallMap.txt");

    Map::GetInstance().DisplayMap();

    return EXIT_SUCCESS;
}