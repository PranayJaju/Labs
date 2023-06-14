module 	Q3(A, B, C, D, f);
    input A, B, C, D;
    output f;
    nor(d, D, D);
    nor(Ad, A, d);
    nor(Cd, C, d);
    nor(F, Ad, Cd);
    nor(f, F, F);
endmodule