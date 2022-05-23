#include "event.h"

// Creates a Event struct given the hour, minute, and second, and event id
//   param hour: int representing the hour 0-23
//   param min: int representing the minute 0-59
//   param sec: int representing the second 0-59
//   param event_id: int representing the event id >= 0
//   return: a Event struct with event id and its time
// TODO: complete the function
struct Event create_new_event(int hour, int min, int sec, int event_id) {
  struct Event ret;
  ret.event_id = event_id;
  int time = hour*10000 + min*100 + sec;
  ret.st.militaryTime = time;
  return ret;
}

// Gets the hour from a Time struct
//   param t: struct representing a time
//   return: an int representing the hour of time t
// TODO: complete the function
int get_hour(struct Time t) {
  int genTime = t.militaryTime;
  int hour = genTime/ 10000;
  return hour;
}

// Gets the minute from a Time struct
//   param t: struct representing a time
//   return: an int representing the minute of time t
// TODO: complete the function
int get_min(struct Time t) {
  int genTime = t.militaryTime;
  int min = (genTime - (genTime/ 10000)*10000)/100;
  return min;
}

// Gets the second from a Time struct
//   param t: struct representing a time
//   return: an int representing the second of time t
// TODO: complete the function
int get_sec(struct Time t) {
  int genTime = t.militaryTime;
  int sec = genTime - (genTime/ 100)*100;
  return sec;
}

// Gets the event id from a Event struct
//   param e: struct representing a event
//   return: an int representing the id of event e
// TODO: complete the function
int get_event_id(struct Event e) {
  return e.event_id;
}

// Gets the time from a Event struct
//   param e: struct representing a event
//   return: a Time struct representing the time of event e
// TODO: complete the function
struct Time get_event_time(struct Event e) {
  struct Time ret;
  ret = e.st;
  return ret;
}

// Creates a Time struct representing the time difference between two events of
// today
//   param e1: Event struct representing the first event
//   param e2: Event struct representing the second event
//   return: Time struct representing time between e1 and e2
// TODO: complete the function
struct Time elapsed_time(struct Event e1, struct Event e2) {
  struct Time ret;
  //int result = e1.st.militaryTime - e2.st.militaryTime;
  //(result > 0) ? (ret.militaryTime = result) : (ret.militaryTime = 0- result);
  int transferToSec1 = get_hour(e1.st) *3600 +get_min(e1.st)*60 +get_sec(e1.st);
  int transferToSec2 = get_hour(e2.st) *3600 +get_min(e2.st)*60 +get_sec(e2.st);
  int delta = transferToSec1-transferToSec2;
  if (delta <0) delta *= -1;
  int hour =delta/3600; int min = (delta - hour*3600)/60; int sec = delta - hour*3600- min*60;
  struct Event tempE = create_new_event(hour, min, sec, 0);
  ret.militaryTime =tempE.st.militaryTime;
  return ret;
}
