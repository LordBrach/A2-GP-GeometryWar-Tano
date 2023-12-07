#include "MainMenu.h"

MainMenu::MainMenu()
{
	// input ui setup
	if (!uiFont.loadFromFile("../Fonts/slkscr.ttf"))
	{
		std::cout << "Couldnt load font" << std::endl;
		// throw err instead maybe this is just for debug for now
	}
	uiText.setFont(uiFont);
	uiText.setString("{ PRESS ENTER TO PLAY }");
	uiText.setCharacterSize(24);
	uiText.setFillColor(sf::Color::White);
	uiText.setPosition(1920.f * 0.43f, 1080.f * 0.42f);

	_uiFlashDelay = 0.66f;
	// title drawing setup
	size = 100;
	StartPos = { 1920.f * 0.35f, 1080.f * 0.3f };
	currentPos = std::get<0>(StartPos);
	increment += 50;
	CreateLetter('h'); //ptdr, si j'ai le temps je fait plus clean
	TitleVector[0].setScale(2.0f, 2.0f);
	increment -= 50;
	CreateLetter('i');
	CreateLetter('r');
	CreateLetter('a');
	CreateLetter('i');
	CreateLetter('s');
	CreateLetter('h');
	CreateLetter('i');
	CreateLetter('n');
	// extra
	CreateStar();
}

MainMenu::~MainMenu(){}

std::vector<sf::ConvexShape> MainMenu::GetTitle()
{
	return TitleVector;
}
sf::Text MainMenu::GetUIText()
{
	return uiText;
}
sf::ConvexShape MainMenu::GetVictoryStar()
{
	return  victoryStar;
}

void MainMenu::CreateLetter(char which_letter)
{
	sf::ConvexShape LetterTest;
	switch (which_letter)
	{
	case('h'):
		LetterTest.setPointCount(12);
		//									H	V
		//TOP LEFT
		LetterTest.setPoint(0, sf::Vector2f(0.f, 0.f));
		LetterTest.setPoint(1, sf::Vector2f(10.f, 10.f));
		LetterTest.setPoint(2, sf::Vector2f(10.f, 40.f));
		// TOP RIGHT
		LetterTest.setPoint(3, sf::Vector2f(30.f, 40.f));
		LetterTest.setPoint(4, sf::Vector2f(30.f, 10.f));
		LetterTest.setPoint(5, sf::Vector2f(40.f, 0.f));
		// RIGHT LINE
		LetterTest.setPoint(6, sf::Vector2f(40.f, 100.f));
		//BOTTOM RIGHT
		LetterTest.setPoint(7, sf::Vector2f(30.f, 90.f));
		LetterTest.setPoint(8, sf::Vector2f(30.f, 80.f));
		LetterTest.setPoint(9, sf::Vector2f(10.f, 80.f));
		// BOTTOM LEFT
		LetterTest.setPoint(10, sf::Vector2f(10.f, 100.f));
		LetterTest.setPoint(11, sf::Vector2f(0.f, 90.f));
		break;
	case('i'):
		LetterTest.setPointCount(4);
		LetterTest.setPoint(0, sf::Vector2f(15.0f, 1.0f));
		LetterTest.setPoint(1, sf::Vector2f(30.0f, 90.0f));
		LetterTest.setPoint(2, sf::Vector2f(15.0f, 100.0f));
		LetterTest.setPoint(3, sf::Vector2f(0.f, 90.0f));
		break;
	case('r'):
		LetterTest.setPointCount(5);
		LetterTest.setPoint(0, sf::Vector2f(0.f, 10.f));
		LetterTest.setPoint(1, sf::Vector2f(15.0f, 0.0f));
		LetterTest.setPoint(2, sf::Vector2f(45.0f, 10.0f));
		LetterTest.setPoint(3, sf::Vector2f(15.f, 60.0f));
		LetterTest.setPoint(4, sf::Vector2f(10.f, 100.0f));
		break;
	case('a'):
		LetterTest.setPointCount(4);
		LetterTest.setPoint(0, sf::Vector2f(15.0f, 1.0f));
		LetterTest.setPoint(1, sf::Vector2f(30.0f, 100.0f));
		LetterTest.setPoint(2, sf::Vector2f(15.0f, 80.0f));
		LetterTest.setPoint(3, sf::Vector2f(0.f, 100.0f));
		break;
	case('s'):
		LetterTest.setPointCount(7);
		LetterTest.setPoint(0, sf::Vector2f(5.0f, 15.0f));
		LetterTest.setPoint(1, sf::Vector2f(15.0f, 0.0f));
		LetterTest.setPoint(2, sf::Vector2f(40.0f, 10.0f));
		LetterTest.setPoint(3, sf::Vector2f(10.0f, 20.0f));
		LetterTest.setPoint(4, sf::Vector2f(45.f, 90.0f));
		LetterTest.setPoint(5, sf::Vector2f(0.f, 100.0f));
		LetterTest.setPoint(6, sf::Vector2f(10.f, 70.0f));
		break;
	case('n'):
		LetterTest.setPointCount(6);
		LetterTest.setPoint(0, sf::Vector2f(0.f, 90.0f));
		LetterTest.setPoint(1, sf::Vector2f(15.0f, 5.0f));
		LetterTest.setPoint(2, sf::Vector2f(30.0f, 60.0f));
		LetterTest.setPoint(3, sf::Vector2f(45.0f, 0.0f));
		LetterTest.setPoint(4, sf::Vector2f(40.0f, 100.0f));
		LetterTest.setPoint(5, sf::Vector2f(20.0f, 70.0f));

		break;
	default:
		break;
	}

	AddToVector(LetterTest);
}

void MainMenu::AddToVector(sf::ConvexShape SingleLetter)
{
	// Maybe change letter color each time or once before
	// If possible change scale using size value

	// Set position
	SingleLetter.setPosition(currentPos, std::get<1>(StartPos));
	// Add letter to array
	TitleVector.push_back(SingleLetter);
	// Increment position
	currentPos += increment;
}

void MainMenu::CheckClock()
{
	float deltaTime = this->_MenuClock.getElapsedTime().asSeconds();

	_MenuClock.restart();
	_timeElapsed += deltaTime;
	if (_timeElapsed > this->_uiFlashDelay) {
		// Do what you need here
		BlinkUI();
		_timeElapsed = 0;
	}
}

void MainMenu::BlinkUI()
{
	if (uiText.getFillColor() == sf::Color::White) {
		uiText.setFillColor(sf::Color::Black);
	} else {
		uiText.setFillColor(sf::Color::White);
	}
}

void MainMenu::CreateStar()
{
	victoryStar.setFillColor(sf::Color::Yellow);
	victoryStar.setPosition(1920.f * 0.9f, 1080.f * 0.05f);
	victoryStar.setPointCount(8);
	// leftmost point
	victoryStar.setPoint(0, sf::Vector2f(0.0f, 45.0f));
	victoryStar.setPoint(1, sf::Vector2f(15.0f, 40.0f));
	// top point
	victoryStar.setPoint(2, sf::Vector2f(20.0f, 5.0f));
	victoryStar.setPoint(3, sf::Vector2f(25.0f, 40.0f));
	// rightmost point
	victoryStar.setPoint(4, sf::Vector2f(40.0f, 45.0f));
	victoryStar.setPoint(5, sf::Vector2f(25.0f, 50.0f));
	// bottom point
	victoryStar.setPoint(6, sf::Vector2f(20.0f, 75.0f));
	victoryStar.setPoint(7, sf::Vector2f(15.0f, 50.0f));
}