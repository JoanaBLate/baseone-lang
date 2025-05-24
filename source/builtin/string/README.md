
All String functions that start with **createString** allocate heap memory. All other String functions don't.

Excepting the function 'stringCharCodeAt', String functions silently avoid 'index of out bounds' errors. 

Functions 'createStringReverse' and 'createStringSort' may corrupt Unicode symbols like '∆'.
(TODO: create stringReverseUnicode and stringSortUnicode)

