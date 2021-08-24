#pragma once
#include "card.h"
#include "game.h"

class Player {
    friend bool Game::win();
    Card AllCards[9]={}; // больше 9 карт всегда будет больше 21
                     // (минимальное значение из 9 карт - 4 двойки, 4 тройки, 1 четверка - 24, из 8ми карт - 20)
    public:
       Player() {
       // конструктор будет пустым чтобы все действия были в Game::step();
       }
       void showAllCardsOpen() const {
       // метод показывает на экране все карты открытыми. Метод по умолчанию для игрока, он же метод для дилера после
       // чьего либо выигрыша.
       }
       void getPlayerCardsFromDeck(DeckOfCards & deck) {
	 // при первом вызове берёт из колоды 2 карты и копирует в AllCards, при последующих
         // метод запрашивает пользователя сколько карт взять из колоды и копирует их в AllCards, вызов только из Player
       }
       int cardSumm() {
         // метод считает очки на картах из AllCards
	 return 21; // FIXME
       }

};



