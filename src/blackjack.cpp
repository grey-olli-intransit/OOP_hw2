#include <iostream>
#include <string>

// Правила Black Jack: https://add-hobby.ru/blackjack.html
// Уточнения под которые сделан код:
// игра одной колодой,
// ставок нет - только статус выигрыша,
// нет даблов и триплов,
// игра дилера с одним игроком, т.е. не более 2х человек.
// За дилера будет играть компьютер.

enum Suit {HEARTS, SPADES, CROSS, DIAMONDS}; // Черви, Пики, Крести, Буби (в этой игре не нужно)
enum Distributed {DEALER, PLAYER, DECK};

// карта
class Card {
   int cardValue;
   std::string cardName;
   int indexInDeck; // номер под которым карта лежит в колоде
   Distributed distributed; // флаг "карта роздана" дилеру или игроку или лежит в колоде
   Suit suit;
};

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

class Player {
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


class Dealer:public Player {
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


int main(int argc, char ** argv) {
    Game g;
repeat:
    while(!g.win()) {
       g.step();
    }
    // тут спросить хочет ли продолжать игру,
    // если да:
    // g.
    // goto repeat;
    return 0;

}
