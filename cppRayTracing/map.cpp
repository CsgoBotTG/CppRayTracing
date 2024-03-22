#include "map.h"

#include <utility>
#include <string>
#include <set>

std::string text_map[] = {
    "WWWWWWWWWWWW",
    "W..........W",
    "W..........W",
    "W..........W",
    "W..........W",
    "W..........W",
    "W..........W",
    "WWWWWWWWWWWW"
};

std::set<std::pair<int, int>> make_world_map(std::string _text_map[], int TILE)
{
    std::set<std::pair<int, int>> world_map;

    for (int j = 0; j < 8; j++)
    {
        std::string row = text_map[j];

        for (int i = 0; i < 13; i++)
        {
            if (row[i] == 'W') world_map.insert(std::make_pair(i * TILE, j * TILE));
        }
    }

    return world_map;
};