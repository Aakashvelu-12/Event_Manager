#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#define MAX_EVENTS 10

typedef void(*response)(int);
typedef struct Event{
    int event_id;
    int count;
    response* functions;
    struct Event* next;
    struct Event* prev;
} Event_t;

Event_t* create_event(int event_id);
void init();
void add_module(int event_id,response module);
void event_trigger(int event_id);

#endif