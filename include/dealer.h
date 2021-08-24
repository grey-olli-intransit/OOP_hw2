#pragma once
#include "deckofcards.h"
#include "player.h"
#include "game.h"
class Dealer:public Player {
   friend bool Game::win();
   public:
      Dealer() {
       // конструктор будет пустым чтобы все действия были в Game::step();
      }
      void showFirstCardOpen() const {
       // метод печатает на экране карты дилера с одной картой открытой (1й шаг и последующие пока не будет выигрыша у кого-то)
      }
      void getDealerCardsFromDeck(DeckOfCards & deck) {
         // метод берёт из колоды по 1 карте и копирует их в AllCards, вызов только из Dealer
      }
};

