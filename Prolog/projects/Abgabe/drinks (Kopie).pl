:- use_module(library(pce)).
:- use_module(library(pce_style_item)).
:- consult('drink.rules').
:- dynamic (known/5).
:- dynamic (name/1).

main:-
    ask_name(Y),
    undo_name,
    new(D, dialog('Menu')),
    with_output_to(string(Text),format("Hello ~w! press Play to start or List to see what kind of drinks are in the database!\n",[Y])),
    send(D, append, label(name,Text)),
    send(D, append,
    button(play, message(@prolog,go,D))),
    send(D, append,
    button(list, message(@prolog,list,D))),
    send(D, append,
    button(add_a_drink, message(@prolog,add_drink))),
    send(D,open).
    
assert_drink(Name,Color,Alc,Soda,Cold,Sweet,Organic,Brew,Main,Dialog):-
        send(Dialog, destroy),
        (Alc \= yes, Alc \= no,
         Soda \= yes, Soda \= no,
         Cold \= yes, Cold \= no,
         Sweet \= yes, Sweet \= no,
         Organic \= yes, Organic \= no,
         Brew \= yes, Brew \= no
        -> new(D,dialog('Falsche Eingabe!')),
           send(D,append, label(msg,"Bitte wiederholen sie den Vorgang.")),
           send(D,append,button(okay,message(D,destroy))),
           send(D,open)
        ;open('drink.rules', append, File1),
           atomic_list_concat(SplitName, ' ', Name),
           atomic_list_concat(SplitName, '_',FixedName),
           nl(File1),write(File1,'drink('),write(File1,FixedName),write(File1,'):-'),nl(File1),
           (Soda==yes
           ->tab(File1,4),write(File1,'has(soda,""),'),nl(File1)
           ;tab(File1,4),write(File1,'not(has(soda,"")),'),nl(File1)),
           tab(File1,4),write(File1,'has('),write(File1,Color),write(File1,',color),'),nl(File1),
           (Alc==yes
           ->tab(File1,4),write(File1,'has(alcohol,""),'),nl(File1)
           ;tab(File1,4),write(File1,'not(has(alcohol,"")),'),nl(File1)),
           (Cold==yes
           ->tab(File1,4),write(File1,'is(cold),'),nl(File1)
           ;tab(File1,4),write(File1,'not(is(cold)),'),nl(File1)),
           (Sweet==yes
           ->tab(File1,4),write(File1,'tastes("",sweet),'),nl(File1)
           ;tab(File1,4),write(File1,'not(tastes("",sweet)),'),nl(File1)),
           (Organic==yes
           ->tab(File1,4),write(File1,'is(organic),'),nl(File1)
           ;tab(File1,4),write(File1,'not(is(organic)),'),nl(File1)),
           (Brew==yes
           ->tab(File1,4),write(File1,'is(brew),'),nl(File1)
           ;tab(File1,4),write(File1,'not(is(brew)),'),nl(File1)),
           atomic_list_concat(SplitMain, ' ', Main),
           atomic_list_concat(SplitMain, '_',FixedMain),
           tab(File1,4),write(File1,'made_of('),write(File1,FixedMain),write(File1,'),'),nl(File1),
           tab(File1,4),write(File1,'!.'),nl(File1),
           close(File1),
           make:reload_file("drink.rules"),
           new(D,dialog('Drink hinzugefügt!')),
           send(D,append, label(msg,"Ihr Drink befindet sich nun in der Datenbank!")),
           send(D,append,button(okay,message(D,destroy))),
           send(D,open)
        ).

add_drink :-
        new(Dialog, dialog('Add your own drink!')),
        send(Dialog,append,label(title,"Please fill in the blanks. No capital letters please... \nNOTE:Name, Color and main ingridient are abitrary but the rest has to be yes and no")),
        send(Dialog, append, new(Name, text_item(name))),
        send(Dialog, append,  new(Color, text_item(color))), 
        send(Dialog, append,  new(Alcohol, text_item(alcoholic))), 
        send(Dialog, append,  new(Soda, text_item(has_soda))), 
        send(Dialog, append,  new(Cold, text_item(cold_drink))), 
        send(Dialog, append,  new(Sweet, text_item(sweet))), 
        send(Dialog, append,  new(Organic, text_item(organic))), 
        send(Dialog, append,  new(Brew, text_item(brew))), 
        send(Dialog, append,  new(Main, text_item(main_ingredient))), 
        send(Dialog, append,  button(cancel, message(Dialog, destroy))),
        send(Dialog,append,
            button(ok,message(@prolog,assert_drink,
                                            Name?selection,
                                            Color?selection,
                                            Alcohol?selection,
                                            Soda?selection,
                                            Cold?selection,           
                                            Sweet?selection,
                                            Organic?selection,
                                            Brew?selection,
                                            Main?selection,Dialog))),
        send(Dialog, open).       




show_fact(Sentence):-
    new(Di, dialog('Funfact')),
    send(Di, append, label(fact,Sentence)),
    send(Di, append, button(okay, message(Di, destroy))),
    send(Di,open).


list(_):-
    new(Di, dialog('Listing')),
    send(Di, append, label(line1,"There are the following drinks in the database:")),
    bagof(X,drink(X,_),Z),
    atomic_list_concat(Z,', ',Atoms),
    atom_string(Atoms,Text),
    send(Di, append, label(line2,Text)),
    send(Di, append, button(okay, message(Di, destroy))),
    send(Di,open).
    

    


go(D):-
    send(D,destroy),
    (drink(X)->write("sucess")
    ;write("sorry nothing found")
    ),
    (retractall(known(_,_,_,_,_))
    ->write("removed answers")
    ;write("no ansswers given")),
    %undo, %this doesnt work :( 
    with_output_to(string(Text),format("is your Drink ~w?",[X])), %das nach oben??
    new(Di, dialog('Finish')),
    send(Di, append,
        button(again, message(@prolog,go,Di))),
    send(Di, append,
        button(funfact, message(@prolog,funfact,X,Di))),
    send(Di, append,label(result,Text)),
    send(Di,open).

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
  known(yes,BEGINN,VAL,ATTR,COND),
  !.

ask(BEGINN,VAL,ATTR,COND):-
  known(no,BEGINN,VAL,ATTR,COND),
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
        asserta(known(Answer,BEGINN,VAL,ATTR,COND)).



made_of(ATTR):-
    ask("Is","mostly made",of,ATTR).

has(ATTR,COND):-
    ask("Does",has,ATTR,COND).


tastes(COND,ATTR):-
    ask("Does",tastes,COND,ATTR).

is(ATTR):-
    ask(is,"considert a",ATTR,drink).

undo_name :- 
	retract(name(_)), 
	fail.

undo_name.

