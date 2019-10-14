:- use_module(library(pce)).
:- use_module(library(pce_style_item)).
:- consult('drink.rules').
:- dynamic (known/5).
:- dynamic (name/1).



main:-
    ask_name(Y),
    new(D, dialog('Menu')),
    with_output_to(string(Text),format("Hello ~w! press Play to start!\n",[Y])),
    send(D, append, new(Ti,text_item(-,Text))),
    send(D, append,
    button(play, message(@prolog,go,D))),
    send(D,open).
    

go(D):-
    %undo,
    send(D,destroy),
    drink(X),
    with_output_to(string(Text),format("your Drik is ~w",[X])),
    new(Di, dialog('Finish')),
    send(Di, append,
        button(again, message(@prolog,go,Di))),
    send(Di, append,
        button(funfact, message(@prolog,funfact,Di,X))),
    send(Di, append,
        button(why, message(@prolog,why,Di,X))),
    send(Di, append, new(T,text_item(result,Text))),
    send(Di,open).

funfact(Di,X):-
    write('funfact').
    go.

why(Di,X):-
    write('funfact').


ask_name(X):-
    name(X),
    !.

ask_name(X):-
    new(D,dialog('Welcome!')),
    send(D, append, label(line1,"How to: this is a small expert system about your favorite drink!")),
    send(D, append, label(line2,"You can answer questions and it will tell you what drink was on your mind")),
    send(D, append, label(line3,"You can also add a missing drink :)")),
    send(D, append, label(name,'But before we start i would like to know your name!')),
    send(D,append,
        new(T,text_item(name,''))),   
    send(D,append,
            button(ok,message(D,return,T?selection))),
    get(D,confirm,Name),
    Name \== @nil,
    X = Name,
    asserta(name(X)),
    writeln(X),
    send(D,destroy).


ask(BEGINN,VAL,ATTR,COND):-
  known(yes, BEGINN,VAL,ATTR,COND),
  !.

ask(BEGINN,VAL,ATTR,COND):-
  known(_,BEGINN,VAL,ATTR,COND),
  !,
  fail.


ask(BEGINN,VAL,ATTR,COND):-  
        with_output_to(string(Text),format("~w your Drink ~w ~w ~w?\n",[BEGINN,VAL,ATTR,COND])),
        new(D, dialog('?')),
        send(D, append,
        new(ANSWER, menu(Text,marked))),
        send(ANSWER, append, yes),
        send(ANSWER, append, no),
        send(D, append,
             button(ok, message(D, return,
                                ANSWER?selection))),
        send(D, default_button, ok), % Ok: default button
        get(D, confirm, Answer),     % This blocks!
        send(D, destroy),
        %Answer \== no,             % canceled
        asserta(known(Answer,BEGINN,VAL,ATTR,COND)).



made_of(ATTR):-
    ask("Is","mostly made",of,ATTR).

has(ATTR,COND):-
    ask("Does",has,ATTR,COND).


tastes(COND,ATTR):-
    ask("Does",tastes,COND,ATTR).

is(ATTR):-
    ask(is,"considert a",ATTR,drink).

undo:- 
	retract(known(_._._._._)), 
	fail.

undo_name :- 
	retract(name(_)), 
	fail.

undo_name.

undo.
