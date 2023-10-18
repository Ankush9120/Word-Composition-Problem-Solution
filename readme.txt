Overview -

It is an program written in c++ language which is used to calculate the longest and second longest compound word from the given input files that is Input_01.txt and Input_02.txt.
Here , Trie data structure is used in order to minimize the time complexity for searching the words and provide the result in an efficient manner.


Design Decisions -

1. I have used the trie data structure which stores the words in a efficient manner which makes searching more easier in lesser time.
2. I have used the recursive approach to find all of the combinations within the words to check whether it is compounded or not.


Approach -

1. Firstly I have created an structure of the Trie Node.
2. I have created multiple functions for different operations such as node insertion (insertNode) , compound checking (isCompoundWord) , finding longest compound word (findLongestCompoundWord) , find second longest compound word (findSecondLongestCompoundWord).
3. In main function I am creating a trie node instance which is main root node of the trie then we start reading the words from the file and while reading the words we keep storing words in a vector and also inserting words in a trie simaltaneously.
4. Then we are storing the compound words in two different variable using function findLongestCompoundWord and findSecondLongestCompoundWord.
5. Then we are calculating the time which is used to process the current file.
6. Then we print our all of the outputs.


Steps to execute the code -

1. Firstly open the cmd terminal or vs code terminal in your windows / linux.
2. Then go the folder directory where all of these files belongs.
3. Then in terminal type the below mentioned command for compliation of the file.

    g++ solution.cpp -o solution

4. Then an executable file with the name solution.exe will be created in the directory , run that file using below command.

    ./solution.exe

5. Output will be shown in the terminal.