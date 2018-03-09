// Use this as the base for your program 4
//==================================================================
// File: Prog4Main.cpp
// Base file provided by Dr. Coleman for programming assignment 4.
// Look for places where you see TODO: which requires you to insert
//    code.
// 
// Student Name: Quang Tran
// 
// This program is entirely my own work.
//==================================================================
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "MicroSecondTimer.h"

using namespace std;

#define DATAFILE	"SortData.txt"
#define NUMRECS		10000
#define MAXKEY		99999.0
#define RADIX		10.0

struct SortData
{
    int     key;
    char    strData[5];
    double  numData;
};

bool ReadData(SortData DA[], int count);
bool getNextLine(ifstream *inF, char *line, int lineLen);
bool CheckData(SortData DataArray[], int count);

// Sorting Algorithm Prototypes
//---------------------------------------------------------
// TODO: Prototype the 5 sort functions you will be testing here
//---------------------------------------------------------
void BubbleSort(SortData DataArray[], int count);

void InsertSort(SortData DataArray[], int count);

void ShellSort(SortData DataArray[], int count);
void DeltaInsertionSort(SortData DataArray[], int I, int Delta, int count);

void MergeSort(SortData strData[], int startIdx, int endIdx);
void Merge(SortData Array1[], int start1, int end1, int start2, int end2);

void ProxmapSort(SortData DataArray[], SortData DataArray2[], int count);
int  Hash(int key, int KeyMax, int KeyMin, int count);
void ProxMapInsertionSort(SortData DataArray[], SortData *theStruct, int startIdx, int listLen);

void RadixSort(SortData DataArray[], SortData DataArray2[], int count);

void SelectSort(SortData DataArray[], int count);
	
int main(int argc, char **argv)
{
	SortData	DataArray[NUMRECS];	// Array into which unsorted data will be read
	SortData	DataArray2[NUMRECS]; // Array to hold sorted data if needed
	MicroSecondTimer *mst = new MicroSecondTimer();
	long		startTime, endTime;
	double		totalTime;
	double		averageTime;
	bool		sortError;

	cout << "============================================================\n";
	cout << " PROGRAMMING ASSIGNMENT 4\n";
	cout << " Name: Quang Tran\n";
	cout << "============================================================\n";
	cout << "Starting application\n\n";
	cout.flush();

	// For each of your 5 sort algorithms do the following
	//---------------------- Begin Sort Algorithm -----------------------

		totalTime = 0.0; // Initialize the time variable
		sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		ProxmapSort(DataArray,  DataArray2, NUMRECS);
		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray2, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---ProxmapSort---\n\n";
	else
		cout << "---ProxmapSort--- took " << averageTime << " seconds to complete\n\n";
		


		

//*******************************************************************************************************
//*******************************************************************************************************
	
		totalTime = 0.0; // Initialize the time variable
		sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		ShellSort(DataArray, NUMRECS);

		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---ShellShort---\n\n";
	else
		cout << "---ShellShort--- took " << averageTime << " seconds to complete\n\n";

//*******************************************************************************************************
//*******************************************************************************************************
	

	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		RadixSort( DataArray,  DataArray2,  NUMRECS);

		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray2, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---RadixSort---\n\n";
	else
		cout << "---RadixSort--- took " << averageTime << " seconds to complete\n\n";

//*******************************************************************************************************
//*******************************************************************************************************
		totalTime = 0.0; // Initialize the time variable
		sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		InsertSort(DataArray, NUMRECS);

		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---InsertSort---\n\n";
	else
		cout << "---InsertSort--- took " << averageTime << " seconds to complete\n\n";

//*******************************************************************************************************
//*******************************************************************************************************
		
	totalTime = 0.0; // Initialize the time variable
		sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		
		MergeSort(DataArray, 0, NUMRECS-1);
			
		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---MergeSort---\n\n";
	else
		cout << "---MergeSort--- took " << averageTime << " seconds to complete\n\n";

//*******************************************************************************************************
//*******************************************************************************************************
	//*******************************************************************************************************
//*******************************************************************************************************

		totalTime = 0.0; // Initialize the time variable
		sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		SelectSort (DataArray,  NUMRECS);
		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---SelectSort---\n\n";
	else
		cout << "---SelectSort--- took " << averageTime << " seconds to complete\n\n";
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		BubbleSort(DataArray, NUMRECS);

		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---BubbleSort---\n\n";
	else
		cout << "---BubbleSort--- took " << averageTime << " seconds to complete\n\n";

	



	//------------------------ End Sort Algorithm -----------------------------

	cout << "Finished testing all sorting algorithms.\n";
	cout.flush();
	return 0;
	
}

//----------------------------------------------------
// ReadData()
// Reads all data from data file into the data array
//----------------------------------------------------
bool ReadData(SortData DA[], int count)
{
	ifstream	inF;		// Input file stream
	char	line[64];	// Line read from file

	inF.open(DATAFILE, ifstream::in);
    if(!inF.is_open())
    {
		cout << "infile failed" << endl;
        return false;
    }

	for(int i=0; i<count; i++)
	{
		getNextLine(&inF, line, 64);
		DA[i].key = atoi(strtok(line, " "));
		strcpy(DA[i].strData, strtok(NULL, " "));
		DA[i].numData = atof(strtok(line, " "));
		
	}//cout << "infile success"<< endl;

	inF.close();
	return true;
}

//-------------------------------------------
// GetNextLine()
// Read the next line from the file.
//-------------------------------------------
bool getNextLine(ifstream *inF, char *line, int lineLen)
{
    bool    done = false;

    while(!done)
    {
        inF->getline(line, lineLen);
        
        if(inF->good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;  // Got a valid data line so return it
        }
        else
        {
            strcpy(line, "");
            return false;  // Flag end of file
        }
    } // end while
	return true;
}

//------------------------------------------------
// Checkdata()
// Check to make sure the data is in sorted order
//------------------------------------------------
bool CheckData(SortData DataArray[], int count)
{
	int i;
	for(i=0; i<(count-1); i++)
	{
		if(DataArray[i].key > DataArray[i+1].key)
		{
			return false;
		}
	}
	//cout << DataArray << endl;
	return true;
}

//=======================================================================
//         TODO: PUT YOUR SORTING ALGORITHM IMPLEMENTATIONS HERE
//=======================================================================



void BubbleSort(SortData DataArray[], int count){
	int i , j;
	SortData temp;

	for (i=0; i < count ; i++){
		for(j=0; j<(count-i - 1); j++)
			if(DataArray[j].key > DataArray[j+1].key){
				temp = DataArray[j];
				DataArray[j] = DataArray[j+1];
				DataArray[j+1] = temp;
				
			}
		}	
}

 /***************************************/
/* InsertSort()                        */
/*                                     */
/* Sort records on integer key using   */
/*  an insertion sort.                 */
/***************************************/
void InsertSort(SortData DataArray[], int count)
{
    int            i, j;
    SortData     temp;
    int            NotDone;
    int            Key;

    for(i=1; i<count; i++)
    {
        Key = DataArray[i].key;
        j = i;
        NotDone = (DataArray[j-1].key > Key);

        temp = DataArray[j]; /* Remove and hold the one to be moved */

        while(NotDone)
        {
            /* Slide all others to the right */
            DataArray[j] = DataArray[j-1];
            j--;
            if(j > 0)
                NotDone = (DataArray[j - 1].key > Key);
            else
                NotDone = FALSE;
        }

        /* Put the removed record into it's correct slot */
        DataArray[j] = temp;
    }
}

/***************************************/
/* ShellSort()                         */
/*                                     */
/* Sort records on integer key using   */
/*  a shell sort.                      */
/***************************************/
void ShellSort(SortData DataArray[], int count)
{
    int i, delta;

    delta = count;

    do
    {
        delta = 1 + delta / 3;
        for(i=0; i<delta; i++)
            DeltaInsertionSort(DataArray, i, delta, count);
    }
    while(delta > 1);
}

/***************************************/
/* DeltaInsertionSort()                */
/*                                     */
/* Sort subarrays of records on integer*/
/*   key using selection sort.         */
/***************************************/
void DeltaInsertionSort(SortData DataArray[], int I, int Delta, int count)
{
    int            j, k;
    int            key;
    int            NotDone;
    SortData    temp;

    j = I + Delta;

    while(j < count)
    {
        key = DataArray[j].key;        /* Get next key to sort */
        temp = DataArray[j];    /* Remove and hold */

        /* Do insertion sort on this key in the block of delta records */
        /* Move each struct where DataArray[j].key > key to the right  */
        /*   by delta spaces and insert the key there.                 */
        k = j;
        NotDone = TRUE;

        do
        {
            if(DataArray[k - Delta].key <= key)
                NotDone = FALSE;    /* Terminate the loop */
            else
            {
                DataArray[k] = DataArray[k - Delta];
                k -= Delta;
                if(k==I) NotDone = FALSE;
            }
        }
        while(NotDone);

        /* Insert the moved key */
        DataArray[k] = temp;

        /* Get next key to insert--one full delta increment to the right */
        j += Delta;
    }
}

/***************************************/
/* MergeSort()                         */
/*                                     */
/* Sort records on integer key using   */
/*  a merge sort.                      */
/***************************************/
void MergeSort(SortData DataArray[], int startIdx, int endIdx)
{
    int        start, end;

    if(startIdx < endIdx)    // If there is more than one item to sort 
    {
	
		start = startIdx;
        end = startIdx + ((endIdx - startIdx) / 2);
        MergeSort(DataArray, start, end);
        start = end + 1;
        end = endIdx;
        MergeSort(DataArray, start, end);
        Merge(DataArray, startIdx, start - 1, start, end);
    }
}

/***************************************/
/* Merge()                             */
/* Merge the two sections of the array */
/*  using Insertion Sort treating one  */
/*  section as the sorted section and  */
/*  the other as the unsorted section. */
/***************************************/
void Merge(SortData Array1[], int start1, int end1, int start2, int end2)
{


     int          i, j;
     SortData     temp;
     int          NotDone;
     int          Key;

	 for(i=start2; i<=end2; i++)
     {
          Key = Array1[i].key;
          j = i;
          NotDone = (Array1[j-1].key > Key);
          temp = Array1[j]; 
		  while(NotDone)
          {
               // Slide all others to the right 
               Array1[j] = Array1[j-1];
               j--;
               if(j > 0)
                    NotDone = (Array1[j - 1].key > Key);
               else
                    NotDone = FALSE;
          }
          // Put removed record into correct slot
          Array1[j] = temp;
     }
}

   
/***************************************/
 /* ProxmapSort()                       */
 /*                                     */
 /* Sort records on integer key using   */
 /*  a proxmap sort.                    */
 /***************************************/
 void ProxmapSort(SortData DataArray[], SortData DataArray2[], int count)
 {
     int i;
     int HitList[NUMRECS];
     int Hidx;                  /* Hashed index */
     int ProxMap[NUMRECS];
     int RunningTotal;          /* Number of hits */
     int Location[NUMRECS];
     int KeyMax, KeyMin;        /* Used in Hash() */



     /* Initialize hit list and proxmap */
     for(i=0; i<count; i++)
     {
         HitList[i] = 0;           /* Init to all 0 hits */
		// cout << HitList[i] << endl;
         ProxMap[i] = -1;          /* Init to all unused */
		// cout <<  ProxMap[i] << endl;
         DataArray2[i].key = -1;   /* Init to all empty */
		 //cout <<  DataArray2[i].key << endl;
     }
      /* Find the largest key for use in computing the hash */
     KeyMax = 0;        /* Guaranteed to be less than the smallest key */
     KeyMin = 32767;    /* Guaranteed to be more than the largest key */
     for(i=0; i<count; i++)
     {
         if(DataArray[i].key > KeyMax) KeyMax = DataArray[i].key;
         if(DataArray[i].key < KeyMin) KeyMin = DataArray[i].key;
		 //cout <<  DataArray[i].key << endl;
		 

     } //cout << "largest key: " << KeyMax << " Small Key: " << KeyMin <<endl;
      /* Compute the hit count list (note this is not a collision count, but
         a collision count+1 */
     for(i=0; i<count; i++)
     {
         Hidx = Hash(DataArray[i].key, KeyMax, KeyMin, count); /* Calculate hash index */
         Location[i] = Hidx; /* Save this for later. (Step 1) */
         HitList[Hidx]++;    /* Update the hit count (Step 2) */
     }//cout <<  HitList[Hidx] << endl;
      /* Create the proxmap from the hit list. (Step 3) */
     RunningTotal = 0;        /* Init counter */
     for(i=0; i<count; i++)
     {
         if(HitList[i] > 0)    /* There were hits at this address */
         {
             ProxMap[i] = RunningTotal;    /* Set start index for this set */
             RunningTotal += HitList[i];
         }
     }
     // NOTE: UNCOMMENT THE FOLLOWING SECTION TO SEE WHAT IS IN THE ARRAYS, BUT
     //       COMMENT IT OUT WHEN DOING A TEST RUN AS PRINTING IS VERY SLOW AND
     //       WILL RESULT IN AN INACCURATE TIME FOR PROXMAP SORT.
     // ---------------------------------------------------- 
    // // Print HitList[] to see what it looks like
    // printf("HitList:\n");
    // for(i=0; i<count; i++)
    //     printf("%d ", HitList[i]);
    // printf("\n\n");
    // getch();
    //  // Print ProxMap[] to see what it looks like
    // printf("ProxMap:\n");
    // for(i=0; i<count; i++)
    //     printf("%d ", ProxMap[i]);
    // printf("\n\n");
    //getch();
    //  // Print Location[] to see what it looks like
    // printf("Location:\n");
    // for(i=0; i<count; i++)
    //     printf("%d ", Location[i]);
    // printf("\n\n");
    // getch();
    // ---------------------------------------------  
     /* Move the keys from A1 to A2 */
     /* Assumes A2 has been initialized to all empty slots (key = -1)*/
     for(i=0; i<count; i++)
     {
		 if((DataArray2[ProxMap[Location[i]]].key == -1))  /* If the location in A2 is empty...*/
         {
             /* Move the structure into the sorted array */
             DataArray2[ProxMap[Location[i]]] = DataArray[i]; 
			
         }
         else    /* Insert the structure using an insertion sort */
         {
			 ProxMapInsertionSort(DataArray2, &DataArray[i], ProxMap[Location[i]], HitList[Location[i]]);
         }
     }
  }

 /***************************************/
 /* Hash()                              */
 /*                                     */
 /* Calculate a hash index.             */
 /***************************************/
 int Hash(int key, int KeyMax, int KeyMin, int count)
 {
     float    keyFloat;      /* Map integer key to float in the range 0 <= key < 1 */
     keyFloat = (float)(key - KeyMin) / (float)(1 + KeyMax - KeyMin);
     /* Map float key to indices in range 0 <= index < count */
     return((int)floor(count * keyFloat));
 }

 /***************************************/
 /* ProxMapInsertionSort()              */
 /*                                     */
 /* Use insertion sort to insert a      */
 /*   struct into a subarray.           */
 /***************************************/
 void ProxMapInsertionSort(SortData DataArray[], SortData *theStruct,
                            int startIdx, int listLen)
 {
     /* Args:    DataArray - Partly sorted array
                 *theStruct - Structure to insert
                 startIdx - Index of start of subarray
                 listLen - Number of items in the subarray */
     int i;      /* Find the end of the subarray */
     i = startIdx + listLen - 1;
     while(DataArray[i-1].key == -1) i--;          /* Find the location to insert the key */
	 while((DataArray[i-1].key > theStruct->key) && (i > startIdx))
     {
         DataArray[i] = DataArray[i-1];
         i--;
     }
      /* Insert the key */
      DataArray[i] = *theStruct;
	 
 }
 
 /***************************************/
/* RadixSort()                         */
/*                                     */
/* Sort records on integer key using   */
/*  a radix sort.                      */
/* Note: This sort is made faster by   */
/* using two arrays of pointers to     */
/* structs.  The structures are then   */
/* sorted by moving the pointers       */
/* instead of the structures themselves*/
/* This speeds up the sort because it  */
/* is much quicker to move a 4-byte    */
/* pointer than it is a large struct.  */
/***************************************/
void RadixSort(SortData DataArray[], SortData DataArray2[], int count)
{
    int            i, j, k, radixN, radixNplus1, index;
    SortData    *temp1[NUMRECS], *temp2[NUMRECS];
    SortData    **arrayIn, **arrayOut, **arrayTemp;

    /* Create initial array of pointers to structs */
    for(i=0; i<count; i++) temp1[i] = &DataArray[i];

    /* Set initial pointers to arrays of pointers */
    arrayOut = &temp1[0];
    arrayIn = &temp2[0];


    for(i=0; i<(int)ceil(log10(MAXKEY)); i++)  /* Get # digits in the key, i.e. ceil(log10(9999)) = 4 */
    {
        index = 0;                        /* Start at beginning of arrays of pointers */
        radixN = (int)ceil(pow(RADIX, i));
        radixNplus1 = radixN * RADIX;

        for(j=0; j<RADIX; j++)            /* Sort into 10 stacks */
        {
            for(k=0; k<count; k++)        /* Look at all records */
            {
                               /* To isolate one digit:  (num % radixi+1 ) / radixi */
               if( ( (int)floor(((*(arrayOut+k))->key % radixNplus1) / radixN)) == j)
                {
                    /* Copy the pointer */
                    *(arrayIn+index) = *(arrayOut + k);
                   // printf("Key moved = %.4d\n", (*(arrayIn+index))->key);
                    //getch();
                    index++;
                }
            }
        }
        /* Swap the array pointers */
        arrayTemp = arrayOut;
        arrayOut = arrayIn;
        arrayIn = arrayTemp;
    }

    /* Copy structs from Array1 in sorted order into Array2 */
    /* Use arrayOut here as it was the result of the last   */
    /*    sorting after the pointers were swapped.          */
    for(i=0; i<count; i++)
        DataArray2[i] = *(*(arrayOut + i));
}
   
/***************************************/
/* SelectSort()                        */
/*                                     */
/* Sort records on integer key using   */
/*  a selection sort.                  */
/***************************************/
void SelectSort(SortData DataArray[], int count)
{
    int            NextIdx;    /* Next open position in sorted section */
    int            LargestKey;    /* INdex of largest key in unsorted section */
    int            i;
    SortData    temp;

    NextIdx = count - 1;

    while(NextIdx > 0)
    {
        LargestKey = NextIdx;  /* Initialize the search by assuming the  */
                               /* entry in the next open position in the */
                               /* sorted section has the largest key.    */
        /* Find next largest key in unsorted section */
        for(i=0; i<NextIdx; i++)
            if(DataArray[i].key > DataArray[LargestKey].key)
                LargestKey = i;

        /* Swap the largest key with the one at the top of the Priority Queue */
        temp = DataArray[LargestKey];
        DataArray[LargestKey] = DataArray[NextIdx];
        DataArray[NextIdx] = temp;

        /* Set NextIdx to next position up */
        NextIdx--;
    }
}