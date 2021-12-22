#include <Gamefunctions.hpp>

bool setupcheck() {
	sf::Image icon;
	if (!icon.loadFromFile("img/icon32.png"))
	{
		return false;
	}

	sf::Font font;
	if (!font.loadFromFile("fonts/Elfboyclassic.ttf")) {
		std::cout << "FONT ERROR";
		return false;
	}

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sounds/pop.ogg")) {
		std::cout << "AUDIO ERROR";
		return false;
	}

	sf::Texture texture;
	if (!texture.loadFromFile("img/background.png"))
	{
		std::cout << "BACKGROUND ERROR" << std::endl;
		return false;
	}
	sf::Texture textureblock;
	if (!textureblock.loadFromFile("img/block.png"))
	{
		std::cout << "BLOCK ERROR" << std::endl;
		return false;
	}
	sf::Texture textureplatform;
	if (!textureplatform.loadFromFile("img/platform.png"))
	{
		std::cout << "PLATFORM ERROR" << std::endl;
		return false;
	}
	sf::Texture textureball;
	if (!textureball.loadFromFile("img/ball.png"))
	{
		std::cout << "BALL ERROR" << std::endl;
		return false;
	}
	sf::Texture textureheart;
	if (!textureheart.loadFromFile("img/heart.png"))
	{
		std::cout << "HEART ERROR" << std::endl;
		return false;
	}
}

bool startgame() {

	int const window_x = 600;
	int const window_y = 800;

	rec::Rectangle block;
	block.setcoorx(0);
	block.setcoory(0);
	block.setwidht_x(100);
	block.setlenght_y(50);

	rec::Rectangle platform;
	platform.setcoorx(225);
	platform.setcoory(785);
	platform.setwidht_x(150);
	platform.setlenght_y(15);
	platform.setspeed(5.75);

	cir::Circle ball;
	ball.setcoorx(285);
	ball.setcoory(755);
	ball.setradius(15);
	ball.setspeed(5.75);

	cir::Circle heart;
	heart.setcoorx(25);
	heart.setcoory(25);
	heart.setradius(25);

	sf::RenderWindow window(sf::VideoMode(window_x, window_y), L"Арканоид");
	window.setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("img/icon32.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	sf::Font font;
	font.loadFromFile("fonts/Elfboyclassic.ttf");

	sf::SoundBuffer buffer;
	buffer.loadFromFile("sounds/pop.ogg");

	sf::Texture texture;
	texture.loadFromFile("img/background.png");

	sf::Texture textureblock;
	textureblock.loadFromFile("img/block.png");

	sf::Texture textureplatform;
	textureplatform.loadFromFile("img/platform.png");

	sf::Texture textureball;
	textureball.loadFromFile("img/ball.png");

	sf::Texture textureheart;
	textureheart.loadFromFile("img/heart.png");

	bool mousepressed = true;

	int kx = -1, ky = -1, sc = 0, h = 2;

	sf::Sprite blocks[30];
	sf::Sprite hearts[3];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			blocks[j * 6 + i].setPosition(i * (block.getwidht_x()), (j * block.getlenght_y()) + 100);
			blocks[j * 6 + i].setTexture(textureblock);
		}

	}

	for (int i = 0; i < 3; i++) {
		hearts[i].setTexture(textureheart);
		hearts[i].setPosition(25 + (i * (heart.getcoorx() + 50)), heart.getcoory());
	}

	sf::Sprite back;
	back.setTexture(texture);

	sf::Sound sound;
	sound.setBuffer(buffer);

	sf::Text score_text;
	score_text.setFont(font);
	score_text.setCharacterSize(70);
	score_text.setFillColor(sf::Color::Cyan);
	score_text.setString("Score:" + std::to_string(sc));
	score_text.setPosition(heart.getcoorx() + 300, 0);

	sf::Text lose;
	lose.setFont(font);
	lose.setCharacterSize(100);
	lose.setFillColor(sf::Color::Cyan);
	lose.setString("you lose!");
	lose.setPosition(1000, 0);

	sf::Text win;
	win.setFont(font);
	win.setCharacterSize(100);
	win.setFillColor(sf::Color::Cyan);
	win.setString("you win!");
	win.setPosition(1000, 0);

	sf::Text restart_text;
	restart_text.setFont(font);
	restart_text.setCharacterSize(24);
	restart_text.setFillColor(sf::Color::Blue);
	restart_text.setString("If you want to restart the game, press the space bar");
	restart_text.setPosition(1000, 0);


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		sf::Sprite playerball(textureball);
		playerball.setPosition(ball.getcoorx(), ball.getcoory());

		sf::Sprite playerplatform(textureplatform);
		playerplatform.setPosition(platform.getcoorx(), platform.getcoory());

		if (sc != 30 && h != -1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (platform.getcoorx() <= (window_x - platform.getwidht_x())) {
					platform.move_right(platform.getspeed());
					if (mousepressed) {
						ball.move_right(ball.getspeed());
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (platform.getcoorx() >= 0) {
					platform.move_left(platform.getspeed());
					if (mousepressed) {
						ball.move_left(ball.getspeed());
					}
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				mousepressed = false;
			}

			if (ball.getcoory() == window_y + (ball.getradius() * 2)) {
				mousepressed = true;

				ball.setcoorx(platform.getcoorx() + (platform.getwidht_x() / 2) - ball.getradius());
				ball.setcoory(platform.getcoory() - platform.getlenght_y() - ball.getradius());

				hearts[h].setPosition(1000, 0);
				h--;
			}

			if (mousepressed == false) {

				if (ball.getcoorx() < 0 || ball.getcoorx() > (window_x - (ball.getradius() * 2))) {
					kx = -kx;
				}
				if (ball.getcoory() < 100) {
					ky = -ky;
				}
				if (ball.getcoorx() > platform.getcoorx() - ball.getradius() && ball.getcoorx() < platform.getcoorx() + platform.getwidht_x() && ball.getcoory() > window_y - platform.getlenght_y() - (ball.getradius() * 2)) {
					ky = -ky;
				}

				sf::Vector2f bl[30];
				for (int i = 0; i < 30; i++) {
					bl[i] = blocks[i].getPosition();

					if (ball.getcoorx() > bl[i].x && ball.getcoorx() < bl[i].x + block.getwidht_x() || ball.getcoorx() < bl[i].x && ball.getcoorx() > bl[i].x + block.getwidht_x()) {
						if (ball.getcoory() > bl[i].y && ball.getcoory() < bl[i].y + block.getlenght_y()) {
							ky = -ky;
							sc++;

							sound.play();

							score_text.setString("Score:" + std::to_string(sc));

							blocks[i].setPosition(1000, 0);
						}
					}


				}

				ball.move_x(ball.getcoorx(), ball.getspeed() * kx);
				ball.move_y(ball.getcoory(), ball.getspeed() * ky);
			}
		}

		else if (h == -1) {

			ball.setcoorx(platform.getcoorx() + (platform.getwidht_x() / 2) - ball.getradius());
			ball.setcoory(platform.getcoory() - platform.getlenght_y() - ball.getradius());

			lose.setPosition(100, (window_y / 2) - lose.getCharacterSize());
			score_text.setCharacterSize(40);
			score_text.setPosition(window_x / 2 - 50, (window_y / 2) - 15);
			restart_text.setPosition(13, (window_y / 2) + 50);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				return true;

		}

		else if (sc == 30) {

			ball.setcoorx(platform.getcoorx() + (platform.getwidht_x() / 2) - ball.getradius());
			ball.setcoory(platform.getcoory() - platform.getlenght_y() - ball.getradius());

			win.setPosition(125, (window_y / 2) - win.getCharacterSize());
			score_text.setCharacterSize(40);
			score_text.setPosition(window_x / 2 - 75, (window_y / 2) - 15);
			restart_text.setPosition(13, (window_y / 2) + 50);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				return true;

		}


		window.clear();

		window.draw(back);

		for (int i = 0; i < 6;i++) {
			for (int j = 0; j < 5; j++) {
				window.draw(blocks[j * 6 + i]);
			}
		}
		for (int i = 0; i < 3; i++) {
			window.draw(hearts[i]);
		}
		window.draw(score_text);
		window.draw(lose);
		window.draw(win);
		window.draw(restart_text);
		window.draw(playerplatform);
		window.draw(playerball);


		window.display();
	}

	return 0;
}

void gamerunning() {
	if (startgame())
		gamerunning();
}