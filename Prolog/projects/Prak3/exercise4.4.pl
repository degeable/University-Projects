second(X,[Y,X|List]).

swap12([X,Y|List1],[Y,X|List2]):-
    List1 = List2.

tran(eins,one).
tran(zwei,two).
tran(drei,three).
tran(vier,four).
tran(fuenf,five).
tran(sechs,six).
tran(sieben,seven).
tran(acht,eight).
tran(neun,nine). 

listtran([],X):-
    []=X.

listtran([X|List3],[Z|List4]):- 
    tran(X,Z),
    listtran(List3,List4).

twice([],X):-
    !.

twice([N|List],X):-
        [N,N|X]=Temp,
        twice(List,Temp).
    
