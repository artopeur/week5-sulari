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
