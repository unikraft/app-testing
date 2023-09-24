#!/bin/bash

test -d workdir/unikraft || git clone https://github.com/unikraft/unikraft workdir/unikraft

if test -f libs.txt; then
    libstring=""
    while read l; do
        libstring="$libstring:"'$(UK_LIBS)/'"$l"
        test -d workdir/libs/"$l" || git clone https://github.com/unikraft/lib-"$l" workdir/libs/"$l"
    done < libs.txt
    libstring=${libstring:1}
fi

cat > Makefile <<END
UK_ROOT ?= \$(PWD)/workdir/unikraft
UK_LIBS ?= \$(PWD)/workdir/libs
UK_BUILD ?= \$(PWD)/workdir/build
LIBS ?= $libstring

all:
	@\$(MAKE) -C \$(UK_ROOT) A=\$(PWD) L=\$(LIBS) O=\$(UK_BUILD)

\$(MAKECMDGOALS):
	@\$(MAKE) -C \$(UK_ROOT) A=\$(PWD) L=\$(LIBS) O=\$(UK_BUILD) \$(MAKECMDGOALS)
END

