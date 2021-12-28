all: derle bagla calistir
derle:
	g++ -c -I  "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I  "./include" ./src/nokta.cpp -o ./lib/nokta.o
	g++ -c -I  "./include" ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
	g++ -c -I  "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
bagla:
	g++ ./lib/nokta.o ./lib/main.o ./lib/DogruKuyrugu.o ./lib/AVLAgaci.o -o ./bin/program
calistir:
	./bin/program