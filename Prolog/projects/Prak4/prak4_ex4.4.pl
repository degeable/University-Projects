psum([],0).

psum([H | List], P):-
    psum( List, SubP),
    P is H + SubP.

psum([_ |List],P):-
    psum(List,P).
