state(A,B,C).

empty([]).

valid_calc(X,[]).
valid_calc([]).
valid_calc([_]).


valid_calc([One,Two|Tail]):-
    One < Two,
    valid_calc(Two,Tail).


valid_calc(X,[Y|Tail]):-
    X < Y,
    valid_calc(Tail).


valid_state(state(A,B,C)):-
    valid_calc(A),
    valid_calc(B),
    valid_calc(C).
    
	
final_state(state(A,B,C)):-
	valid_state(state(A,B,C)),
    empty(A),
    empty(B).
    
	
node(state(A,B,C), F, G, H, Path).

final_node(node(state(A,B,C), F, G, H, Path)):-
    final_state(state(A,B,C)).

% arg(?Arg, +Term, ?Value) -> ?Arg=what position of arg u want to have, +Term=the term, ?Value=output

move(NodeBefore,NodeAfter).

moveA2B(NodeBefore,NodeAfter):-
    arg(1,NodeBefore,StateBefore), 
    arg(2,NodeBefore,Fb),
    arg(3,NodeBefore,Gb),
    arg(4,NodeBefore,Hb),
    arg(5,NodeBefore,PathBefore),
    valid_state(StateBefore),
    StateBefore=..StateBeforeList,
    StateBeforeList = [_,[TopA|RodA],RodB,RodC|_],
    Ga=Gb+1,
    Ha=0,
    Fa=Ga+Ha,
    append(PathBefore,[ab],RightPath),
    NodeAfter = node(state(RodA,[TopA|RodB],RodC),Fa, Ga, Ha, RightPath),
    arg(1,NodeAfter,StateAfter),
    valid_state(StateAfter). 

moveA2C(NodeBefore,NodeAfter):-
    arg(1,NodeBefore,StateBefore), 
    arg(2,NodeBefore,Fb),
    arg(3,NodeBefore,Gb),
    arg(4,NodeBefore,Hb),
    arg(5,NodeBefore,PathBefore),
    valid_state(StateBefore),
    StateBefore=..StateBeforeList,
    StateBeforeList = [_,[TopA|RodA],RodB,RodC|_],
    Ga=Gb+1,
    Ha=0,
    Fa=Ga+Ha,
    append(PathBefore,[ac],RightPath),
    NodeAfter = node(state(RodA,RodB,[TopA|RodC]),Fa, Ga, Ha, RightPath),
    arg(1,NodeAfter,StateAfter),
    valid_state(StateAfter). 

moveB2A(NodeBefore,NodeAfter):-
    arg(1,NodeBefore,StateBefore), 
    arg(2,NodeBefore,Fb),
    arg(3,NodeBefore,Gb),
    arg(4,NodeBefore,Hb),
    arg(5,NodeBefore,PathBefore),
    valid_state(StateBefore),
    StateBefore=..StateBeforeList,
    StateBeforeList = [_,RodA,[TopB|RodB],RodC|_],
    Ga=Gb+1,
    Ha=0,
    Fa=Ga+Ha,
    append(PathBefore,[ba],RightPath),
    NodeAfter = node(state([TopB|RodA],RodB,RodC),Fa, Ga, Ha, RightPath),
    arg(1,NodeAfter,StateAfter),
    valid_state(StateAfter). 


moveB2C(NodeBefore,NodeAfter):-
    arg(1,NodeBefore,StateBefore), 
    arg(2,NodeBefore,Fb),
    arg(3,NodeBefore,Gb),
    arg(4,NodeBefore,Hb),
    arg(5,NodeBefore,PathBefore),
    valid_state(StateBefore),
    StateBefore=..StateBeforeList,
    StateBeforeList = [_,RodA,[TopB|RodB],RodC|_],
    Ga=Gb+1,
    Ha=0,
    Fa=Ga+Ha,
    append(PathBefore,[bc],RightPath),
    NodeAfter = node(state(RodA,RodB,[TopB|RodC]),Fa, Ga, Ha, RightPath),
    arg(1,NodeAfter,StateAfter),
    valid_state(StateAfter). 

moveC2A(NodeBefore,NodeAfter):-
    arg(1,NodeBefore,StateBefore), 
    arg(2,NodeBefore,Fb),
    arg(3,NodeBefore,Gb),
    arg(4,NodeBefore,Hb),
    arg(5,NodeBefore,PathBefore),
    valid_state(StateBefore),
    StateBefore=..StateBeforeList,
    StateBeforeList = [_,RodA,RodB,[TopC|RodC]|_],
    Ga=Gb+1,
    Ha=0,
    Fa=Ga+Ha,
    append(PathBefore,[ca],RightPath),
    NodeAfter = node(state([TopC|RodA],RodB,RodC),Fa, Ga, Ha, RightPath),
    arg(1,NodeAfter,StateAfter),
    valid_state(StateAfter). 

moveC2B(NodeBefore,NodeAfter):-
    arg(1,NodeBefore,StateBefore), 
    arg(2,NodeBefore,Fb),
    arg(3,NodeBefore,Gb),
    arg(4,NodeBefore,Hb),
    arg(5,NodeBefore,PathBefore),
    valid_state(StateBefore),
    StateBefore=..StateBeforeList,
    StateBeforeList = [_,RodA,RodB,[TopC|RodC]|_],
    Ga=Gb+1,
    Ha=0,
    Fa=Ga+Ha,
    append(PathBefore,[cb],RightPath),
    NodeAfter = node(state(RodA,[TopC|RodB],RodC),Fa, Ga, Ha, RightPath),
    arg(1,NodeAfter,StateAfter),
    valid_state(StateAfter).



last([Elem], Elem).
last([_|Tail], Elem) :- last(Tail, Elem).

successor(Node, ListOfSuccessors):-
   (final_node(Node)
    -> writeln(Node)
  ;  ((moveA2B(Node,X), arg(5,Node,PathBefore),last(PathBefore,Path),not(Path = "ba")) ->
    	writeln(X),successor(X,NewSucc)
    ;   ((moveA2C(Node,X), arg(5,Node,PathBefore),last(PathBefore,Path),not(Path = "ca")) ->
         	writeln(X),successor(X,NewSucc)
        ;  ((moveB2C(Node,X), arg(5,Node,PathBefore),last(PathBefore,Path),not(Path="cb")) ->
                writeln(X),successor(X,NewSucc)
            ;  ((moveB2A(Node,X), arg(5,Node,PathBefore),last(PathBefore,Path),not(Path= "ab")) ->
                    writeln(X),successor(X,NewSucc)
                ;  ((moveC2A(Node,X), arg(5,Node,PathBefore),last(PathBefore,Path),not(Path= "ac")) ->
                        writeln(X),successor(X,NewSucc)
                    ;  ((moveC2B(Node,X), arg(5,Node,PathBefore),last(PathBefore,Path),not(Path= "bc")) ->
                           writeln(X),successor(X,NewSucc)
                        )
                    )
                )
            )
        )
    )
 ).

successor_nodes(Node, ListOfSuccessors):-
    (moveA2B(Node,X)->
    ACC=[X]
    ;ACC=[]
    ),
    (moveA2C(Node,X1)->
    ACC1=[X1|ACC]
    ;ACC1=ACC
    ),
    (moveB2A(Node,X2)->
    ACC2=[X2|ACC1]
    ;ACC2=ACC1
    ),
    (moveB2C(Node,X3)->
    ACC3=[X3|ACC2]
    ;ACC3=ACC2
    ),
    (moveC2A(Node,X4)->
    [X4|ACC3]=ACC4
    ;ACC4=ACC3
    ),
    (moveC2B(Node,X5)->
    [X5|ACC4]=ACC5
    ;ACC5=ACC4
    ),
    ListOfSuccessors=ACC5.


search(Fringe,Path):-
    Fringe=[FHead|Tail],
    (final_node(FHead)
    -> arg(5,FHead,Path)
    ;successor_nodes(FHead,SuccNodes),
     append(Tail,SuccNodes,NewFringe),
     sort(2, @=<, NewFringe,SortedFringe),
     search(SortedFringe,Path)
    ).











    
