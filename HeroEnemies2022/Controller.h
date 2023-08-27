#pragma once
#include "Enemy.h"
#include "Hero.h"
#include <vector>

using namespace std;

class Controller {
private:
	Hero* hero;
	vector<Enemy*> Jugador2;

public:
	Controller(Bitmap^ bmpHero, Bitmap^ bmpEnemy) {
		hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);
		//Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 0));
		//Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 1));
		//Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 2));
		Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 3));
		Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 3));
		Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 3));
		Jugador2.push_back(new Enemy(bmpEnemy->Width / 6, bmpEnemy->Height / 4, 3));
	}

	~Controller() {}

	void drawEverything(Graphics^ g, Bitmap^ bmpHero, Bitmap^ bmpEnemy) {
		hero->draw(g, bmpHero);
		for (int i = 0; i < Jugador2.size(); i++) {
			Jugador2[i]->draw(g, bmpEnemy);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < Jugador2.size(); i++) {
			Jugador2[i]->move(g, hero);
		}
	}

	void collision() {
		//Verification
		for (int i = 0; i < Jugador2.size(); i++) {
			if (hero->getRectangle().IntersectsWith(Jugador2[i]->getRectangle())) {
				hero->decreaseHp();
				Jugador2[i]->setVisible(false);
			}
		}
		
		//Elimination
		for (int i = 0; i < Jugador2.size(); i++) {
			if (!Jugador2[i]->getVisible()) {
				Jugador2.erase(Jugador2.begin() + i);
			}
		}
	}

	Hero* getHero() { return hero; }
};