test:-
	open('hogwart.txt',write,Stream),
	tab(Stream,9),
	write(Stream,'gryffindor'),
	nl(Stream),
	tab(Stream,2),
	write(Stream,'hufflepuff'),
	tab(Stream,5),
	write(Stream,'ravenclaw'),
	nl(Stream),
	tab(Stream,9),
	write(Stream,'slytherin'),
    close(Stream).