module q3i(x1, x2, x3, f);
    input x1, x2, x3;
    output f;
    nor(X1, x1, x1);
    nor(X3, x3, x3);
    nor(X1X2, x1, x2);
    nor(X1X3, X1, X3);
    nor(f, X1X3, X1X2);
endmodule