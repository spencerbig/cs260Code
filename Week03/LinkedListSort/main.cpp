#include <iostream>
#include <cstdlib>
#include <ctime>

#include "LinkedList.h"

using namespace std;

int main()
{
    {
        cout << "Testing slice on even sized list:" << endl;

        LinkedList<int> myList;
        myList.insertStart(4);
        myList.insertStart(2);
        myList.insertStart(6);
        myList.insertStart(5);


        cout << "Original: ";
        cout << myList;

        LinkedList<int> secondHalf = myList.sliceInHalf();

        cout << "1st Half: ";
        cout << myList;
        cout << "2nd Half: ";
        cout << secondHalf << endl;
    }

    {
        cout << "Testing slice on odd sized list:" << endl;

        LinkedList<int> myList;
        myList.insertStart(4);
        myList.insertStart(2);
        myList.insertStart(6);

        cout << "Original: ";
        cout << myList;

        LinkedList<int> secondHalf = myList.sliceInHalf();

        cout << "1st Half: ";
        cout << myList;
        cout << "2nd Half: ";
        cout << secondHalf << endl;
    }


    ////---------------------Merge-----------------------

//    cout << endl << "Making two sorted lists:" << endl;
//    LinkedList<int> myList2a;
//    for(int i = 18; i > 0; i -=3 )
//        myList2a.insertStart(i);

//    LinkedList<int> myList2b;
//    for(int i = 10; i > 0; i -= 2 )
//        myList2b.insertStart(i);

//    cout << "First: ";
//    cout << myList2a;
//    cout << "2nd : ";
//    cout << myList2b;

//    cout << endl << "Merging 2nd into first..." << endl;
//    myList2a.mergeIn(myList2b);
//    cout << "First: ";
//    cout << myList2a;
//    cout << "2nd: ";
//    cout << myList2b << endl;


    ////-------------MergeSort-----------------

//    cout << endl << "Making a list with random junk and sorting:" << endl;
//    LinkedList<int> myList3;
//    srand(time(nullptr));
//    for(int i = 0; i < 15; i++) {
//        myList3.insertStart(rand()%100);
//    }
//    myList3.mergeSort();
//    cout << myList3;


    return 0;
}
