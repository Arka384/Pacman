#pragma once
#include "Depends.h"

void setMap()
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			ground[i][j].setSize(Vector2f(box_dimensions - box_gap, box_dimensions - box_gap));
			if (valid_way[i][j] == 0) {
				ground[i][j].setFillColor(Color::White);
				valid_dot[i][j] = 1;
				Dot[i][j].setTexture(dot);
				Dot[i][j].setPosition(i*box_dimensions, j*box_dimensions);
			}
			if (valid_way[i][j] == 1)
				ground[i][j].setFillColor(Color::Black);
			ground[i][j].setPosition(i*box_dimensions, j*box_dimensions);
		}
	}

	map.loadFromFile("images/map_1.png");
	Map.setTexture(map);

}

void init_player_sprites()
{
	left.loadFromFile("images/pacman/left.png");
	right.loadFromFile("images/pacman/right.png");
	up.loadFromFile("images/pacman/up.png");
	down.loadFromFile("images/pacman/down.png");
	dot.loadFromFile("images/other/dot.png");

	Pacman.setPosition(px, py);
}
