has(ATTR,COND):-
    ask(does,has,ATTR,COND).

has(ATTR):-
    ask(does,has,ATTR,"").  

tastes(COND,ATTR):-
    ask(tastes,COND,ATTR).

is(ATTR):-
    ask_is(ATTR).

ask_is(ATTR):-
    write("Is your Drink considert a "),
    write(ATTR),tab(1),
    write("Drink?").
    

ask(BEGINN,VAL,ATTR,COND):-
    write(BEGINN),tab(1),
    write("your Drink "),
    write(VAL),tab(1),
    write(ATTR),tab(1),
    write(COND),tab(1).  




%https://stackoverflow.com/questions/23411139/prolog-unexpected-end-of-file
%http://www.swi-prolog.org/pldoc/man?predicate=read_string/5
%http://www.swi-prolog.org/pldoc/doc_for?object=split_string/4

input:-
   read(yes).

open_drinks(Path):-
    open(Path,read,Str),
    read_drinks(Str,List),
    close(Str),
    load_drinks(List),
    !.

read_drinks(Stream,[]):-
    at_end_of_stream(Stream).

read_drinks(Stream,[H|T]):-
    \+ at_end_of_stream(Stream),
    read_string(Stream, "\n", "\r", End, H),
    read_drinks(Stream,T).

load_drinks([],0).

load_drinks([Name | Tail]):-
    write("drink"),write("("),write(Name),write("):-"),nl,
    tab(4),
    %load_attr(Tail),
    
    write(Func),write("("),
    %write(Rest),
    (Tail == "and" 
    -> write("),"),nl
    ;write(","),write(Tail),write("),"),nl).
    %load_attr(Rest).

load_attr([]).
    
