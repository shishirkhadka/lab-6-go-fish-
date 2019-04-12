//
// Created by shish on 4/9/2019.
//

#include "deck.h"
#include "card.h"
#include <iostream>
#include <cstdlib>

#include "stdlib.h"
#include <ctime>

using namespace std;

Deck:: Deck(){
    int myIndex = 0;
    for(int suit = Card::spades; suit <= Card::clubs; suit++ ){
        for( int i = 1; i <= 13; i++){
            myCards[myIndex]= Card(i, Card::Suit(suit));
            myIndex++;
        }
    }
    srand(time(0));
    myIndex=0;
}



void Deck::shuffle() {
    myIndex = 0;
    for(int i=0;i<3400; i++) {
        int rand1 = rand() % SIZE;
        int rand2 = rand() % SIZE;
        swap(myCards[rand1], myCards[rand2]);
    }
}

Card Deck::dealCard() {
    if(size()== 0) {
        cout << "no cards to deal";
    }
    else {
        Card temp = myCards[myIndex];
        myIndex++;
        return temp;
    }
    Card temp;
    return temp;
}

int Deck::size() const {
    return (SIZE-myIndex);
}

