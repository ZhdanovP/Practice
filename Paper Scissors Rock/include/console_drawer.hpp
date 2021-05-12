#ifndef CONSOLE_DRAWER_HPP
#define CONSOLE_DRAWER_HPP

#include <iostream>
#include "symbol.hpp"
#include "rock.hpp"
#include "scissors.hpp"
#include "paper.hpp"

class ConsoleDrawer : public Drawer {
public:

	ConsoleDrawer()
		: m_border_symbol('-')
		, m_border_length(50)
		, m_indent_length(4) {}

	void ShowMainScreen(
		const std::vector<std::shared_ptr<Symbol> > symbols) override {
		PrintInLoop(m_indent_length, '\t');
		PrintInLoop(m_border_length, m_border_symbol);

		std::cout << std::endl;
		PrintInLoop(m_indent_length, '\t');
		std::cout << "\t Welcome to the Game" << std::endl;

		PrintInLoop(m_indent_length, '\t');
		PrintInLoop(m_border_length, m_border_symbol);

		std::cout << std::endl;
		PrintInLoop(m_indent_length, '\t');
		std::cout << "\t Type: " << std::endl;
		PrintInLoop(m_indent_length, '\t');

		for (auto s : symbols) {
			const char first_letter = tolower(s->GetName()[0]);
			std::cout 	<< "\t\t "
						<< first_letter << " : "
						<< s->GetName()
						<< std::endl;
			PrintInLoop(m_indent_length, '\t');
		}

		std::cout << std::endl << std::endl;

		PrintInLoop(m_indent_length, '\t');
		PrintInLoop(m_border_length, m_border_symbol);

		std::cout << std::endl;
	}

	std::string GetPlayerName() override {
		std::cout << "Enter your name: ";
		std::string name;
		std::cin >> name;
		return name;
	}

	void ShowChoose(const Player& first, const Player& second) override {
		PrintInLoop(m_indent_length, '\t');
		std::cout 	<< first.GetName() << ": "
					<< first.GetSymbol().GetName() << "\n";
		PrintInLoop(m_indent_length, '\t');
		std::cout 	<< second.GetName() << ": "
					<< second.GetSymbol().GetName() << "\n";
	}

	std::shared_ptr<Symbol> PlayerChoose() override {
		PrintInLoop(m_indent_length, '\t');
        std::cout << "Enter your choice: ";
		char input;
		std::cin >> input;
		if ('r' == input) {
			return std::make_shared<Rock>();
		} else if ('p' == input) {
			return std::make_shared<Paper>();
		} else if ('s' == input) {
			return std::make_shared<Scissors>();
		}
		return nullptr;
	}

	void Hurray() override {
		PrintInLoop(m_indent_length, '\t');
		std::cout << "You won! Hurray" << std::endl;
	}

	void Loose() override {
		PrintInLoop(m_indent_length, '\t');
		std::cout << "You lose! Bad Luck" << std::endl;
	}

	void Tie() override {
		PrintInLoop(m_indent_length, '\t');
		std::cout << "Woah! That's Tie!" << std::endl;
	}

	bool IsContinue() override {
		PrintInLoop(m_indent_length, '\t');
        std::cout << "Do you want to Play Again?" << std::endl;
        PrintInLoop(m_indent_length, '\t');
        std::cout << "Note: Press 'n' to exit! Press 'y' to continue: ";

        char playmore;
        std::cin >> playmore;

        PrintInLoop(m_indent_length, '\t');
        PrintInLoop(m_border_length, m_border_symbol);
        std::cout << std::endl;

        return playmore != 'n';
	}

	void GoodByeScreen() override {
		PrintInLoop(m_indent_length, '\t');
		std::cout << "Goodbye!";
	}

private:

	void PrintInLoop(const int num, const char symbol) {
		for(size_t i = 0; i < num; ++i){
		    std::cout << symbol;
		}
	}

private:

	char m_border_symbol;
	size_t m_border_length;
	size_t m_indent_length;
};

#endif  // CONSOLE_DRAWER_HPP