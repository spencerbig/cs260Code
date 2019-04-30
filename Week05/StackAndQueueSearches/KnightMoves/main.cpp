#include <iostream>

#include "Queue.h"
#include "Location.h"
using namespace std;

int main()
{
    Location loc1(6, 7);     //starting location
    Location goalLocation(8, 8);   //goal location

    //Initialize search storage
    Queue<Location> storage;
    storage.enqueue(loc1);


    while( !storage.empty() ) {
        cout << "\n----------------------------------------" << endl;
        cout << "States to process:" << endl;
        cout << storage << endl;

        ///Get the next state to explore from the queue
        Location curLocation = storage.dequeue();

        if(curLocation == goalLocation) {
            cout << "Found the path to: " << curLocation << endl;
            break;
        } else {
            cout << "Making moves from: " << curLocation << " --> ";
        }

        ///Ugly for loops generate each possible move for a knight
        //Can move up to 2 rows either direction
        for(int rowMod = -2; rowMod <= 2; rowMod++) {
            if(rowMod == 0)
                continue;  //can't move 0 rows
            //Assume we move only 1 column. If we are moving just 1 row, move 2 cols
            int colsToMove = 1;
            if( rowMod == 1 || rowMod == -1 ) colsToMove = 2;
            for(int colMod = -colsToMove; colMod <= colsToMove; colMod+= 2*colsToMove) {

                ///Make a new possible move
                Location newLocation = curLocation;
                newLocation.row += rowMod;
                newLocation.col += colMod;

                //Only keep moves that are on the board
                if( newLocation.row >= 1 && newLocation.row <= 8 &&
                    newLocation.col >= 1 && newLocation.col <= 8)
                {
                    ///Add the new location to the queue of things to try
                    cout << newLocation << " ";
                    storage.enqueue(newLocation);
                }

            }
        }
    }

}
