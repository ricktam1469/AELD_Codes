CC =  g++ -c -I. -I/opt/systemc-2.3.1/include -L. -L/opt/systemc-2.3.1/lib-linux64 -Wl,-rpath=/opt/systemc-2.3.1/lib-linux64 -lsystemc -lm
CC1 = g++ -I. -I/opt/systemc-2.3.1/include -L. -L/opt/systemc-2.3.1/lib-linux64 -Wl,-rpath=/opt/systemc-2.3.1/lib-linux64 -lsystemc -lm



ALL: Main.cpp NOC.o Integrate.hpp loadProgram.hpp Packet.hpp Registers.hpp 
	$(CC1)  NOC.o Main.cpp -o out

Integrate.o: Integrate.hpp loadProgram.hpp Registers.hpp Packet.hpp
	$(CC1) Integrate.hpp loadProgram.hpp Registers.hpp Packet.hpp

NOC.o:	NOC.cpp NOC.hpp loadProgram.hpp Packet.hpp
	$(CC) NOC.cpp NOC.hpp loadProgram.hpp Packet.hpp

	
clean:
	rm -rf *o out
