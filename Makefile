

all:
	gcc depth.cpp -DFIRST -ftemplate-depth=4000 -o depth
	gcc depth.cpp -ftemplate-depth=4000 -o depth4


.PHONY: depth depth4
