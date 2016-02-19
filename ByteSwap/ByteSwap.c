//
//ÅyÉtÉ@ÉCÉãñºÅz ByteSwap.c
//
//Åy  äT  óv  Åz Byte Swap Memory Address.	
//
//Åy çXêVóöó Åz 2010/10/22	Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "ByteSwap.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz ParseInt
//
//Åyì‡  óeÅz Converts input string to integer.
//
//Åyà¯  êîÅz [i] pszInputString : Input String.
//			 [o] pNInteger : Integer
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/12	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL ParseInt(char* pszInputString, int* pNInteger)
{
	int nLength = MAX_DIGITS;	//Max digits for integers
	int i = 0;					//Loop variable
	int j = 0;					//Loop variable
	double dblSize = 0;			//To store value from atof()
	BOOL bFinish = FALSE;		//Boolean to indicate finish of string
	char szNumSize[MAX_DIGITS] = {0};	//To store the numbers from string

	//Check input parameters
	if(pszInputString == NULL || pNInteger == NULL)
	{
		return FALSE;
	}

	szNumSize[j] = PLUS_SIGN;
	j++;

	//Till End of String not reached...
	while(pszInputString[i] != END_OF_STRING && (j < nLength ))
	{
		//Till we have leading spaces...
		while(pszInputString[i] == SPACES || pszInputString[i] == TAB)
		{
			i++;
		}

		//If '+/-' sign is present
		if(pszInputString[i] == PLUS_SIGN ||
			(pszInputString[i] == MINUS_SIGN))
		{
			j = 0;
			szNumSize[j] = pszInputString[i];
			i++;
			j++;
		}

		//spaces or tab after sign
		while(pszInputString[i] == SPACES || pszInputString[i] == TAB)
		{
			i++;
		}

		//If we have leading zeroes
		while(pszInputString[i] == ZERO)
		{
			i++;
		}

		//If a End of string is found
		if(pszInputString[i] == END_OF_STRING)
		{
			szNumSize[j] = END_OF_STRING;
			bFinish = TRUE;
		}

		//If a Number is not found..
		if(bFinish == FALSE &&
		   (pszInputString[i] > NINE || pszInputString[i] < ONE))
		{
			printf(INVALID_INTEGER);
			return FALSE;
		}

		//If a Number is found and is in the range...
		while((pszInputString[i] <= NINE && pszInputString[i] >= ZERO) &&
			  (j < nLength ))
		
		{
			//Read the number in szNumSize
			szNumSize[j] = pszInputString[i];
			j++;
			i++;

			//If next character is '\0'
			if(pszInputString[i] == END_OF_STRING)
			{
				szNumSize[j] = END_OF_STRING;
				break;
			}

			//If next Charcter is "spaces"
			while(pszInputString[i] == SPACES)
			{
				i++;
				
				//If next characyter is '\0'
				if(pszInputString[i] == END_OF_STRING)
				{
					szNumSize[j] = END_OF_STRING;
					break;
				}

				//Check if next character is also a "space"
				if(pszInputString[i] != SPACES)
				{
					printf(INVALID_INTEGER);
					return FALSE;
				}
			}
		}
	}

	//Convert string to integer
	dblSize = atof(szNumSize);

	if(dblSize > INTEGER_RANGE)
	{
		printf(BIG_NUMBER);
		return FALSE;
	}

	*pNInteger = (int)dblSize;
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz Byte Swap a particular Memory address.
//			 	
//Åyà¯  êîÅz [i] nothing. 	
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success,otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/22	Jatin Mistry
//-----------------------------------------------------------------------------

BOOL main()
{
	int nIndex = 0;						//Loop variable
	int nArraySize = 0;					//Array size
	int nI = 0;							//Loop variable
	int bReturn = FALSE;				//Boolean variable for checks
	int nChoice = 0;					//User data type selection
	char szString[MAX_STR_LEN]={0};		//Gets data frm user
	int aNArray[MAX_ARRAY_SIZE] = {0};	//Integer array	
	double aDblArray[MAX_ARRAY_SIZE] = {0};	//Double array

	//Display Program outline
	do
	{
		//Print Program outline
		_flushall();
		printf(DATATYPE_SELECT);
		printf(OPTION1);
		printf(OPTION2);
		printf(OPTION3);
		printf(USER_SELECT);
		gets(szString);

		//Check valid integer

		bReturn = ParseInt(szString, &nChoice);
		if(bReturn == FALSE)
		{
			continue;
		}

		if(nChoice<MIN_CHOICE || nChoice>MAX_CHOICE)
		{
			printf(INVALID_CHOICE);
			continue;
		}

		switch(nChoice)
		{
		//For Integer 
		case 1:
			//Read the Array Size
			printf(ARRAY_SIZE);
			gets(szString);

			bReturn = ParseInt(szString, &nArraySize);
			if(bReturn == FALSE)
			{
				continue;
			}

			//Check Array Size
			if(nArraySize > MAX_ARRAY_SIZE || nArraySize < MIN_ARRAY_SIZE)
			{
				printf(INVALID_INPUT);
				continue;
			}

			//Read values into the array
			nIndex = 0;
			while(nIndex < nArraySize)
			{
				printf(ENTER_VALUE, nIndex+1);
				gets(szString);
				bReturn = ParseInt(szString, &aNArray[nIndex]);
				if(bReturn == FALSE)
				{
					continue;
				}
				nIndex++;
			}
			
			printf(NEW_LINE);

			//Display values with hexal representation
			bReturn = Display((char*)aNArray, nArraySize, 
								nChoice, sizeof(int));
			if(bReturn == FALSE)
			{
				printf(ERR_DISP);
				return FALSE;
			}
			printf(NEW_LINE);

			//Swap bytes
			bReturn = SwapBytes(aNArray, nArraySize, sizeof(int));
			if(bReturn == FALSE)
			{
				printf(ERR_SWAP);
				return FALSE;
			}
			printf(NEW_LINE);

			//Display swap bytes(hexal values) with decimal representation 
			bReturn = Display((char*)aNArray, nArraySize, 
								nChoice, sizeof(int));
			if(bReturn == FALSE)
			{
				printf(ERR_DISP_AFTER_SWAP);
				return FALSE;
			}
			printf(NEW_LINE);

			break;

		//For Double
		case 2:
			//Read the Array size
			printf(ARRAY_SIZE);
			gets(szString);

			bReturn = ParseInt(szString, &nArraySize);
			if(bReturn == FALSE)
			{
				continue;
			}

			//Check Array Size
			if(nArraySize > MAX_ARRAY_SIZE || nArraySize < MIN_ARRAY_SIZE)
			{
				printf(INVALID_INPUT);
				continue;
			}

			//Read values into the array
			for(nIndex = 0; nIndex < nArraySize; nIndex++)
			{
				printf(ENTER_VALUE, nIndex + 1);
				scanf(DOUBLE_FORM, &aDblArray[nIndex]);
			}

			//Display values with hexal representation
			bReturn = Display((char*)aDblArray, nArraySize, 
								nChoice, sizeof(double));
			if(bReturn == FALSE)
			{
				printf(ERR_DISP);
				return FALSE;
			}
			printf(NEW_LINE);

			//Swap bytes
			bReturn = SwapBytes((void*)aDblArray, nArraySize, sizeof(double));
			if(bReturn == FALSE)
			{
				printf(ERR_SWAP);
				return FALSE;
			}
			printf(NEW_LINE);

			//Display swapped bytes(hexal values) with decimal representation 
			bReturn = Display((char*)aDblArray, nArraySize, 
								nChoice, sizeof(double));
			if(bReturn == FALSE)
			{
				printf(ERR_DISP_AFTER_SWAP);
				return FALSE;
			}
			printf(NEW_LINE);

			break;

		default:
			break;
		}

	}while(nChoice != MAX_CHOICE);
	
	return TRUE;
}


//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz Display
//
//Åyì‡  óeÅz Display the Hexadecimal equivalent
//			 	
//Åyà¯  êîÅz [o] pszData	: Pointer to array
//			 [i] nValues	: Size of Array
//			 [i] nDataType	: datatype to be used
//			 [i] nDataSize	: size of datatype
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success,otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/22	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL Display(char* pszData, int nValues, int nDataType, int nDataSize)
{
	int nIndexInner=0;			//Loop variable
	int nIndexOuter=0;			//Loop variable
	int* pNInt = NULL;			//Pointer to integer array
	double* pDblDouble = NULL;	//Pointer to double array

	//Check Inputs
	if(pszData == NULL, nValues == 0, nDataType == 0, nDataSize == 0)
	{
		return FALSE;
	}

	switch(nDataType)
	{
	//Integer
	case 1:
			pNInt = (int*)(pszData);
			//Display original values
			printf(INTEGER_PRINT, *pNInt);
			break;

	//Double
	case 2:
			pDblDouble = (double*)(pszData);
			//Display Original values
			printf(DOUBLE_PRINT, *pDblDouble);
			break;
	default:
			break;
	}

	for(nIndexOuter = 0; nIndexOuter < nValues; nIndexOuter++)
	{
		//Display hexal values
		for(nIndexInner = nDataSize-1; nIndexInner >= 0; nIndexInner--)
		{
			printf(HEXAL_PRINT, (unsigned char)pszData[ nIndexInner ]);
		}
		printf( NEW_LINE );
		pszData += nDataSize;
		pNInt++;
	}
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz SwapBytes
//
//Åyì‡  óeÅz Byte Swapping a particular Memory address.
//			 	
//Åyà¯  êîÅz [o] pData		: void Pointer
//			 [i] nValues	: size of Array
//			 [i] nDataSize	: size of datatype
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success,otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/22	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL SwapBytes(void* pData, int nValues, int nDataSize)
{
	int nIndex = 0;	//Loop variable
	int nAhead = 0;	//Marker to Move Ahead
	int nBack = 0;	//Marker to Move Back

	unsigned char cTemp = ZERO;		//Stores temporary character
	unsigned char* pszData = NULL;	//For hexal values

	//Check Inputs
	if(pData == NULL, nValues == 0, nDataSize == 0)
	{
		return FALSE;
	}
	//TypeCasting
	pszData = (unsigned char*) pData;

	for(nIndex=0; nIndex<nValues; nIndex++)
	{
		//Marker at start
		nAhead = 0;
		//Marker at end
		nBack = nDataSize-1;
		//Swap
		while(nAhead<nBack)
		{
			cTemp = pszData[nAhead];
			pszData[nAhead] = pszData[nBack];
			pszData[nBack] = cTemp;
			nAhead++;
			nBack--;
		}
		pszData += nDataSize;
	}
	return TRUE;
}
