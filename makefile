exec: bigEnvironment.o plannerTester.o display.o pathPlanner.o obstacles.h
	gcc -o bigEnvironment bigEnvironment.o display.o pathPlanner.o obstacles.h -lX11
	gcc -o plannerTester plannerTester.o display.o pathPlanner.o obstacles.h -lX11
	
clean:
	rm -f *.o
