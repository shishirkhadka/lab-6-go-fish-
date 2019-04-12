
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include <fstream>
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void checkHandForBook(Card &c1, Card &c2);
void bookEveryPair(Player &p,ofstream &myfile);
Card chooseCardFromHand();
void gameEngine(ofstream &myfile);


int main( ){
    ofstream myfile ("gofish_results.txt");
    if(myfile.is_open()){
        myfile << "this is printed."<<endl;
    }
    gameEngine(myfile);
    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{    //d.shuffle();
    for (int i=0; (i < numCards) && (d.size()>0); i++)
        p.addCard(d.dealCard());
}

void bookEveryPair(Player &p, ofstream &myfile){
    Card card1;
    Card card2;
    bool isBookFlag = p.checkHandForBook(card1, card2);
    while(isBookFlag){
        p.bookCards( card1, card2);
        myfile<< p.getName()<<" booked card ";
        myfile<<p.showBooks()<<endl;
        isBookFlag=p.checkHandForBook(card1, card2);
    }
}

void gameEngine(ofstream &myfile){
    int numCards = 7;
    Player p1("Joe");
    Player p2("Jane");
    Card c1,c2;
    Deck d;  //create a deck of cards
    d.shuffle();
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    myfile << p1.getName() <<" has : " << p1.showHand() << endl;
    myfile << p2.getName() <<" has : " << p2.showHand() << endl;


    bool game= true;
    bool player1=true;
    bool player2=false; //remember to set to false
    while(game){
        if(player1 &&game ){
            while(player1 && game){
                myfile<<endl<<endl;
                if(d.size()>0) {
                    if (p1.getHandSize() == 0) {
                        dealHand(d, p1, numCards);
                    }
                    if (p2.getHandSize() == 0) {
                        dealHand(d, p2, numCards);
                    }
                }

                bookEveryPair(p1, myfile); // make books
                bookEveryPair(p2, myfile);
                if(d.size()>0) {
                    if (p1.getHandSize() == 0) {
                        dealHand(d, p1, numCards);
                    }
                    if (p2.getHandSize() == 0) {
                        dealHand(d, p2, numCards);
                    }
                }
                myfile << p1.getName() <<" has : " << p1.showHand() << endl;
                myfile << p1.getName() <<" has : " << p1.showBooks() << endl;
                myfile << p2.getName() <<" has : " << p2.showHand() << endl;
                myfile << p2.getName() <<" has : " << p2.showBooks() << endl<<endl<<endl;

                if((d.size()==0 && p1.getHandSize()==0)) {
                    if (p1.getBookSize()>p2.getBookSize()){
                        myfile<<p1.getName()<< " won the game!!"<<endl;
                    }
                    else if (p2.getBookSize()>p1.getBookSize()){
                        myfile<<p2.getName()<< " won the game!!"<<endl;
                    }
                    else {
                        myfile << "its a draw" << endl;
                    }
                    game = false;
                }
                else{
                    c1 = p1.chooseCardFromHand();
                    myfile << p1.getName() << " asks- Do you have " << c1.rankString(c1.getRank()) << endl; //ask
                    if (!p2.rankInHand(c1)) {
                        player1 = false; //really false
                        player2 = true;
                        myfile << p2.getName() << " - Go Fish" << endl;
                        if (d.size() > 0) {
                            Card temp = d.dealCard();
                            myfile << p1.getName() << " draws a " << temp.toString() << endl;
                            p1.addCard(temp);
                            bookEveryPair(p1,myfile);
                        }
                    } else {
                        myfile << p2.getName() << " - Yes. I have " << c1.rankString(c1.getRank()) << endl;
                        p1.addCard(p2.getCardOfRank(c1.getRank()));
                        p1.checkHandForBook(c1, c2);
                        p1.bookCards(c1, c2);
                        myfile << p1.getName() << " has : " << p1.showHand() << endl;
                    }
                }
            }
        }

        if(player2){
            while(player2 && game){
                if(d.size()>0) {
                    if (p1.getHandSize() == 0) {
                        dealHand(d, p1, numCards);
                    }
                    if (p2.getHandSize() == 0) {
                        dealHand(d, p2, numCards);
                    }
                }
                myfile<<endl<<endl;
                bookEveryPair(p1, myfile); // make books
                bookEveryPair(p2, myfile);

                if(d.size()>0) {
                    if (p1.getHandSize() == 0) {
                        dealHand(d, p1, numCards);
                    }
                    if (p2.getHandSize() == 0) {
                        dealHand(d, p2, numCards);
                    }
                }

                myfile << p1.getName() <<" has : " << p1.showHand() << endl;
                myfile << p1.getName() <<" books : " << p1.showBooks() << endl;
                myfile << p2.getName() <<" has : " << p2.showHand() << endl;
                myfile << p2.getName() <<" books : " << p2.showBooks() << endl<<endl<<endl;

                if((d.size()==0 && p2.getHandSize()==0)) {
                    if (p1.getBookSize()>p2.getBookSize()){
                        myfile<<p1.getName()<< " won the game!!"<<endl;
                    }
                    else if (p2.getBookSize()>p1.getBookSize()){
                        myfile<<p2.getName()<< " won the game!!"<<endl;
                    }
                    else {
                        myfile<<"its a draw"<<endl;
                    }
                    game = false;
                }
                else{
                    c2 = p2.chooseCardFromHand();
                    myfile << p2.getName() << " asks- Do you have " << c2.rankString(c2.getRank()) << endl; //ask
                    if (!p1.rankInHand(c2)) {
                        player2 = false; //really false
                        player1 = true;
                        myfile << p1.getName() << " - Go Fish" << endl;
                        if (d.size() > 0) {
                            Card deal = d.dealCard();
                            myfile << p2.getName() << " draws a " << deal.toString() << endl;
                            p2.addCard(deal);
                        }
                    }
                    else {
                        myfile << p1.getName() << " - Yes. I have " << c2.rankString(c2.getRank()) << endl;
                        p2.addCard(p1.getCardOfRank(c2.getRank()));
                        p2.checkHandForBook(c1, c2);
                        p2.bookCards(c1, c2);
                        myfile << p2.getName() << " has : " << p2.showHand() << endl;
                    }
                }
            }
        }
    }
}


