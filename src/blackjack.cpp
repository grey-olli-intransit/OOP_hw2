#include <iostream>
#include <string>
#include "card.h"
#include "deckofcards.h"
#include "player.h"
#include "dealer.h"
#include "game.h"

// Правила Black Jack: https://add-hobby.ru/blackjack.html
// Уточнения под которые сделан код:
// игра одной колодой,
// ставок нет - только статус выигрыша,
// нет даблов и триплов,
// игра дилера с одним игроком, т.е. не более 2х человек.
// За дилера будет играть компьютер.


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
