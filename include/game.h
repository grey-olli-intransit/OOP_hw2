#pragma once
#include "deckofcards.h"
#include "player.h"
#include "dealer.h"

class Game {
  DeckOfCards deck;
  Dealer dealer;
  Player player;
  public:
      void firstStep() {
	  deck.shuffle();
          dealer.getDealerCardsFromDeck(deck);
	  dealer.showFirstCardOpen();
	  player.getPlayerCardsFromDeck(deck);
          player.showAllCardsOpen();
      }
      Game() {
	  firstStep();
      }
      void step() {
          if (dealer.cardSumm()<17 && deck.lastCardIndex > 0)
	      dealer.getDealerCardsFromDeck(deck);
	  dealer.showAllCardsOpen();
	  if (player.cardSumm()<21 && deck.lastCardIndex > 0)
	      player.getPlayerCardsFromDeck(deck);
          player.showAllCardsOpen();
      }

      bool win() {
	  // При игре двух человек 21 или более наберётся всегда раньше чем закончится колода,
	  // так что этот if можно опустить - закоментирован.
          //if(deck.lastCardIndex == 0) {
	  //   printf("Колода закончилась.");
	     // если дилер набрал 17 или более оценивается у кого больше и возвращается true.
	     // 0) у всех карт у игрока и дилера устанавливает поле distributed в DECK ("в колоде")
	     // 1) обнуляет массивы карт игрока и дилера
	     // 2) вызывает shuffle() у колоды
	  //   deck.shuffle()
	     // 3) вызывает firstStep()
	  //   firstStep();
	     // 4) возвращает false, если никто не набрал 21, а дилер не набрал 17.
	     //    
	  //   return false;
	  //}

      // метод возвращает true если:
      // 1) игрок набрал 21 или более
      // 2) дилер набрал 17 или более
      // 3) когда больше двух игроков, если колода кончилась до набора хотя бы одним игроком 21 (не мой вариант - всего 2 игрока) 
       if(player.cardSumm()>=21) {
         // тут написать кто выиграл
	 return true;
       }
       if (dealer.cardSumm()>=17) {
         // тут написать кто выиграл
	 return true;
       }
       return false;
      }
};


