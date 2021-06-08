#pragma once
#include "Depends.h"

void pacman_movement()
{
	if (dir == 0) {
		if (valid_way[px - 1][py] != 1)
			px--;
	}
	if (dir == 1) {
		if (valid_way[px + 1][py] != 1)
			px++;
	}
	if (dir == 2) {
		if (valid_way[px][py - 1] != 1)
			py--;
	}
	if (dir == 3) {
		if (valid_way[px][py + 1] != 1)
			py++;
	}

	if (valid_dot[px][py])
		valid_dot[px][py] = 0;
	if (px < 0)
		px = row - 1;
	if (px > row - 1)
		px = 0;

	Pacman.setPosition(px*box_dimensions, py*box_dimensions);
}

void set_animation()
{
	switch (dir)
	{
	case 0:
		Pacman.setTexture(left);
		animate_pacman();
		break;
	case 1:
		Pacman.setTexture(right);
		animate_pacman();
		break;
	case 2:
		Pacman.setTexture(up);
		animate_pacman();
		break;
	case 3:
		Pacman.setTexture(down);
		animate_pacman();
		break;
	default:
		break;
	}
}


void animate_pacman()
{
	if (sprite_x == 32)
		sprite_x = 0;
	else
		sprite_x += 16;
	IntRect SpriteRect(sprite_x, 0, 16, 16);
	Pacman.setTextureRect(SpriteRect);
}
