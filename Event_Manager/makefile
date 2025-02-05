CC = gcc
CFLAGS = -Wall
OBJFILES = main.o event_manager.o module.o event_trigger.o
EXEC = program

all : $(EXEC)

module.o : module.c module.h
	$(CC) $(CFLAGS) -c module.c 

event_manager.o : event_manager.c event_manager.h
	$(CC) $(CFLAGS) -c event_manager.c 

main.o : main.c event_manager.h module.h event_trigger.h
	$(CC) $(CFLAGS) -c main.c 

event_trigger.o : event_trigger.c event_trigger.h event_manager.h
	$(CC) $(CFLAGS) -c event_trigger.c

$(EXEC) : $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(EXEC)

clean:
	rm -f $(OBJFILES) $(EXEC)
