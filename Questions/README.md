# Theorical questions

[Back to main README](../README.md)


1. What are the steps involved in the compilation process?
myFile(.hpp), myFile(.cpp)  >  myFile(.i)   >  myFile(.o)  >  myFile(.exe)

    A. Preprocessing
        The compiler takes all #preprocessor and replaces them. 
        This also means taking all imported code from #include "my.hpp" and 'pasting it' into the file importing it.

    B. Compilation
        We transform all C++ synthax and code into asembly code effectively creating object files.
        Then these object files are compiled from asembly to binary.

    C. Linking
        We write binary object files all together into one executable. 
        We link all declaration/definitions/call for everything to work together.


2. What is the difference between a declaration and a definition?
    Declaration: Announcing to the program that THIS and THAT exist and they look a certain way.
    Definition:  Programming all the behaviours and logic behind THIS and THAT. How they work/process things


3. What is the difference between passing a parameter by value, by reference, and by pointer?
    by value: 
        Make a copy of the object. 
        Effectively "duplicating" the value in memory
    by pointer: 
        Pass a memory address (pointer) of that value. 
        Effectively 'linking' the in-scope parameter and out-of-scope to the same memory address.
        Writing to one will write to the other (because they are the same place)
        Reading one will be just like reading the other (because they are the same place)
        A pointer can be null (0/nullptr)
    by reference
        The same as by pointer BUT the value 'is not a pointer' 
        (we don't have te dereference it, event tho it's a pointer 'behind the scene')
        A reference MUST be given at declaration time. Because a reference cannot be null (0/nullptr)


4. What is the difference between the stack and the heap?
    The stack is contiguous and created at the start of the program.
    Effectively even functions/for/while/... create mini-stacks, at each new {} braket.

    The Heap is non-contiguous. Everytime a new object is created in it, we don't really know
    where it will go before the allocator/os tell us where itplaced it.

    To create in the heap, use the keyword `new`. Don't for the stack.


5. What is the difference between struct and class in C++?
    I would say conceptually that a struct is pure DATA and NO BEHAVIOUR while a class is BOTH.
    A struct is by default PUBLIC while a class is PRIVATE.

    Fundamentally, I don't think I know. 
    Because we can create methods in struct and don't give process/behaviour to a class...


6. What is the difference between the public, protected, and private access specifiers?
    public: anyone anywhere can access/use it.
    protected: any CHILD of the class can access/use it.
    private: only the class itself can access/use it.


7. What is a pure virtual function? What effect does it have on a class?
    `virtual void myFunc() = 0;` 
    is a way to tell that this class SHOULDN'T (in fact CANNOT) be instantiated directly from.
    it 'marks' the class as `abstract`
    it forces its CHILD to implement it (aka. declare and define their version of it)


8. Briefly explain the diamond problem in multiple inheritance.
    ```   
          A
         / \
        B1 B2
         \ /
          C   ```

    Here we can see that `B1` & `B2` poth heritate from `A`. But the issue is that `C` heritates from two parents: `B1` & `B2`.
    In this case, inside the memory, `C` will exists as:
    
    ``` [A][B1][A][B2][C] ```
    
    Which is a big probleme becaus when we want (from `C`) refere to a variable from `A`, which one do I pick ?

    To counter-act this problem, we can mark `class B1 : virtual public A` and same for `B2`.
    That way, if the constructor of `B1` or `B2` sees that there is already a `A` inside the `C` object, it will not create it again.


9. Name the different containers studied in class and describe the strengths and weaknesses of each.
    array    - `auto myArray[];`
          They are contiguous in memory
        + Really fast to iterate through them
        - Finding something inside a giant array is expansive
        - "Unmutable" behaviour. You cannot change its size. And if you do good luck. 
          Good if you know at compile time the size they'll be and will not change.

    lists    - `List<auto> myList;` (Sorry, it's C# synthaxe)
          The are not contiguous in memory (a serie of 'node' pointing to the next)
        + Mutable. We can change its size
        + Inserting and removing elements mid-container.
        - Really Slow to iterate through them.

    vectors  - `vector<auto> myVector;`
          They are contiguous in memory (because behind there are arrays)
        + Really fast to iterate through them.
        - Finding something inside is still difficulte
        + Mutable !! When you add something, it tries to find the next contiguous space in memory to place its data. 
          Effectively being the best mid-point between an array and a list 

    dict,map - `unordered_map<myHash, auto> myMap;`
          They 'link' a hash (kind of an id) to a value in memory
          Act as a Library in which indexes are not necessarly int.
        + Really fast to look for something specific
        + You can iterate throught them quite well too


10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change.

    array.
    You can change its values but the number of them will never change.

- You need to manage a queue of tasks that must be executed in the order they arrive.

    vector as FIFO.
    The vector can pop its first element and collapse all others right to left.

- You frequently need to insert and remove elements in the middle of a sequence.

    list.
    You can insert, move, add, replace, everything without having to move all your container.

- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.

    unordered_map.
    Finding is the absolute priority and order doesn't matter.

- You need to keep track of actions so that the most recent action can be undone before earlier actions.

    vector or an array of pointers, as LIFO.
    It depends if you know at compile time that your max_Action_count will not move. 
    If it can grow, then use a vector with a reserve() and rereserve OCCASIONNALY in rare scenarios. But at least you are not locked with
    the array.
    If it never changes and it will always be LIFO, array of pointer is good too.

- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.

    vector.
    We need to iterate fast through them so the array behind the scene is good, but we also need to be able to change its nubmer over time.

- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.

    (ordered) map.
    An ID is number-like. Either it's hexa, binary or a mix of `string-NN-divN` where N are numbers.
    First you can iterate through it quickly to make stats and treat data.
    Second, you can find any grade quickly thanks to the ID acting as the hash-Key of the grade-Value.
