#include <utility>
#include <string>
#include <set>

#include "map.h"

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

std::set<std::pair<int, int>> init_world_map(int TILE)
{
    std::set<std::pair<int, int>> world_map;

    for (int j = 0; j < std::end(text_map) - std::begin(text_map); j++)
    {
        std::string row = text_map[j];

        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == 'W') world_map.insert(std::make_pair(i * TILE, j * TILE));
        }
    }

    return world_map;
};