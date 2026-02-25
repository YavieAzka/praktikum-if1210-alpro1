misteri(I, I, []).
misteri(I, K, [I|L]) :- I < K, I1 is I + 1, misteri(I1, K, L).