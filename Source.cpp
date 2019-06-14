#include "Game.h"
#include <SFML/Graphics.hpp>


void menu(RenderWindow & window) {
	Texture menu_texture1, menu_texture2, menu_texture3, about_texture;
	menu_texture1.loadFromFile("111.png");
	menu_texture2.loadFromFile("222.png");
	menu_texture3.loadFromFile("333.png");
	about_texture.loadFromFile("about.png");
	Sprite menu1(menu_texture1), menu2(menu_texture2), menu3(menu_texture3), about(about_texture);
	bool Menu = 1;
	int MenuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);


	/////меню
	while (Menu)
	{
		int numberLevel = 1;//сначала 1-ый уровень
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		MenuNum = 0;
		window.clear(Color(0, 0, 0));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); MenuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); MenuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); MenuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuNum == 1) {
				window.close();
				Menu = false;
				RunGame(numberLevel);
			}
			if (MenuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (MenuNum == 3) { window.close(); Menu = false; }

		}


		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}
int main()
{
	
	RenderWindow window(VideoMode(450, 280), "The Game!");
	int numberLevel = 1;//сначала 1-ый уровень
	menu(window);
	menu(window);
	return 0;
}
