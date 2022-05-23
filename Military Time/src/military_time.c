#include "military_time.h"
#include <string.h>

// goal: creates a Time struct given the hour, minute, and second
// param hour: int representing the hour 0-23
// param min: int representing the minute 0-59
// param sec: int representing the second 0-59
// assumptions:
//   the inputs are that of a valid military time.
// return: a Time struct for the time representing the same time as the integers
//
// TODO: complete the function
struct Time create_time(int hour, int min, int sec) {
	struct Time ret;
  	ret.hour = hour;
	ret.min =min;
	ret.sec= sec;
  	return ret;
}

// goal: gets the hour from a Time struct
// param t: pointer that point to a struct representing a time
// return: an int representing the hour of time t
//
// TODO: complete the function
int get_hour(struct Time *t) {
  	return t->hour;
}

// goal: gets the minute from a Time struct
// param t: pointer that point to a struct representing a time
// return: an int representing the minute of time t
//
// TODO: complete the function
int get_min(struct Time *t) {
 	return t->min;
}

// goal: gets the second from a Time struct
// param t: pointer that point to a struct representing a time
// return: an int representing the second of time t
//
// TODO: complete the function
int get_sec(struct Time *t) {
  return t->sec;
}

// goal: sets the hour to a Time struct
// param t: pointer that point to a struct representing a time
//
// TODO: complete the function
void set_hour(struct Time *t, int hour) {
	t->hour = hour;
}

// goal: sets the minute to a Time struct
// param t: pointer that point to a struct representing a time
//
// TODO: complete the function
void set_min(struct Time *t, int min) {
	t->min = min;
}

// goal: sets the second to a Time struct
// param t: pointer that point to a struct representing a time
//
// TODO: complete the function
void set_sec(struct Time *t, int sec) {
	t->sec = sec;
}


// goal: Creates a Time struct representing the difference between two times (t2
// - t1) param t1: pointer that point to a Time struct representing the
// beginning of interval param t2: pointer that point to a Time struct
// representing the end of interval return: Time struct representing time
// between t1 and t2
//
// TODO: complete the function
struct Time elapsed_time(struct Time *t1, struct Time *t2) {
  struct Time dt;
	int t1sum = (t1->hour)*3600 + (t1->min)*60 +(t1->sec);
	int t2sum = (t2->hour)*3600 + (t2->min)*60 +(t2->sec);
	if (t2sum > t1sum){
		t2sum -= t1sum;
		dt.hour = t2sum/3600;
		dt.min = (t2sum - 3600*dt.hour)/60;
		dt.sec = t2sum -3600*dt.hour -dt.min*60;
	}
	else{
		t2sum += 24*3600;
		t2sum -= t1sum;
                dt.hour = t2sum/3600;
                dt.min = (t2sum - 3600*dt.hour)/60;
                dt.sec = t2sum -3600*dt.hour -dt.min*60;
	}
  return dt;
}

// goal: remove a substring of str beginning at index idx and having length len
// param str: the string being altered
// param idx: the starting index of the removed chunk
// param len: the number of characters to remove (length of substring being
// removed) assumptions:
//   0 <= idx
//   str is a valid string that terminates properly
//
// TODO: complete the function
void remove_substr(char str[], int idx, int len) {
	char *ptr = str;
	int strLength = strlen(str);
	if ((idx >= strLength) || (idx < 0) || (len ==0)){
		//no change here!
	}
	else if ((idx + len) >= strLength){
		for(ptr = &str[idx]; ptr < &str[strLength]; ptr++) *ptr = NULL;
	}
	else{
		for(ptr = &str[idx]; ptr < &str[strLength]; ptr++) *ptr = *(ptr+len);
		//for(int i= 0; i <len; i++){for(ptr = &str[idx]; ptr < &str[strLength]; ptr++) *ptr = *(ptr+1);}
	}

}
