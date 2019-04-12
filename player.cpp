//
// Created by shish on 4/9/2019.
//

#include "player.h"
#include <string.h>

#include<cstdlib>
#include<ctime>
#include "stdlib.h"

using namespace std;

Player::Player(){
    myName=" ";
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){

    for(vector<Card>::iterator it = myHand.begin(); it<myHand.end(); it++){
        if(*it==c1){
            myBook.push_back(*it);
            it = myHand.erase(it);
            break;
        }
        else if(*it == c2){
            myBook.push_back(*it);
            it = myHand.erase(it);
            break;
        }

    }
    for(vector<Card>::iterator it = myHand.begin(); it<myHand.end(); it++){
        if(*it==c1){
            myBook.push_back(*it);
            it = myHand.erase(it);
            break;
        }
        else if(*it == c2){
            myBook.push_back(*it);
            it = myHand.erase(it);
            break;
        }

    }
}



//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    for(vector<Card>::iterator i = myHand.begin(); i<(myHand.end()-1); i++){
        for(vector<Card>::iterator j = i+1; j<myHand.end(); j++) {
            if(i->getRank()==j->getRank()){
                c1=*i;
                c2=*j;
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{

    for( vector<Card>::const_iterator it = myHand.begin() ; it<myHand.end(); it++){
        if(it->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {
    if(myHand.size()==0){
        Card temp = Card(20, Card::spades);
    }
    if(myHand.size()<2){
        return myHand[0];
    }
    int index= (rand() % myHand.size());
    return myHand[index];

}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {
    for (vector<Card>::const_iterator it = myHand.begin(); it < myHand.end(); it++) {
        if(*it == c){
            return true;
        }
    }
    return false;
}

////Remove the card c from the hand and return it to the caller
//Card Player::removeCardFromHand(Card c){
//    for( vector<Card>::const_iterator it = myHand.begin() ; it<myHand.end(); it++) {
//        if(*it == c){
//            Card temp= *it;
//            it = myHand.erase(it);
//            return temp;
//        }
//    }
//}

string Player:: showHand() const{
    string hands;
    for( vector<Card>::const_iterator it = myHand.begin() ; it<myHand.end(); it++){
        hands += it->toString();
        hands+= " ";
    }
    return hands;
}

string Player::showBooks() const{
    string books;
    if(myBook.size()<1){
        return this->getName() + " book is empty";
    }
    for( vector<Card>::const_iterator it = myBook.begin() ; it<myBook.end()-1; it+=2){
        books +="( ";
        books += it->toString();
        books += (it+1)->toString();
        books += " ) ";
    }
    return books;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player:: getBookSize() const{
    return myBook.size();
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

//}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool sameRankInHand(Card c){
//
//}

//removes the card a certain from the players hand and returns it so that the other player can then grab it.
Card Player::getCardOfRank(int rank){
    for( vector<Card>::iterator it = myHand.begin() ; it<myHand.end(); it++) {
        if(it->getRank()==rank){
            Card temp = *it;
            it = myHand.erase(it);
            return temp;
        }
    }
    Card temp;
    return temp;
}
