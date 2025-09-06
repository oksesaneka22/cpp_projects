#include<iostream>
#include<cmath>
#include<SFML/Graphics.hpp>
int ScreenWidth = 800;
int ScreenHeight = 1200; 
sf::Font font("ArialMT.ttf");
sf::Text text(font, "", 120);
std::string result(std::string str);
class button {
		
	public:
		sf::RectangleShape btn;
		sf::Text symbol = sf::Text(font);
		sf::Color color = sf::Color(230, 255, 230);
		int x = 0;
		int y = 0;
		sf::FloatRect bounds = symbol.getLocalBounds();

		void create(std::string text, int position)
		{
			


			btn.setSize({ static_cast<float>(ScreenWidth)/3 - static_cast<float>(ScreenWidth)/20, static_cast<float>(ScreenHeight-300)/6 - static_cast<float>(ScreenHeight) / 30 });
			
			if (position % 3 == 1)
			{
				x = ((ScreenWidth / 20)*3)/4;
			}
			else if (position % 3 == 2)
			{
				x = ScreenWidth - 2*btn.getSize().x - 2*(((ScreenWidth / 20) * 3) / 4);
			}
			else
			{
				x = ScreenWidth - btn.getSize().x - ((ScreenWidth / 20) * 3) / 4;

			}
			if (position <= 3)
			{
				y = 300 + ((ScreenWidth / 30) * 6) / 7;
			}
			else if (position <= 6)
			{
				y = 300 + btn.getSize().y + 2*((ScreenWidth / 30) * 6) / 7;
			}
			else if (position <= 9)
			{
				y = 300 + 2 * (btn.getSize().y + 2*((ScreenWidth / 30) * 6) / 7);
			}
			else if (position <= 12)
			{
				y = 300 + 3 * (btn.getSize().y + 2*((ScreenWidth / 30) * 6) / 7);
			}
			else if (position <= 15)
			{
				y = 300 + 4 * (btn.getSize().y + 2 * ((ScreenWidth / 30) * 6) / 7);
			}
			else if (position <= 18)
			{
				y = 300 + 5 * (btn.getSize().y + 2 * ((ScreenWidth / 30) * 6) / 7);
			}
			symbol.setString("7");
			symbol.setFillColor(sf::Color::Black);
			symbol.setCharacterSize(100);
			symbol.setPosition({ static_cast<float>(x) + (btn.getSize().x)/2 - 25, static_cast<float>(y) - 70 + (btn.getSize().y) / 2 });
			btn.setPosition({ static_cast<float>(x), static_cast<float>(y) });
			btn.setFillColor(color);
			
		}
		void SetColor(sf::Color newColor)
		{
			btn.setFillColor(newColor);
		}
		void press()
		{
			if (symbol.getString() != '<' && symbol.getString() != 'C' && symbol.getString() != '=')
			{
				text.setString(text.getString() + symbol.getString());
			}
			else
				{
				if (symbol.getString() == '<')
				{
					if (!text.getString().isEmpty())
						text.setString(text.getString().substring(0, text.getString().getSize() - 1));
				}
				else if (symbol.getString() == 'C')
				{
					text.setString("");
				}
				else if (symbol.getString() == '=')
				{
					std::string userInput = text.getString().toAnsiString();
					text.setString(result(userInput));
				}

			}
			sf::sleep(sf::milliseconds(300));


			
		}
};

button btn[18];

std::string formatResult(float result) {
	std::ostringstream out;
	out << std::fixed << std::setprecision(6) << result; // Start with 6 decimals

	std::string str = out.str();
	str.erase(str.find_last_not_of('0') + 1, std::string::npos); // Remove trailing zeros
	if (!str.empty() && str.back() == '.') // Remove trailing dot if integer
		str.pop_back();

	return str;
}

std::string result(std::string str) {
	if (str.empty()) return "Error";
	for (char c : str) {
		if (!(isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '.')) {
			std::cout << "Error: Invalid character '" << c << "' in input string." << std::endl;
			return "Error";
		}
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (str.find(c) != str.rfind(c)) {
				std::cout << "Error: Multiple '" << c << "' operators found." << std::endl;
				return "Error";
			}
		}
		//error if first or second part is empty
		if ((c == '+' || c == '-' || c == '*' || c == '/') && (str.find(c) == 0 || str.find(c) == str.length() - 1)) {
			std::cout << "Error: Operator '" << c << "' cannot be at the start or end of the input string." << std::endl;
			return "Error";
		}
	}
	float result = 0;
	char operator_char;
	if (str.find('+') != std::string::npos) {
		operator_char = '+';
	}
	else if (str.find('-') != std::string::npos) {
		operator_char = '-';
	}
	else if (str.find('*') != std::string::npos) {
		operator_char = '*';
	}
	else if (str.find('/') != std::string::npos) {
		operator_char = '/';
	}
	else {
		std::cout << "Error: No operator found in input string." << std::endl;
		return "Error";
	}
	int operator_pos = str.find(operator_char);
	std::string first_part = str.substr(0, operator_pos);
	std::string second_part = str.substr(operator_pos + 1);
	//find which operator is used
	std::cout << "Operator found: " << operator_char << std::endl;
	switch (operator_char) {
	case '+':
		result = std::stof(first_part) + std::stof(second_part);
		break;
	case '-':
		result = std::stof(first_part) - std::stof(second_part);
		break;
	case '*':
		result = std::stof(first_part) * std::stof(second_part);
		break;
	case '/':
		if (std::stof(second_part) == 0) {
			std::cout << "Error: Division by zero." << std::endl;
			return "Error";
		}
		result = std::stof(first_part) / std::stof(second_part);
		break;
	default:
		std::cout << "Error: No valid operator found." << std::endl;
		return "Error";
	}

	return formatResult(result);
}

int main() {
	sf::VideoMode vm({ static_cast<unsigned int>(ScreenWidth), static_cast<unsigned int>(ScreenHeight) });
	sf::RenderWindow window(vm, "Window");
	sf::Text label(font, "Calculator", 100);
	label.setPosition({ 10.f, 0.f });
	label.setOutlineThickness(5.f);
	label.setOutlineColor(sf::Color::Black);
	label.setFillColor(sf::Color(0,0,153));
	sf::RectangleShape inputBox;
	inputBox.setSize({ 800.f, 200.f });
	inputBox.setFillColor(sf::Color::White);
	inputBox.setOutlineColor(sf::Color::Black);
	inputBox.setOutlineThickness(-10.f);
	inputBox.setPosition({ 0.f, 100.f });
	text.setPosition({ inputBox.getPosition().x + 10.f, inputBox.getPosition().y + 10.f });
	text.setFillColor(sf::Color::Black);
	std::string userInput = text.getString().toAnsiString();

	btn[0].symbol.setString("7");

	for (int i = 0; i < 18; i++)
	{
		btn[i].create("=", i + 1);
		btn[i].symbol.setFont(font);
		//symbol.setPosition({ (btn.getPosition().x + (btn.getSize().x) / 2), (btn.getPosition().y + (btn.getSize().y) / 2) });


	}
	btn[0].symbol.setString("1");
	btn[1].symbol.setString("2");
	btn[2].symbol.setString("3");
	btn[3].symbol.setString("4");
	btn[4].symbol.setString("5");
	btn[5].symbol.setString("6");
	btn[6].symbol.setString("7");
	btn[7].symbol.setString("8");
	btn[8].symbol.setString("9");
	btn[9].symbol.setString("-");
	btn[10].symbol.setString("0");
	btn[11].symbol.setString("+");
	btn[12].symbol.setString("*");
	btn[13].symbol.setString("/");
	btn[14].symbol.setString("<");
	btn[15].symbol.setString("C");
	btn[16].symbol.setString(".");
	btn[17].symbol.setString("=");


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

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
				window.close();
			if (auto* key = event->getIf<sf::Event::KeyPressed>())
			{
				switch (key->scancode)
				{
				case sf::Keyboard::Scancode::Num0:
				case sf::Keyboard::Scancode::Num1:
				case sf::Keyboard::Scancode::Num2:
				case sf::Keyboard::Scancode::Num3:
				case sf::Keyboard::Scancode::Num4:
				case sf::Keyboard::Scancode::Num5:
				case sf::Keyboard::Scancode::Num6:
				case sf::Keyboard::Scancode::Num7:
				case sf::Keyboard::Scancode::Num8:
				case sf::Keyboard::Scancode::Num9:
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::RShift))
					text.setString(text.getString() + sf::Keyboard::getDescription(key->scancode).toAnsiString());
					break;
				default:
					break;
				}
			}
			if (auto* key = event->getIf<sf::Event::KeyPressed>())
			{
				switch (key->scancode)
				{
				case sf::Keyboard::Scancode::Backspace:
					if (!text.getString().isEmpty())
						text.setString(text.getString().substring(0, text.getString().getSize() - 1));
					break;
				case sf::Keyboard::Scancode::Period:
					text.setString(text.getString() + ".");
					break;
				case sf::Keyboard::Scancode::Equal:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::RShift))
						text.setString(text.getString() + "+");
					break;
				case sf::Keyboard::Scancode::Hyphen:
					text.setString(text.getString() + "-");
					break;
				case sf::Keyboard::Scancode::Num8:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::RShift))
						text.setString(text.getString() + "*");
					break;
				case sf::Keyboard::Scancode::Slash:
					text.setString(text.getString() + "/");
					break;
				case sf::Keyboard::Scancode::Enter:
					userInput = text.getString().toAnsiString();
					text.setString(result(userInput));

					break;
				default:
					break;
				}

			}
			//button press with mouse event handled below
			

				
		}
		
		
		for (int i = 0; i < 18; i++)
		{
			if (sf::Mouse::getPosition(window).x >= btn[i].x && sf::Mouse::getPosition(window).x <= btn[i].x + btn[i].btn.getSize().x && sf::Mouse::getPosition(window).y >= btn[i].y && sf::Mouse::getPosition(window).y <= btn[i].y + btn[i].btn.getSize().y)
			{
				btn[i].SetColor(sf::Color::Blue);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					btn[i].SetColor(sf::Color::Yellow);
					btn[i].press();

				}
				
			}
			else
				btn[i].SetColor(sf::Color(230, 255, 230));
		}


		


		window.clear(sf::Color(204, 255, 255));

		for (int i = 0; i < 18; i++)
		{
			window.draw(btn[i].btn);
			window.draw(btn[i].symbol);
		}
		

		window.draw(inputBox);
		window.draw(text);
		window.draw(label);



		window.display();
		

	}
	return 0;
}