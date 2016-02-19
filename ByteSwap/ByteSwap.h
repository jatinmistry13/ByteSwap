//
//ÅyÉtÉ@ÉCÉãñºÅz ByteSwap.h
//
//Åy  äT  óv  Åz Contains the various headers and macros. 
//
//Åy çXêVóöó Åz 2010/10/22	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define	PLUS_SIGN			'+'	//Plus sign
#define MINUS_SIGN			'-'	//Minus sign
#define SPACES				' '	//Blank space
#define END_OF_STRING		'\0'//End of string character
#define ZERO				'0'	//zero
#define ONE					'1'	//One
#define	NINE				'9'	//Nine
#define TAB					'\t'//Tab
//Invalid integer
#define INVALID_INTEGER		"\nInvalid Integer : Not a Valid Number\n"
//Big value	
#define BIG_NUMBER			"\nInvalid Integer : Too big Number for Integer\n"

//Program Outline
#define DATATYPE_SELECT		"Please select from options below \n"
#define OPTION1				"Enter 1 for Integer\n"
#define OPTION2				"Enter 2 for Double\n"
#define OPTION3				"Enter 3 to EXIT\n"
#define USER_SELECT			"Enter Your Choice:\t"
#define INVALID_CHOICE		"INVALID CHOICE\n"
//Get Array Size
#define ARRAY_SIZE			"Enter Array Size not more than 5:\t"
//Get Array Values
#define ENTER_VALUE			"Enter value %d:\t"
//Format Specifier
#define INT_FORM			"%d"
#define DOUBLE_FORM			"%lf"
//Field specification for output
#define DOUBLE_PRINT		"%-20e\t"
#define HEXAL_PRINT			" %02X "
#define INTEGER_PRINT		"%-10d\t"
//Print a new line
#define NEW_LINE			"\n"

//Errors
#define INVALID_INPUT		"Invalid Input"
#define ERR_DISP			"Error while displaying hexal values..."
#define ERR_SWAP			"Error while swapping bytes..."
#define ERR_DISP_AFTER_SWAP	"Error while displaying hexal values after swapping..."

#define MAX_DIGITS			13			//Max length of digits in Integer
#define MAX_STR_LEN			256			//Max String length
#define MAX_ARRAY_SIZE		5			//Max Array size
#define MIN_ARRAY_SIZE      1			//Min Array size
#define MAX_CHOICE			3			//Max value for choice
#define MIN_CHOICE			1			//Min value for choice
#define INTEGER_RANGE		+2147483647	//Max value for positive integer
#define BOOL				int			//Boolean
#define TRUE				1			//False
#define FALSE				0			//True






