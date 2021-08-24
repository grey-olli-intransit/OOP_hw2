#pragma once
#include "enum.h"
// карта
class Card {
   int cardValue;
   std::string cardName;
   int indexInDeck; // номер под которым карта лежит в колоде
   Distributed distributed; // флаг "карта роздана" дилеру или игроку или лежит в колоде
   Suit suit;
};


