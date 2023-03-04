#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <algorithm>

#define SMALL 100
#define LARGE 100000

using namespace std;
using namespace std::chrono;

void systemSort(int theArray[], int n)
{
    //get starting point
    auto start = high_resolution_clock::now();
    //sort array
    sort (theArray,theArray + n);//(theArray.begin(), theArray.end());
    //get end point
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);

    cout << "\t Elapsed time in nanoseconds for " << n <<" elements: "
         << duration.count() << " ns" << endl;

}

void insertionSort(int theArray[], int n)
{
    int i, key, j;


    //get starting point
    auto start = high_resolution_clock::now();

    //sort array
    for (i = 1; i < n; i++)
    {
        key = theArray[i];
        j = i - 1;

        //move elements of array that
        //are greater than the key, to
        //one position ahead of
        //their current

        while ((j >= 0)&&(theArray[j] > key))
        {
            theArray[j + 1] = theArray[j];
            j = j - 1;
        }

        theArray[j + 1] = key;
    }

    //get end point
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);

    cout << "\t Elapsed time in nanoseconds for " << n <<" elements: "
         << duration.count() << " ns" << endl;
}

void heapify(int theArray[], int n, int root)
{
    int largest = root;  // root is the largest value
    int l = 2*root+1;    // left = root*2+1
    int r = 2*root+2;    // right = root*2+1

    // if left child is larger than root
    if ((l < n) && (theArray[l] > theArray[largest]))
        largest = l;

    // if right child is larger that largest so far
    if ((r < n) && (theArray[r] > theArray[largest]))
        largest = r;

    // if largest is not the root
    if (largest != root) {
        swap (theArray[root], theArray[largest]);  // swamp root and largest
        heapify(theArray, n, largest);
    }
}

void heapSort(int theArray[], int n)
{

    //get starting point
    auto start = high_resolution_clock::now();

    // build heap
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(theArray, n, i);
    }

    // extract elements for the heap one by one
    for (int i = n-1; i >= 0; i--)
    {
        // move the current root to the end
        swap(theArray[0], theArray[i]);

        // again call heapify on the reduced array
        heapify(theArray, i, 0);
    }

    //get end point
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);

    cout << "\t Elapsed time in nanoseconds for " << n <<" elements: "
         << duration.count() << " ns" << endl;
}


int main()
{
    //create array
    int theArray[SMALL];
    int theLargeArray[LARGE];


/*
    //randomize small values
    for (int i = 0; i < SMALL; i++)
        theArray[i] = rand() % SMALL;

    //randomize large values
    for (int i = 0; i < LARGE; i++)
        theLargeArray[i] = rand() % LARGE;
*/


    //print unsorted array
    cout << endl << "Unsorted Small Data: ";
    for (int i = 0; i < SMALL; i++)
    {
        cout << theArray[i] << " ";
    }

    //print unsorted array
    cout << endl << "Unsorted Large Data: ";
    for (int i = 0; i < LARGE; i++)
    {
        cout << theLargeArray[i] << " ";
    }




    cout << "\n Using system sort: " << endl;
    systemSort(theArray, SMALL);
    systemSort(theLargeArray, LARGE);

    cout << endl;

    cout << "\n Using insertion sort: " << endl;
    insertionSort(theArray, SMALL);
    insertionSort(theLargeArray, LARGE);

    cout << endl;

    cout << "\n Using heap sort: " << endl;
    heapSort(theArray, SMALL);
    heapSort(theLargeArray, LARGE);


    return 0;
}
