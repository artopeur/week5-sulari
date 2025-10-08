#include <stdlib.h>
#include <string.h>
#include "TimeParser.h"

// time format: HHMMSS (6 characters)
int time_parse(char *time) {
	
	if(strlen(time) > 6) {
		return TIME_ARRAY_ERROR;
	}
	if(strlen(time) < 6) {
		return TIME_ARRAY_ERROR;
	}
	// how many seconds, default returns error
	int seconds = TIME_LEN_ERROR;

	// TODO: Check that string is not null
	if(strlen(time) == 0) {
		return TIME_ARRAY_ERROR;
	}
	// Parse values from time string
	// For example: 124033 -> 12hour 40min 33sec
    int test = checkChars(time);
	if(!test) {
		return test;
	}
	int values[3];
	values[2] = atoi(time+4); // seconds
	time[4] = 0;
	values[1] = atoi(time+2); // minutes
	time[2] = 0;
	values[0] = atoi(time); // hours
	// Now you have:
	// values[0] hour
	// values[1] minute
	// values[2] second
	if(values[0] > 59 || values[1] > 59 || values[2] > 23) {
		return TIME_VALUE_ERROR;
	}
	int hours = values[0] * 60 * 60;
	int minutes = values[1] * 60;
	seconds = values[2];
	seconds = hours + minutes + seconds;
	// TODO: Add boundary check time values: below zero or above limit not allowed
	// limits are 59 for minutes, 23 for hours, etc

	// TODO: Calculate return value from the parsed minutes and seconds
	// Otherwise error will be returned!
	// seconds = ...

	return seconds;
}

checkChars(char *characters) {
	if(characters == NULL) {
		return CHARACTERS_NULL_ERROR;
	}
	else {
		if(checkIfNumber(characters[0])) {
			if(checkIfNumber(characters[0]) != true) {
				return WRONG_CHARS_ERROR;
			};
			return 0;
		}
		else {
			return WRONG_CHARS_ERROR;
		}
	}
	return -1;
}
char checkIfNumber(char character) {
	switch(character) {
		case '0': return '0';
		case '1': return '1';
		case '2': return '2';
		case '3': return '3';
		case '4': return '4';
		case '5': return '5';
		case '6': return '6';
		case '7': return '7';
		case '8': return '8';
		case '9': return '9';
		case 'R': return true;
		case 'Y': return true;
		case 'G': return true;
		case 'T': return true;
		case 'J': return true;
		case 'L': return true;
		case 'M': return true;
		case 'N': return true;
		case 'D':return true;
	}
	return -1;
}