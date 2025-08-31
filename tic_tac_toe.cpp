#include<iostream>
#include<cmath>
#include<SFML/Graphics.hpp>

//App created usgin SFML 3.0
int ScreenWidth = 1100;
int ScreenHeight = 1100;
sf::Font font("ArialMT.ttf");
sf::Text label2(font, sf::String(" "), 50);
sf::Text table[9] = { sf::Text(font, sf::String(" "), 300) , sf::Text(font, sf::String(" "), 300) , sf::Text(font, sf::String(" "), 300) , sf::Text(font, sf::String(" "), 300) , sf::Text(font, sf::String(" "), 300) , sf::Text(font, sf::String(" "), 300) ,sf::Text(font, sf::String(" "), 300) ,sf::Text(font, sf::String(" "), 300) ,sf::Text(font, sf::String(" "), 300) };

bool check_position(int pos)
{
	
	if (table[pos].getString() == " ")
		return true;
	else
		return false;
}
int check_win()
{
	
	if (table[0].getString() == "X" && table[1].getString() == "X" && table[2].getString() == "X")
		label2.setString("Player win");
	else if (table[3].getString() == "X" && table[4].getString() == "X" && table[5].getString() == "X")
		label2.setString("Player win");
	else if (table[6].getString() == "X" && table[7].getString() == "X" && table[8].getString() == "X")
		label2.setString("Player win");
	else if (table[0].getString() == "X" && table[3].getString() == "X" && table[6].getString() == "X")
		label2.setString("Player win");
	else if (table[1].getString() == "X" && table[4].getString() == "X" && table[7].getString() == "X")
		label2.setString("Player win");
	else if (table[2].getString() == "X" && table[5].getString() == "X" && table[8].getString() == "X")
		label2.setString("Player win");
	else if (table[0].getString() == "X" && table[4].getString() == "X" && table[8].getString() == "X")
		label2.setString("Player win");
	else if (table[2].getString() == "X" && table[4].getString() == "X" && table[6].getString() == "X")
		label2.setString("Player win");
	if (table[0].getString() == "O" && table[1].getString() == "O" && table[2].getString() == "O")
		label2.setString("Computer win");
	else if (table[3].getString() == "O" && table[4].getString() == "O" && table[5].getString() == "O")
		label2.setString("Computer win");
	else if (table[6].getString() == "O" && table[7].getString() == "O" && table[8].getString() == "O")
		label2.setString("Computer win");
	else if (table[0].getString() == "O" && table[3].getString() == "O" && table[6].getString() == "O")
		label2.setString("Computer win");
	else if (table[1].getString() == "O" && table[4].getString() == "O" && table[7].getString() == "O")
		label2.setString("Computer win");
	else if (table[2].getString() == "O" && table[5].getString() == "O" && table[8].getString() == "O")
		label2.setString("Computer win");
	else if (table[0].getString() == "O" && table[4].getString() == "O" && table[8].getString() == "O")
		label2.setString("Computer win");
	else if (table[2].getString() == "O" && table[4].getString() == "O" && table[6].getString() == "O")
		label2.setString("Computer win");
	if (label2.getString() == "Player win")
		return 2;
	if (label2.getString() == "Computer win")
		return 3;
	if (table[0].getString() != " " && table[1].getString() != " " && table[2].getString() != " " &&
		table[3].getString() != " " && table[4].getString() != " " && table[5].getString() != " " &&
		table[6].getString() != " " && table[7].getString() != " " && table[8].getString() != " ")
		{
		label2.setString("Draw");
		return 1;
		}
	return 0;
}
void computer_move()
{
	int position = rand() % 9;
	while (!check_position(position))
	{
		position = rand() % 9;
	}
	switch (position)
	{
	case 0:
		table[0].setString("O");
		table[0].setPosition({ 100, 100 });
		break;
	case 1:
		table[1].setString("O");
		table[1].setPosition({ 400, 100 });
		break;
	case 2:
		table[2].setString("O");
		table[2].setPosition({ 700, 100 });
		break;
	case 3:
		table[3].setString("O");
		table[3].setPosition({ 100, 400 });
		break;
	case 4:
		table[4].setString("O");
		table[4].setPosition({ 400, 400 });
		break;
	case 5:
		table[5].setString("O");
		table[5].setPosition({ 700, 400 });
		break;
	case 6:
		table[6].setString("O");
		table[6].setPosition({ 100, 700 });
		break;
	case 7:
		table[7].setString("O");
		table[7].setPosition({ 400, 700 });
		break;
	case 8:
		table[8].setString("O");
		table[8].setPosition({ 700, 700 });
		break;
	default:
		break;
	}
	if (check_win() == 1)
	{
		std::cout << "Draw";
		while (true);
	}
	else if (check_win() == 2)
	{
		std::cout << "Player win";
		while (true);

	}
	else if (check_win() == 3)
	{
		std::cout << "Computer win";
		while (true);

	}
}
void player_move(int pos)
{
	if (!check_position(pos))
	{
		label2.setString("Position already taken");
	}
	else if (check_position(pos))
	{
		switch (pos)
		{
		case 0:
			table[0].setString("X");
			table[0].setPosition({ 100, 100 });
			label2.setString("X set in 1-st place");
			break;
		case 1:
			table[1].setString("X");
			table[1].setPosition({ 400, 100 });
			label2.setString("X set in 2-nd place");
			break;
		case 2:
			table[2].setString("X");
			table[2].setPosition({ 700, 100 });
			label2.setString("X set in 3-rd place");
			break;
		case 3:
			table[3].setString("X");
			table[3].setPosition({ 100, 400 });
			label2.setString("X set in 4-th place");
			break;
		case 4:
			table[4].setString("X");
			table[4].setPosition({ 400, 400 });
			label2.setString("X set in 5-th place");
			break;
		case 5:
			table[5].setString("X");
			table[5].setPosition({ 700, 400 });
			label2.setString("X set in 6-th place");
			break;
		case 6:
			table[6].setString("X");
			table[6].setPosition({ 100, 700 });
			label2.setString("X set in 7-th place");
			break;
		case 7:
			table[7].setString("X");
			table[7].setPosition({ 400, 700 });
			label2.setString("X set in 8-th place");
			break;
		case 8:
			table[8].setString("X");
			table[8].setPosition({ 700, 700 });
			label2.setString("X set in 9-th place");
			break;
		default:
			break;
		}
		if (check_win() == 1)
		{
			std::cout << "Draw";
			while (true);
		}
		else if (check_win() == 2)
		{
			std::cout << "Player win";
			while (true);

		}
		else if (check_win() == 3)
		{
			std::cout << "Computer win";
			while (true);

		}
		

		computer_move();

	}
}

int main() {
	sf::VideoMode vm({ static_cast<unsigned int>(ScreenWidth), static_cast<unsigned int>(ScreenHeight) });
	sf::RenderWindow window(vm, "Window");
	sf::Clock clock;
	sf::Text label(font, sf::String("0"), 50);



	sf::RectangleShape Vertical_line1({ 5, 900 });
	sf::RectangleShape Vertical_line2({ 5, 900 });
	sf::RectangleShape Horizontal_line1({ 900, 5 });
	sf::RectangleShape Horizontal_line2({ 900, 5 });

	Vertical_line1.setPosition({ 400, 100 });
	Vertical_line2.setPosition({ 700, 100 });
	Horizontal_line1.setPosition({ 100, 400 });
	Horizontal_line2.setPosition({ 100, 700 });

	Vertical_line1.setFillColor(sf::Color::Black);
	Vertical_line2.setFillColor(sf::Color::Black);
	Horizontal_line1.setFillColor(sf::Color::Black);
	Horizontal_line2.setFillColor(sf::Color::Black);

	clock.start();
	label.setPosition({ 50, 50 });
	label2.setPosition({ 550, 50 });


	while (window.isOpen()) {

		while (std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			else if (event->is<sf::Event::Resized>())
			{
				sf::View view(sf::FloatRect({ 0.f, 0.f }, sf::Vector2f(window.getSize())));
				window.setView(view);
			}
			if (event->is<sf::Event::MouseButtonPressed>())
			{
				if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 400 &&
					sf::Mouse::getPosition(window).y > 100 && sf::Mouse::getPosition(window).y < 400)
				{
					player_move(0);
				}
				if (sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 700 &&
					sf::Mouse::getPosition(window).y > 100 && sf::Mouse::getPosition(window).y < 400)
				{
					player_move(1);
				}
				if (sf::Mouse::getPosition(window).x > 700 && sf::Mouse::getPosition(window).x < 1000 &&
					sf::Mouse::getPosition(window).y > 100 && sf::Mouse::getPosition(window).y < 400)
				{
					player_move(2);
				}
				if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 400 &&
					sf::Mouse::getPosition(window).y > 400 && sf::Mouse::getPosition(window).y < 700)
				{
					player_move(3);
				}
				if (sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 700 &&
					sf::Mouse::getPosition(window).y > 400 && sf::Mouse::getPosition(window).y < 700)
				{
					player_move(4);
				}
				if (sf::Mouse::getPosition(window).x > 700 && sf::Mouse::getPosition(window).x < 1000 &&
					sf::Mouse::getPosition(window).y > 400 && sf::Mouse::getPosition(window).y < 700)
				{
					player_move(5);
				}
				if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 400 &&
					sf::Mouse::getPosition(window).y > 700 && sf::Mouse::getPosition(window).y < 1000)
				{
					player_move(6);
				}
				if (sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 700 &&
					sf::Mouse::getPosition(window).y > 700 && sf::Mouse::getPosition(window).y < 1000)
				{
					player_move(7);
				}
				if (sf::Mouse::getPosition(window).x > 700 && sf::Mouse::getPosition(window).x < 1000 &&
					sf::Mouse::getPosition(window).y > 700 && sf::Mouse::getPosition(window).y < 1000)
				{
					player_move(8);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
			window.close();





		window.clear(sf::Color::Red);
		window.draw(label);
		window.draw(label2);
		window.draw(Vertical_line1);
		window.draw(Vertical_line2);
		window.draw(Horizontal_line1);
		window.draw(Horizontal_line2);
		for (int i = 0; i < 9; i++)
		{
			window.draw(table[i]);
		}
		

		window.display();
		int time = clock.getElapsedTime().asSeconds();
		label.setString(std::to_string(time));
		
	}
	return 0;
}