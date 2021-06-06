
#include "Depends.h"
#include "Init.h"
#include "Update.h"

/*
	Map working
	Pacman animation working
	Dots working
*/

int main()
{
	init_player_sprites();
	setMap();
	float counter = 0, anim_counter = 0;

	//game loop
	while (window.isOpen())
	{
		t = clk.restart();
		counter += t.asSeconds();
		anim_counter += t.asSeconds();
		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left))
					dir = 0;
				if (Keyboard::isKeyPressed(Keyboard::Right))
					dir = 1;
				if (Keyboard::isKeyPressed(Keyboard::Up))
					dir = 2;
				if (Keyboard::isKeyPressed(Keyboard::Down))
					dir = 3;
			default:
				break;
			}
		}

		//update functions
		//mx = Mouse::getPosition(window).x;
		//my = Mouse::getPosition(window).y;

		/*
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int hot = mx > ground[i][j].box.getPosition().x && mx < ground[i][j].box.getPosition().x + box_dimensions
					&& my > ground[i][j].box.getPosition().y && my < ground[i][j].box.getPosition().y + box_dimensions;

				if (hot && Mouse::isButtonPressed(Mouse::Button::Left)) {
					ground[i][j].box.setFillColor(Color::Black);
					ground[i][j].wall = 1;
				}
				if (hot && Mouse::isButtonPressed(Mouse::Button::Right)) {
					ground[i][j].box.setFillColor(Color::White);
					ground[i][j].wall = 0;
				}
			}
		}
		*/

		if (counter > 0.2) {
			pacman_movement();
			counter = 0;
		}
		if (anim_counter > 0.15) {
			set_animation();
			anim_counter = 0;
		}



		window.clear();
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
				window.draw(ground[i][j]);
		window.draw(Map);
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
				if (valid_dot[i][j])
					window.draw(Dot[i][j]);
		window.draw(Pacman);
		window.display();
	}
}