:- use_module(library(pce)).
:- use_module(library(pce_style_item)).
:- consult('drink.rules').
:- dynamic (known/5).
:- dynamic (name/1).

/*main function to retract the name if you restart the program. Menue is called afterwards*/
main:-
    undo_name,
    menue.

/*menue ask for the name if it hasnt a name yet. 4 Buttons for play,listing, adding an own drink and exit the programm. */
menue:-
    ask_name(Y),
    new(D, dialog('Menu')),
    %with_output_to for creating the label string
    with_output_to(string(Text),format("Hello ~w! press Play to start or List to see what kind of drinks are in the database!\nTry to add your own drink if its missing",[Y])),
    send(D, append, label(name,Text)),
    send(D, append,
    button(play, message(@prolog,go))),
    send(D, append,
    button(list, message(@prolog,list,D))),
    send(D, append,
    button(add_a_drink, message(@prolog,add_drink))),
    send(D, append,
    button(exit, message(D,destroy))),
    send(D,open).

/*another menue with a parameter to destroy an old windown when returning to menue*/  
menue(Di):-
        send(Di,destroy),
        menue.

/*writes a new drink in the drink.rules file. Userinput gets checked, capital letters will be lowered and whitespaces will be repaced with "_"*/
assert_drink(Name,Color,Alc,Sparkling,Cold,Sweet,Organic,Brew,Main,Dialog):-
        send(Dialog, destroy),
        (Alc \= yes, Alc \= no,
         Sparkling \= yes, Sparkling \= no,
         Cold \= yes, Cold \= no,
         Sweet \= yes, Sweet \= no,
         Organic \= yes, Organic \= no,
         Brew \= yes, Brew \= no
        -> new(D,dialog('Wrong input!')),
           send(D,append, label(msg,"Please repeat the process...")),
           send(D,append,button(okay,message(D,destroy))),
           send(D,open)
        ;open('drink.rules', append, File1),
           atomic_list_concat(SplitName, ' ', Name),
           atomic_list_concat(SplitName, '_',FixedName),
           atomic_list_concat(SplitMain, ' ', Main),
           atomic_list_concat(SplitMain, '_',FixedMain),
           atomic_list_concat(SplitColor, ' ', Color),
           atomic_list_concat(SplitColor, '_',FixedColor),
           downcase_atom(FixedMain,LowercaseMain),
           downcase_atom(FixedName,LowercaseName),
           downcase_atom(FixedColor,LowercaseColor),
           nl(File1),write(File1,'drink('),write(File1,LowercaseName),write(File1,'):-'),nl(File1),
           (Sparkling==yes
           ->tab(File1,4),write(File1,'is(sparkling),'),nl(File1)
           ;tab(File1,4),write(File1,'not(is(sparkling)),'),nl(File1)),
           tab(File1,4),write(File1,'has('),write(File1,LowercaseColor),write(File1,',color),'),nl(File1),
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
           ->tab(File1,4),write(File1,'is(brewage),'),nl(File1)
           ;tab(File1,4),write(File1,'not(is(brewage)),'),nl(File1)),
           tab(File1,4),write(File1,'made_of('),write(File1,LowercaseMain),write(File1,'),'),nl(File1),
           tab(File1,4),write(File1,'!.'),nl(File1),
           close(File1),
           make:reload_file("drink.rules"),
           new(D,dialog('Drink added!')),
           send(D,append, label(msg,"your drink is now in the database!")),
           send(D,append,button(okay,message(D,destroy))),
           send(D,open)
        ).
/* dialog for userinput for adding a new drink. when pressing ok button, assert_drink/10 is called */
add_drink :-
        new(Dialog, dialog('Add your own drink!')),
        send(Dialog,append,label(title,"Please fill in the blanks. \nNOTE:Name, color and main ingridient are abitrary but the rest has to be yes and no")),
        send(Dialog, append, new(Name, text_item(name))),
        send(Dialog, append,  new(Color, text_item(color))), 
        send(Dialog, append,  new(Alcohol, text_item(alcoholic))), 
        send(Dialog, append,  new(Sparkling, text_item(is_Sparkling))), 
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
                                            Sparkling?selection,
                                            Cold?selection,           
                                            Sweet?selection,
                                            Organic?selection,
                                            Brew?selection,
                                            Main?selection,Dialog))),
        send(Dialog, open).       



/* displays a small dialog with the funfact string */
show_fact(Sentence):-
    new(Di, dialog('Funfact')),
    send(Di, append, label(fact,Sentence)),
    send(Di, append, button(okay, message(Di,destroy))),
    send(Di,open).

/* searches for the standart drink names, puts them into a string and displays them on a dialog*/
list(_):-
    new(Di, dialog('Listing')),
    send(Di, append, label(line1,"There are the following drinks in the database:")),
    bagof(X,drink(X,_),Z),
    atomic_list_concat(Z,', ',Atoms),
    atom_string(Atoms,Text),
    send(Di, append, label(line2,Text)),
    send(Di, append, button(okay, message(Di, destroy))),
    send(Di,open).

/* prints all answeres questuons but in list form... there was no time left to correct this one to natural language.. */
 why(Drink):-
    bagof([ANSWER,BEGINN,ATTR,COND,VAL],known(ANSWER,BEGINN,ATTR,COND,VAL),L),
    with_output_to(string(Text),format("~w",[L])),
    with_output_to(string(Intro),format("Your Drink is ~w because:",[Drink])),
    new(Di,dialog('Why?')),
    send(Di,append,label(name,Intro)),
    send(Di,append,label(name,Text)),
    send(Di, append,
    button(okay, message(Di,destroy))),
    send(Di,open).

    
/* tries to unificate X with a drink and calls the drink(X) from drink.rules file. When nothing fits it sayy no drink found. After it finishes
 * the answeres get getracted from the database. At the finish Dialog are 4 buttons for play again, show funfact, show why and return to menue (consider that return home doenst retract answers)
 */
go:-
    (drink(X)->atomic_list_concat(Split,'_',X),atomic_list_concat(Split,' ',FixedX),with_output_to(string(Text),format("your Drink is ~w",[FixedX]))
    ;go
    ),
    new(Di, dialog('Finish')),
    send(Di, append,
        button(again, message(@prolog,again,Di))),
    send(Di, append,
        button(funfact, message(@prolog,funfact,FixedX,Di))),
    send(Di, append,
        button(why, message(@prolog,why,X))),
    send(Di, append,
        button(menue, message(Di,destroy))),
    send(Di, append,label(result,Text)),
    send(Di,open).

again(Di):-
    send(Di,destroy),
(retractall(known(_,_,_,_,_))
    ->write("removed answers")
    ;write("no ansswers given")),
    go.

/* looks for a name in the database */
ask_name(X):-
    name(X),
    !.

/* when no names found the welcome dialog is shown. the userinput will be asserted into the database */
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
    send(D,destroy).

/* ask will look if theres already an answer in the database*/
ask(BEGINN,VAL,ATTR,COND):-
  known(yes,BEGINN,VAL,ATTR,COND),
  !,
  true.

ask(BEGINN,VAL,ATTR,COND):-
  known(no,BEGINN,VAL,ATTR,COND),
  !,
  fail.

/* for asking questions. simple dialog with a small menue for yes and no and an ok button. The answer will be asserted into the database*/
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


/* the drink(X) from drink.rules call those functions to promt the user for the answer*/
made_of(ATTR):-
    ask("Is","mostly made",of,ATTR).

has(ATTR,COND):-
    ask("Does",has,ATTR,COND).

color(COLOR):-
    ask("Does",has,COLOR,color).


tastes(COND,ATTR):-
    ask("Does",tastes,COND,ATTR).

is(ATTR):-
    ask(is,"considert a",ATTR,drink).

/*to retract the name from the database*/
undo_name :- 
	retract(name(_)), 
	fail.

undo_name.

