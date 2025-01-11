
// Excepting global variables/constants, all regular code must be
// written inside functions.

// Curly braces are used to mark the edges of code blocks. 

// Parentheses should NOT be used around conditions ("if" and loops).

// You must use the correct margins/indentation and 
// symmetrical positions for the curly braces.

// Each indentation step is made by 4 consecutive whitespaces.

// TABs are forbidden in BaseOne. 

// Many text editors can be configured to write
// a number of whitespaces when TAB is pressed.
// Check your text editor about that.

// Margins of comments are not checked, use them nicely.


 package main  // ERROR: forbidden margin here

func main() {

  @println()  // ERROR: too short margin (missing 2 whitespaces)
  
  
    if 1 > 2 { } else { } // ok, everything in one line
    
  
    if 1 > 2 {
  
    }
    else {  // ok, each block has its own lines
    
    }
    
    
    if 1 > 2  // ERROR: missing left curly brace
    {
  
    }
    else { 
    
    }
    
    
    if 1 > 2 {
    
    } else {  // ERROR: content after ending multiline block
    
    }
    
    
    if 1 > 2 {
    
    } 
    else { }  // ERROR: not symmetrical right curly brace
    
  
    @println() }  // ERROR: not symmetrical right curly brace


