Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).# Lab1_arch1_2021

   This will be a brief description of each of the functions and how they
work. It should be noted that for readability, enumeration of NO and YES are
for values 0 and 1 respectively. It's much easier to ready this way as if a
question like, "Is space_char(char c) return a white space?" The other
mentionable is simply starting a pointer pointer variable for the tokenize
features since outside the functions, there's no way to refer to the finsihed
work done. Now, onto the functions.

    Starting off with "space_char" and "non_space_char". They are just
opposites of each other. They both check for white space characters (specificlly space,
tab, and newline characters, not all escape sequences), and if the char given
is white space character will return true or false depending on which function
is called (space_char looking for the white space, non_space_char excepting
any other character). The functions "word_start" simply takes in a string and
assuming there aren't multiple white spaces in the beginning, but does count
for whether the current string starts with one space and pushes forward one
index if it does and assumes that's where the real start of the string
appears. It still would go through the entire string looking for the first
non-white space character and return a pointer to it. The function
"word_terminator" starts the same way and iterates through the string looking
for the first white space character and returns the pointer to that character.

    The next one that's a bit more tricky is "count_words". While resusing the
previous functions to make the function easier, it iterates over the entire
string, keeps checking whether state "inWord" enters a word, and then
increases the count of "words". Simply put, every time there's a non-white
space character after there was a white space character being read, the
pointer must be inside a word, namely the start of it, and counts the words
this way without the need to repeat the iteration over the string. The
function "*copy_str" is pretty simple. Given a string, it allocates memory for
a local empty string, copies the characters from the original string "inStr"
up to "len" characters into "inStr" and returns the local copy of the new
string.

    The "tokenize" function was the most difficult for the "tokenizer"
file. Since this function wouldn't be able to return a double pointer variable
and the input doesn't take in one, it was necessary, or perhaps just easier,
to create the variable "*tokens[5000]" so the entire program could see them
and be used to tokenize strings. The concept is rather pretty simple: use two
character pointers that point to the start and end of each word, then call
"*copy_str" to copy the word from start to end, insert it into the i-th
position in the char* array, move the starting char* to the end char* and then
repeat the process until all the words have been tokenized. Functions
"print_tokens" and "free_tokens" is the same way. Both functions travers the
**tokens array and either prints all the tokens or frees the tokens from
memory depending on which function is called. The function "*get_token" simply
traverses the array of pointers using 'i' and comparing it to the input 'id'
value and returns a pointer to that specific token.

    The history functions were a bit more complicated, but since the file uses
a linked list to keep track, the methods are straight-forward as long as it's
ensured that the linked-list is being traversed using a separate List* instead of the
input List* given. List only needs a pointer to an Item and each Item has a
pointer "next" to keep the linked-list going. Initializing the history
[init_history()] only needs to create the structure, so a new List* is created
and memory allocated, then assigned to the root. The rest is pretty
straight-forward. The function "add_history" takes in a string, creates a new
memory allocated Item (which uses the variable "hItems" outside the scope of
all the functions to keep track of ID's for the history)

