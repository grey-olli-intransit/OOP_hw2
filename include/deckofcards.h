#pragma once
#include "card.h"
// колода карт
class DeckOfCards {
    // в колоде по 4 карты достоинством 2,3,4,5,6,7,8,9,10,валет,дама,король,туз
    Card AllCards[52];
    public:
        int lastCardIndex; // индекс верхней карты в колоде (0..cardsCount-1) (осталась верхней в колоде после раздачи)
        DeckOfCards() {
	  init();
	  //shuffle(); // будет в Game::fistStep()
	}
        void init() {
	  // метод присваивающий значения массиву AllCards
	}
        void shuffle() {
	  // метод "тасующий" массив AllCards, записывает в индекс карты indexInDeck случайное и
	  //  не повторяющееся число в диапазоне 0..51
	}
	Card getCard() {
	  // метод возвращающий карту из колоды, меняет lastCardIndex
	  return AllCards[0]; // FIXME
	}
};

