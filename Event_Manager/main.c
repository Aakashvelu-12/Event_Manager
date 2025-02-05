#include<stdio.h>
#include "module.h"
#include "event_manager.h"
#include "event_trigger.h"

int main(){

    init();

    int choice;
    
    do{
        printf("Select an action.\n");
        printf("Enter choice 0 to exit!\n");
        printf("Enter choice 1 to link an module to a event.\n");
        printf("Enter choice 2 to trigger an event.\n");

        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            int event_id;
            printf("Events present are \nEvent 1, Event 2, Event 3, Event 4, Event 5 \nEvent 6, Event 7, Event 8, Event 9, Event 10");
            printf("Enter the event id.\n");
            scanf("%d",&event_id);
            printf("\nThe module prsent are \nmodule 1 \nmodule 2 \nmodule 3 \nmodule 4 \nmodule 5\n");
            int module_id;
            printf("\nEnter the module id.\n");
            scanf("%d",&module_id);
            switch (module_id)
            {
            case 1:
                add_module(event_id,module_1);
                break;
            case 2:
                add_module(event_id,module_2);
                break;
            case 3:
                add_module(event_id,module_3);
                break;
            case 4:
                add_module(event_id,module_4);
                break;
            case 5:
                add_module(event_id,module_5);
                break;
            
            default:
                break;
            }
            break;
        
        case 2:
            int event_trigger_id;
            printf("\nEnter event id to trigger:\n");
            scanf("%d",&event_trigger_id);
            trigger(event_trigger_id);
            break;

        default:
            break;
        }

        

    }
    while(choice!=0);

    return 0;
}