
//Class that will hold int values
class StackValues{
    private:
        int TheSize; //space currently allocated
        int inUse; //space in use
        int* intDarr; //pointer to dynamic array

    public:
        //This is the initializer of the stack
        StackValues(){
            intDarr = new int[2]; //allocated in memory
            inUse = 0; //Nothins is in use as its being initialized
            TheSize = 2; 
        }

        //Destructor: Will automatically be called as the operation reaches its end
        virtual ~StackValues(){
            delete[]intDarr;
        } 

        bool isEmpty(); //checks if the stack is empty
        void Push(int T); //pushes values into stack
        void Pop(); //removes value
        int Top(); //retieves value at top of stack
        int getInUse(); //gets current space in use

};

//stack that will hold my operators
class StackOps{
    private:
        int TheSize; //space currently allocated
        int inUse; //space in use
        char* charDarr; //pointer to dynamic array

    public:
      //initializer
        StackOps(){
            charDarr = new char[2]; //allocated in memory
            inUse = 0; //Nothins is in use as its being initialized
            TheSize = 2;
        }
        
        //Destructor: Will automatically be called as the operation reaches its en
        virtual ~StackOps(){
            delete[]charDarr;
        }
         
        bool isEmpty(); //checkis if stack is empty
        void Push(char T); //pushes values into stack
        void Pop(); //removes value at top
        int Top(); //retieves value at top
        int getInUse(); //gets space in use

};

/*******************************************************************/
/*This folowing class cam be used by both operators.
It evaluates the following result, pops both stacks and pushes 
result back into the stack that holds integer values*/
void PopAndEvaluate(StackOps &StackO, StackValues &StackV);
/*******************************************************************/