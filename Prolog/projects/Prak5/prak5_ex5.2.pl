%5.2


count_leafs(Term,N):-
	N is 0,
	functor(Term,_,A),
	subcount(Term,A,N).

subcount(Term,0,N):-
	write("N = "),
 	write(N),
	write("  Dont listen to the rest...").

subcount(Term,Pos,N):-
	arg(Pos,Term,NewTerm),
	functor(NewTerm,F,A),
	(atom(F)->
	inc(N,X),
	NewPos is Pos-1,
	subcount(F,NewPos,X);
	NewPos is Pos-1,
	subcount(F,NewPos,N)).

% 5.3

is_ground_term(Term):-
	atom(Termn).
	
inc(X,Y):-
Y is X+1.

is_ground_term(Term):-
    Y=1,
    arg(Y,Term,X),
    nonvar(X).

% 5.4

term_member(Term1,Term2):-
    arg(X,Term2,Term1).

% 5.5 TODO


%subterm_left(Term1,Term2):-
    

%5.6 TODO

    
%reverse_left(Term1,Term2)

%5.7

%TODO

%5.8

% list1 and list2 are the same.
%list3 accepts all kinds of lists.

%5.9
% the following loop reached N=11184635 until the stack was full


longterm(N,Term):-
    writeln(N),
    N2 is N+1,
    Term2=(5|Term),
    longterm(N2,Term2).

%5.10 whats occurs check?

%TODO

%5.11

%TODO
