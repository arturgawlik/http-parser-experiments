build: 
	clang ./main.c -o ./main -O0 -I./deps/http-parser/ ./deps/http-parser/http_parser.o

link-http-parser:
	ln -s /home/artur-gawlik/git/http-parser /home/artur-gawlik/git/http-parser-experiments/deps/http-parser
