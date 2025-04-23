LLHTTP_LOCAL_REPO=/home/artur-gawlik/git/llhttp
DEPS=/home/artur-gawlik/git/llhttp-experiments/deps
LLHTTP_DEPS=${DEPS}/llhttp
LLHTTP_DEPS_BUILD=${LLHTTP_DEPS}/build/
LLHTTP_DEPS_BUILD_LIB=${LLHTTP_DEPS_BUILD}libllhttp.a

build: 
	clang ./main.c -o ./main -O0 -I./deps/http-parser/ ./deps/http-parser/http_parser.o

link-http-parser:
	ln -s /home/artur-gawlik/git/http-parser /home/artur-gawlik/git/http-parser-experiments/deps/http-parser
