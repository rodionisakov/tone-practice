This program focuses on practising the tones for Chinese language learners at elementary level.
The aim of the project was to introduce a way of memorising Chinese tones.
The program is written in C language.

The program has three sections: Studying, Testing and Review. 
The studying section allows the user to choose between words of 30 topics based on Boya Chinese Elementary textbook. 
The program displays Pinyin and translation of the words from the user selected topic. 
The testing section is the main section of the program that provides the practice of Chinese tones. 
Just like the studying section, the user can choose from 30 topics based on the book mentioned earlier. 
The program then outputs a word in English asking the user to input the pinyin of the given word in Chinese language. 
The user is given 3 attempts to get the answer right. Every correct answer is recorded on a separate text
file which can be viewed in the third, final, section – review, which can be used for self-checking and educational purposes. 

run tone-practice.cpp to start the program

NOTE:
Input Pinyin in a way described below:

"Hello - ni3hao3"

Number of tone after the character syllable.

The program relies on a set of 30 text files each containing a set of words for every unit from the Boya Chinese Elementary textbook.
Each file is named “topic(number of the unit).txt” i.e “topic1.txt”,”topic2.txt” etc. Each text file has a pinyin and
an English word on every line written in a format “pinyin_English word”. 

The program creates a review file that allows viewing the words mastered.
It appends or creates a text file “review.txt” where all the correct answers are stored.