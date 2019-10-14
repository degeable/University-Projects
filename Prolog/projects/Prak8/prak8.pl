%6.2
%a is the b part without writing it to the file instead just write
%b

%works but the dots at the end of the predicates are missing...
read_stuff(Stream,[]):-
	at_end_of_stream(Stream).

read_stuff(Stream,[X|L]):-
	\+ at_end_of_stream(Stream),
	read(Stream,X),
	open('family2.pl',append,File2),
	write(File2,X),write(File2,'.'),
    nl(File2),
	close(File2),
	read_stuff(Stream,L).
	
read_toThree(Stream,[X|L],N):-
	\+ at_end_of_stream(Stream),
	read(Stream,X),
	open('family2.pl',append,File2),
    functor(X,Name,Arity),
    write(File2,'% '),write(File2,N),tab(File2,1),
    (Name == ':-'
    ->write(File2,' Rule')
    ;write(File2,Name),write(File2,' Fact')
    ),
    tab(File2,1),write(File2,Arity),nl(File2),
	write(File2,X),write(File2,'.'),
    nl(File2),
	close(File2),
    M is N +1,
	read_toThree(Stream,L,M).
	
readTo:-
	open('family1.pl',read,Stream),
	read_stuff(Stream,Stuff),
	close(Stream),!,
	test.
	
readTo2:-
    open('family1.pl',read,Stream),
    read_toThree(Stream,Stuff,1),
    close(Stream).

test:-
     consult(family2),
	 ancestor(X,Y),
	 write(X),nl,
	 write(Y),nl.

read_toFive(Stream,[X|L]):-  
    \+ at_end_of_stream(Stream),
	read_string(Stream,".","",End,X), % string to term read_clause
	%open('family5.pl',append,File2),
    split_string(X,".:-",",",String),
    write(String),
    read_toFive(Stream,L).
    %close('family5.pl').
	

writeToFive:-
    open('family1.pl',read,Stream),
    read_toFive(Stream,Stuff),
    close(Stream).
    


    
