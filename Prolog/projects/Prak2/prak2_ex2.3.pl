correct_dance(stop).

correct_dance(left(X)):-
    correct_dance(X).

correct_dance(right(X)):-
    correct_dance(X).

correct_dance(forward(X)):-
    correct_dance(X).

correct_dance(backward(X)):-
    correct_dance(X).

correct_dance(leftTurn(X)):-
    correct_dance(X).

correct_dance(rightTurn(X)):-
    correct_dance(X).


symmetric_dance(stop).

symmetric_dance(right(left(X))):-
    symmetric_dance(X).

symmetric_dance(left(right(X))):-
    symmetric_dance(X).

symmetric_dance(forward(backward(X))):-
    symmetric_dance(X).

symmetric_dance(backward(forward(X))):-
    symmetric_dance(X).

symmetric_dance(leftTurn(rightTurn(X))):-
    symmetric_dance(X).

symmetric_dance(rightTurn(leftTurn(X))):-
    symmetric_dance(X).

symmetric_dance(leftTurn(leftTurn(X))):-
    symmetric_dance(X).

symmetric_dance(rightTurn(rightTurn(X))):-
    symmetric_dance(X).

%safe_dance(X,Y):-
%    correct_dance(left(X),
%    correct_dance(left(Y),
