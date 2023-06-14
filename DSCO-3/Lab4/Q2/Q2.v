module 	Q2(A, B, C, D, f);
    input A, B, C, D;
    output f;
    nor(d, D, D);
    nor(BD, B, D);
    nor(BC, B, C);
    nor(ACd, A, C, d);
    nor(F, BD, BC, ACd);
    nor(f, F, F);
endmodule