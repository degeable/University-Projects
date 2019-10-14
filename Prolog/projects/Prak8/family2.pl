% 1 father Fact 2
father(anton,john).
% 2 father Fact 2
father(paul,mary).
% 3 father Fact 2
father(john,peter).
% 4 father Fact 2
father(john,elisabeth).
% 5 father Fact 2
father(peter,agneta).
% 6 mother Fact 2
mother(mary,peter).
% 7 mother Fact 2
mother(mary,elisabeth).
% 8 mother Fact 2
mother(elisabeth,agneta).
% 9 mother Fact 2
mother(elisabeth,sarah).
% 10  Rule 2
parent(_2434,_2436):-father(_2434,_2436).
% 11  Rule 2
parent(_2464,_2466):-mother(_2464,_2466).
% 12  Rule 2
ancestor(_2494,_2496):-parent(_2494,_2496).
% 13  Rule 2
ancestor(_2524,_2526):-parent(_2524,_2532),ancestor(_2532,_2526).
% 14 end_of_file Fact 0
end_of_file.
