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
struct Card {
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
	  // двойки
	  Card dvaPik;
	  dvaPik.cardValue=2;
	  dvaPik.cardName="2 пик";
	  dvaPik.indexInDeck=0;
	  dvaPik.distributed=DECK;
	  dvaPik.suit=SPADES;
          AllCards[0]=dvaPik;
	  Card dvaCherv;
	  dvaCherv.cardValue=2;
	  dvaCherv.cardName="2 червей";
	  dvaCherv.indexInDeck=1;
	  dvaCherv.distributed=DECK;
	  dvaCherv.suit=HEARTS;
          AllCards[1]=dvaCherv;
	  Card dvaTref;
	  dvaTref.cardValue=2;
	  dvaTref.cardName="2 треф";
	  dvaTref.indexInDeck=2;
	  dvaTref.distributed=DECK;
	  dvaTref.suit=CROSS;
          AllCards[2]=dvaTref;
	  Card dvaBubey;
	  dvaBubey.cardValue=2;
	  dvaBubey.cardName="2 бубей";
	  dvaBubey.indexInDeck=3;
	  dvaBubey.distributed=DECK;
	  dvaBubey.suit=DIAMONDS;
          AllCards[3]=dvaBubey;
	  // тройки
	  Card triPik;
	  triPik.cardValue=3;
	  triPik.cardName="3 пик";
	  triPik.indexInDeck=4;
	  triPik.distributed=DECK;
	  triPik.suit=SPADES;
          AllCards[4]=triPik;
	  Card triCherv;
	  triCherv.cardValue=3;
	  triCherv.cardName="3 червей";
	  triCherv.indexInDeck=5;
	  triCherv.distributed=DECK;
	  triCherv.suit=HEARTS;
          AllCards[5]=triCherv;
	  Card triTref;
	  triTref.cardValue=3;
	  triTref.cardName="3 треф";
	  triTref.indexInDeck=6;
	  triTref.distributed=DECK;
	  triTref.suit=CROSS;
          AllCards[6]=triTref;
	  Card triBubey;
	  triBubey.cardValue=3;
	  triBubey.cardName="3 бубей";
	  triBubey.indexInDeck=7;
	  triBubey.distributed=DECK;
	  triBubey.suit=DIAMONDS;
          AllCards[7]=triBubey;
	  // четверки
	  Card chetirePik;
	  chetirePik.cardValue=4;
	  chetirePik.cardName="4 пик";
	  chetirePik.indexInDeck=8;
	  chetirePik.distributed=DECK;
	  chetirePik.suit=SPADES;
          AllCards[8]=chetirePik;
	  Card chetireCherv;
	  chetireCherv.cardValue=4;
	  chetireCherv.cardName="4 червей";
	  chetireCherv.indexInDeck=9;
	  chetireCherv.distributed=DECK;
	  chetireCherv.suit=HEARTS;
          AllCards[9]=chetireCherv;
	  Card chetireTref;
	  chetireTref.cardValue=4;
	  chetireTref.cardName="4 треф";
	  chetireTref.indexInDeck=10;
	  chetireTref.distributed=DECK;
	  chetireTref.suit=CROSS;
          AllCards[10]=chetireTref;
	  Card chetireBubey;
	  chetireBubey.cardValue=4;
	  chetireBubey.cardName="4 бубей";
	  chetireBubey.indexInDeck=11;
	  chetireBubey.distributed=DECK;
	  chetireBubey.suit=DIAMONDS;
          AllCards[11]=chetireBubey;
	  // пятерки
	  Card piatPik;
	  piatPik.cardValue=5;
	  piatPik.cardName="5 пик";
	  piatPik.indexInDeck=12;
	  piatPik.distributed=DECK;
	  piatPik.suit=SPADES;
          AllCards[12]=piatPik;
	  Card piatCherv;
	  piatCherv.cardValue=5;
	  piatCherv.cardName="5 червей";
	  piatCherv.indexInDeck=13;
	  piatCherv.distributed=DECK;
	  piatCherv.suit=HEARTS;
          AllCards[13]=piatCherv;
	  Card piatTref;
	  piatTref.cardValue=5;
	  piatTref.cardName="5 треф";
	  piatTref.indexInDeck=14;
	  piatTref.distributed=DECK;
	  piatTref.suit=CROSS;
          AllCards[14]=piatTref;
	  Card piatBubey;
	  piatBubey.cardValue=5;
	  piatBubey.cardName="5 бубей";
	  piatBubey.indexInDeck=15;
	  piatBubey.distributed=DECK;
	  piatBubey.suit=DIAMONDS;
          AllCards[15]=piatBubey;
	  // шестерки
	  Card shestPik;
	  shestPik.cardValue=6;
	  shestPik.cardName="6 пик";
	  shestPik.indexInDeck=16;
	  shestPik.distributed=DECK;
	  shestPik.suit=SPADES;
          AllCards[16]=shestPik;
	  Card shestCherv;
	  shestCherv.cardValue=6;
	  shestCherv.cardName="6 червей";
	  shestCherv.indexInDeck=17;
	  shestCherv.distributed=DECK;
	  shestCherv.suit=HEARTS;
          AllCards[17]=shestCherv;
	  Card shestTref;
	  shestTref.cardValue=6;
	  shestTref.cardName="6 треф";
	  shestTref.indexInDeck=18;
	  shestTref.distributed=DECK;
	  shestTref.suit=CROSS;
          AllCards[18]=shestTref;
	  Card shestBubey;
	  shestBubey.cardValue=6;
	  shestBubey.cardName="6 бубей";
	  shestBubey.indexInDeck=19;
	  shestBubey.distributed=DECK;
	  shestBubey.suit=DIAMONDS;
          AllCards[19]=shestBubey;
	  // семерки
	  Card semPik;
	  semPik.cardValue=7;
	  semPik.cardName="7 пик";
	  semPik.indexInDeck=0;
	  semPik.distributed=DECK;
	  semPik.suit=SPADES;
          AllCards[0]=semPik;
	  Card semCherv;
	  semCherv.cardValue=7;
	  semCherv.cardName="7 червей";
	  semCherv.indexInDeck=1;
	  semCherv.distributed=DECK;
	  semCherv.suit=HEARTS;
          AllCards[1]=semCherv;
	  Card semTref;
	  semTref.cardValue=7;
	  semTref.cardName="7 треф";
	  semTref.indexInDeck=2;
	  semTref.distributed=DECK;
	  semTref.suit=CROSS;
          AllCards[2]=semTref;
	  Card semBubey;
	  semBubey.cardValue=7;
	  semBubey.cardName="7 бубей";
	  semBubey.indexInDeck=3;
	  semBubey.distributed=DECK;
	  semBubey.suit=DIAMONDS;
          AllCards[3]=semBubey;
	  // восьмерки
	  // девятки
	  // десятки
	  // валеты
	  // дамы
	  // короли
	  // тузы
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

       // метод считает очки на картах из AllCards, завершён.
       int cardSumm() {
	 int summ=0;
	 int variableCardValue1=0;
	 int variableCardValue2=0;
	 int variableCardValue3=0;
	 int variableCardValue4=0;
	 for(Card i:{AllCards[0],AllCards[1],AllCards[2],AllCards[3],AllCards[4],AllCards[5],AllCards[6],AllCards[7],AllCards[8]}){
           // туз имеет значение 11 или 1 - как выгоднее держателю карт,ставим 11, после цикла можем сменить на 1 - тут не суммируем.
           if(i.cardName=="туз пик")
              variableCardValue1=11;
	   else if (i.cardName=="туз червей")
              variableCardValue2=11;
	   else if (i.cardName=="туз треф")
              variableCardValue2=11;
	   else if (i.cardName=="туз бубей")
              variableCardValue2=11;
	   else 
	      summ+=i.cardValue;
	 }
         if(variableCardValue1){
	   if(summ+variableCardValue1 > 21)
             summ+=1;
	   else
	     summ+=11
	 }
         if(variableCardValue2){
	   if(summ+variableCardValue2 > 21)
             summ+=1;
	   else
	     summ+=11
	 }
         if(variableCardValue3){
	   if(summ+variableCardValue3 > 21)
             summ+=1;
	   else
	     summ+=11
	 }
         if(variableCardValue4){
	   if(summ+variableCardValue4 > 21)
             summ+=1;
	   else
	     summ+=11
	 }
	 return summ;
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
      // 1) игрок набрал 21 или менее, но больше чем дилер, который уже набрал 17 или более: игрок выиграл
      // 2) дилер набрал 17 или более и больше чем игрок, но менее или равно 21: дилер выиграл
      // 3) игрок набрал больше 21, а дилер 21 или менее: дилер выиграл
      // 4) дилер набрал больше 21, а игрок 21 и менее: игрок выиграл
      // 5) дилер набрал ровно 21, а игрок другую сумму: дилер выиграл
      // 6) когда больше двух игроков, если колода кончилась до набора хотя бы одним игроком 21 (не мой вариант - всего 2 игрока) 
       int playerCardSumm = player.cardSumm();
       int dealerCardSumm = dealer.cardSumm();
       if(playerCardSumm==21) {
	 if (dealerCardSumm == 21)
             printf("Никто не выиграл. И у Вас и у дилера по 21 очку.\n");
	 else
             printf("Вы выиграли!\n"); 
	 return true;
       }
       if (dealerCardSumm >= 17 && dealerCardSumm <= 21 && (playerCardSumm < dealerCardSumm || playerCardSumm > 21)) {
         printf("Дилер выиграл. Вы проиграли.\n");
	 return true;
       }
       if (dealerCardSumm >=17 && playerCardSumm > dealerCardSumm && playerCardSumm <= 21) {
         printf("Дилер проиграл. Вы выиграли.\n");
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
