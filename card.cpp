//
// Created by shish on 4/9/2019.
//

#include "card.h"

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank)+ suitString(mySuit);

}

bool Card::sameSuitAs(const Card &c) const {
    if (mySuit == c.mySuit)
        return true;
    else
        return false;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    switch(s){
        case spades:
            return "s";
        case clubs:
            return "c";
        case diamonds:
            return "d";
        case hearts:
            return "h";
        default:
            return NULL;
    }
}

string Card::rankString(int r) const {
    switch(r){
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return NULL;
    }
}

bool Card::operator ==(const Card &rhs) const {
    if ( (myRank == rhs.myRank) && (mySuit == rhs.mySuit))
        return true;
    else
        return false;
}

bool Card::operator!=(const Card &rhs) const {
    if (myRank != rhs.getRank())
        return true;
    else if (mySuit != rhs.mySuit)
        return true;
    else
        return false;
}
