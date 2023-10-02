CFLAGS = -c -std=c++11 
EXECUTAVEL = app
MAIN = app3


all: ${EXECUTAVEL}

${EXECUTAVEL}: 				${MAIN}.o Aplicacao.o Cinema.o Endereco.o Filme.o Programacao.o
							g++ -o app ${MAIN}.o Aplicacao.o Cinema.o Endereco.o Filme.o Programacao.o 

${MAIN}.o: 					${MAIN}.cpp Aplicacao.hpp 
							g++ ${CFLAGS} ${MAIN}.cpp

Aplicacao.o: 				Aplicacao.cpp Aplicacao.hpp Cinema.hpp Filme.hpp Programacao.hpp
							g++ ${CFLAGS} Aplicacao.cpp

Cinema.o: 					Cinema.cpp Cinema.hpp Endereco.hpp
							g++ ${CFLAGS} Cinema.cpp

Endereco.o: 				Endereco.cpp Endereco.hpp 
							g++ ${CFLAGS} Endereco.cpp

Filme.o: 					Filme.cpp Filme.hpp 
							g++ ${CFLAGS} Filme.cpp

Programacao.o:				Programacao.cpp Programacao.hpp Cinema.hpp Filme.hpp
							g++ ${CFLAGS} Programacao.cpp

clean:
							rm -f *.o ${EXECUTAVEL}

run: 						${EXECUTAVEL}
							@./${EXECUTAVEL}