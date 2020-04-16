#include "TheStack.h"

//STACK THAT HOLDS INTEGERS
/************************************************************************/
//checks if stackValues is empty
bool StackValues::isEmpty(){
    if(inUse == 0) //if there are no elements in the dynamic array
        return true;//return true

    return false; //false if not empty
}
/************************************************************************/
//Pishing values inside of the in dynamicArray
void StackValues::Push(int T){
    /*If the number of data stored in the dynamic
    array is equal to its total capacity, then we have
    to increase the size of the array to store more data*/
    if(inUse == TheSize){
        int *temp = intDarr; //storing data in temp
        intDarr = new int[TheSize + 2]; //Increment the current size by 2

        //Looping through the existing dara and storing it into
        //The new intDarr
        for(int i = 0; i < inUse; i++){
            intDarr[i] = temp[i];
        }

        //Deleting data in temp as we dont need it anymore
        delete[]temp;
        //Incrementing the size
        TheSize+=2;
    }
    //Now we can push the elements
    intDarr[inUse] = T;
    //number of elements inside stack increases as we added more data
    inUse++;
}
/************************************************************************/
//This function will remove the element at the top of the stack
void StackValues::Pop(){
    if (inUse != 0){ //If the stack isnt empty
        inUse--; //then get rid of last element
    }
}
/************************************************************************/
//This function will return the value that is at the top of the stack
int StackValues::Top(){
    return intDarr[inUse - 1];
}
/************************************************************************/
//This function returns the number of elements inside of the stack
int StackValues::getInUse(){
    return inUse;
}


//STACK THE HOLDS OPERATORS
/************************************************************************/
//checks if StackOps is empty
bool StackOps::isEmpty(){
    if(inUse == 0) //if there are no elements in the dynamic array
        return true;//return true

    return false; //false if not empty
}
/************************************************************************/
//Pishing values inside of the in dynamicArray
void StackOps::Push(char T){
    /*If the number of data stored in the dynamic
    array is equal to its total capacity, then we have
    to increase the size of the array to store more data*/
    if(inUse == TheSize){
        char *temp = charDarr; //storing data in temp
        charDarr = new char[TheSize + 2]; //Increment the current size by 2

        //Looping through the existing dara and storing it into
        //The new intDarr
        for(int i = 0; i < inUse; i++){
            charDarr[i] = temp[i];
        }

        //Deleting data in temp as we dont need it anymore
        delete[]temp;
        //Incrementing the size
        TheSize+=2;
    }
    //Now we can push the elements
    charDarr[inUse] = T;
    //number of elements inside stack increases as we added more data
    inUse++;
}
/************************************************************************/
//This function will remove the element at the top of the stack
void StackOps::Pop(){
    if (inUse != 0){ //If the stack isnt empty
        inUse--; //then get rid of last element
    }
}
/************************************************************************/
//This function will return the value that is at the top of the stack
int StackOps::Top(){
    return charDarr[inUse - 1];
}
/************************************************************************/
//This function returns the number of elements inside of the stack
int StackOps::getInUse(){
    return inUse;
}
/************************************************************************/
/*This folowing class cam be used by both operators.
It evaluates the following result, pops both stacks and pushes 
result back into the stack that holds integer values*/
void PopAndEvaluate(StackOps &StackO, StackValues &StackV){
    int result = -999; //default result value

    int int1 = StackV.Top();  //retrieves data from stack
    StackV.Pop(); //removes data
    int int2 = StackV.Top(); //retrieves data from stack
    StackV.Pop(); // removes data

    char op1 = StackO.Top(); //takes operator from stack
    StackO.Pop(); //removes it

    //Now we crate the conditions depending on the operator
    if (op1 == '+')
        result = int1 + int2;
    else if (op1 == '-')
        result = int1 - int2;
    else if (op1 == '*')
        result = int1 * int2;
    else if(op1 == '/')
        result = (int1 / int2);
    
    StackV.Push(result); //pushing int result into the values stack
}
/************************************************************************/
