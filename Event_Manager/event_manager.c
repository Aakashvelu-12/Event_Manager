#include <stdio.h>
#include <stdlib.h>
#include "event_manager.h"

Event_t* event_head=NULL;
Event_t* event_tail=NULL;

Event_t* create_event(int event_id){
    Event_t* new_event=(Event_t*)malloc(sizeof(Event_t));
    new_event->event_id=event_id;
    new_event->count=0;
    new_event->next=NULL;
    new_event->prev=NULL;

    return new_event;   
}

void init(){
    for(int i=0;i<MAX_EVENTS;i++){
        Event_t* new_event=create_event(i+1);

        if(event_head==NULL){
            event_head=new_event;
            event_tail=new_event;
        }
        else{
            event_tail->next=new_event;
            new_event->prev=event_tail;
            event_tail=new_event;
        }
    }
}

void add_module(int event_id, response module){
    Event_t* current_event=event_head;

    while(current_event!=NULL){
        if(current_event->event_id==event_id){
            break;
        }
        current_event=current_event->next;
    }
    if(current_event->count==0){
        current_event->functions=malloc(sizeof(response));
    }
    else{
        current_event->functions=realloc(current_event->functions, (sizeof(response)) * (current_event->count+1));
    }
    current_event->functions[current_event->count++]=module;

    
}

void event_trigger(int event_id){
    Event_t* current_event=event_head;
    while (current_event!=NULL)
    {
        if(current_event->event_id==event_id){
            for(int i=0;i<current_event->count;i++){
                current_event->functions[i](current_event->event_id);
            }
            break;
        }
        current_event=current_event->next;
    }
    
}

