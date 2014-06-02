# Very rudimentary Makefile for the llvm tutorial
# See http://llvm.org/docs/tutorial/
# See also http://koichitamura.blogspot.de/2011/01/since-i-went-to-held-several-weeks-ago.html
# for a necessary "fix" (!)
#
# This Makefile written by Prof. R. C. Moore, fbi.h-da.de

PROGS=toy2 toy3 toy4 toy5 toy6 toy7 ModuleMaker fibonacci

# Uncomment only one of the next two lines (choose your c++ compiler)
# CC=g++
CC=clang++
# (Rather) Minimalist
CFLAGS=`llvm-config --cppflags --ldflags --libs bitwriter core jit interpreter native` -rdynamic
# (Rather) Maximialist
CFLAGS=-O3 `llvm-config --cppflags --ldflags --libs all` -rdynamic

all: $(PROGS)

$(PROGS): %: %.cpp
	$(CC) -g $< $(CFLAGS) -o $@

clean:
	$(RM) *~ $(PROGS) ModuleMaker.bc

testModuleMaker: ModuleMaker
	echo && echo "Testing ModuleMaker (expect 5)...\n"
	./ModuleMaker >ModuleMaker.bc
	@lli ModuleMaker.bc || echo $$?

testFibonacci: fibonacci
	echo && echo "Testing fibonacci (expect 46368)...\n"
	@./fibonacci

test3: toy3 tests/test3.kal
	echo && echo "Testing toy3...\n"
	@./toy3 <tests/test3.kal

test4: toy4 tests/test4.kal
	echo && echo "Testing toy4...\n"
	@./toy4 <tests/test4.kal

test5: toy5 tests/test5.kal
	echo && echo "Testing toy5...\n"
	@./toy5 <tests/test5.kal

test6: toy6 tests/test6.kal
	echo && echo "Testing toy6...\n"
	@./toy6 <tests/test6.kal

#test7: toy7 tests/test7.kal
#	echo && echo "Testing toy7...\n"
#	@./toy7 <tests/test7.kal

tests: test3 test4 test5 test6 testModuleMaker testFibonacci

