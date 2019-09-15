all: a.out b.out c.out d.out e.out f.out

a.out: a.cpp
	g++ --std=c++14 a.cpp -o a.out

b.out: b.cpp
	g++ --std=c++14 b.cpp -o b.out

c.out: c.cpp
	g++ --std=c++14 c.cpp -o c.out

d.out: d.cpp
	g++ --std=c++14 d.cpp -o d.out

e.out: e.cpp
	g++ --std=c++14 e.cpp -o e.out

f.out: f.cpp
	g++ --std=c++14 f.cpp -o f.out


.PHONY: clean
clean:
	rm a.out b.out c.out d.out e.out f.out

.PHONY: setup
setup:
	cp lib/tmpl.cpp a.cpp
	cp lib/tmpl.cpp b.cpp
	cp lib/tmpl.cpp c.cpp
	cp lib/tmpl.cpp d.cpp
	cp lib/tmpl.cpp e.cpp
	cp lib/tmpl.cpp f.cpp
	make
